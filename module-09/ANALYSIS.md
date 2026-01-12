# Module 09: STL - Deep Analysis

## Table of Contents
1. [Module Overview](#module-overview)
2. [Container Strategy](#container-strategy)
3. [Exercise 00: Bitcoin Exchange](#exercise-00-bitcoin-exchange)
4. [Exercise 01: RPN Calculator](#exercise-01-rpn-calculator)
5. [Exercise 02: PmergeMe (Ford-Johnson)](#exercise-02-pmergeme)
6. [Key Concepts Summary](#key-concepts-summary)

---

## Module Overview

```mermaid
mindmap
  root((Module 09: STL))
    Containers Used
      std::map
        Associative Container
        Key-Value Pairs
        Ordered by Key
        O(log n) lookup
      std::stack
        Container Adapter
        LIFO Structure
        push/pop/top
        O(1) operations
      std::vector
        Sequence Container
        Dynamic Array
        Random Access
        O(1) access
      std::deque
        Sequence Container
        Double-ended Queue
        Fast front/back
        O(1) at ends
    Core Concepts
      Iterator Patterns
      Algorithm Complexity
      Container Selection
      Memory Management
    Exercises
      ex00: Bitcoin Exchange
      ex01: RPN Calculator
      ex02: Merge-Insert Sort
```

---

## Container Strategy

The module requires using **different containers for each exercise**. Here's the rationale:

```mermaid
flowchart TB
    subgraph "Container Selection Strategy"
        A[Exercise Requirements] --> B{Need Key-Value Lookup?}
        B -->|Yes| C[std::map]
        B -->|No| D{Need LIFO Access?}
        D -->|Yes| E[std::stack]
        D -->|No| F{Need Random Access + Sorting?}
        F -->|Yes| G[std::vector / std::deque]
    end

    subgraph "Final Allocation"
        C --> H[ex00: Bitcoin Exchange]
        E --> I[ex01: RPN Calculator]
        G --> J[ex02: PmergeMe]
    end

    style C fill:#e1f5fe
    style E fill:#fff3e0
    style G fill:#e8f5e9
```

### Why These Containers?

| Exercise | Container | Reason |
|----------|-----------|--------|
| ex00 | `std::map` | Need date→price mapping with efficient lookup by date. `lower_bound()` finds nearest lower date in O(log n) |
| ex01 | `std::stack` | RPN evaluation naturally uses LIFO - push operands, pop for operations |
| ex02 | `std::vector` + `std::deque` | Need random access for binary search insertion. Compare performance between contiguous (vector) and segmented (deque) memory |

---

## Exercise 00: Bitcoin Exchange

### Architecture

```mermaid
classDiagram
    class BitcoinExchange {
        -std::map~string, double~ _database
        +BitcoinExchange()
        +BitcoinExchange(const BitcoinExchange&)
        +operator=(const BitcoinExchange&)
        +~BitcoinExchange()
        +loadDatabase(string filename) bool
        +processInputFile(string filename) void
        -isValidDate(string date) bool
        -isValidValue(string value, double& result) bool
        -getExchangeRate(string date) double
        -trim(string str) string
    }

    class main {
        +main(int argc, char** argv) int
    }

    main --> BitcoinExchange : uses
```

### Data Flow

```mermaid
flowchart TD
    subgraph "Initialization"
        A[Program Start] --> B[Load data.csv]
        B --> C{File Exists?}
        C -->|No| D[Error: could not open database]
        C -->|Yes| E[Parse CSV lines]
        E --> F[Store in std::map<br/>key=date, value=rate]
    end

    subgraph "Processing Input"
        F --> G[Open input file]
        G --> H{Read Line}
        H -->|EOF| I[End]
        H -->|Line| J{Valid Format?<br/>date \| value}
        J -->|No| K[Error: bad input]
        K --> H
        J -->|Yes| L{Valid Date?<br/>YYYY-MM-DD}
        L -->|No| M[Error: bad input]
        M --> H
        L -->|Yes| N{Valid Value?<br/>0 ≤ v ≤ 1000}
        N -->|< 0| O[Error: not positive]
        N -->|> 1000| P[Error: too large]
        N -->|Valid| Q[Get Exchange Rate]
        O --> H
        P --> H
    end

    subgraph "Rate Lookup"
        Q --> R{Exact Date<br/>in Database?}
        R -->|Yes| S[Use exact rate]
        R -->|No| T[Find lower_bound]
        T --> U{Date before<br/>first entry?}
        U -->|Yes| V[Error: date too early]
        U -->|No| W[Use previous date's rate]
        S --> X[Calculate: value × rate]
        W --> X
        X --> Y[Output Result]
        Y --> H
        V --> H
    end

    style F fill:#e1f5fe
    style Q fill:#fff9c4
```

### std::map Operations Explained

```mermaid
flowchart LR
    subgraph "std::map Internal Structure (Red-Black Tree)"
        ROOT[2012-01-11<br/>7.1] --> L1[2011-01-09<br/>0.32]
        ROOT --> R1[2012-03-01<br/>5.0]
        L1 --> L2[2011-01-03<br/>0.3]
        L1 --> R2[2011-06-01<br/>15.0]
    end

    subgraph "Key Operations"
        OP1["find('2011-01-03')<br/>→ returns iterator to exact match"]
        OP2["upper_bound('2011-01-05')<br/>→ returns iterator to 2011-01-09"]
        OP3["--iterator<br/>→ moves to 2011-01-03<br/>(nearest LOWER date)"]
    end
```

### Date Validation Logic

```mermaid
flowchart TD
    A[Input Date String] --> B{Length == 10?}
    B -->|No| FAIL[Invalid]
    B -->|Yes| C{Format YYYY-MM-DD?}
    C -->|No| FAIL
    C -->|Yes| D[Extract Year, Month, Day]
    D --> E{Month 1-12?}
    E -->|No| FAIL
    E -->|Yes| F{Day valid for month?}
    F -->|No| FAIL
    F -->|Yes| G{Leap year check<br/>for February}
    G --> H[Valid Date]

    style H fill:#c8e6c9
    style FAIL fill:#ffcdd2
```

---

## Exercise 01: RPN Calculator

### Architecture

```mermaid
classDiagram
    class RPN {
        -std::stack~int~ _stack
        +RPN()
        +RPN(const RPN&)
        +operator=(const RPN&)
        +~RPN()
        +evaluate(string expr, int& result) bool
        -isOperator(char c) bool
        -isDigit(char c) bool
        -performOperation(char op) bool
    }

    class main {
        +main(int argc, char** argv) int
    }

    main --> RPN : uses
```

### RPN Evaluation Algorithm

```mermaid
flowchart TD
    A[Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"] --> B[Initialize Empty Stack]
    B --> C[Read Next Token]
    C --> D{Token Type?}

    D -->|Digit| E[Push to Stack]
    E --> C

    D -->|Operator| F[Pop Two Operands]
    F --> G{Stack has ≥ 2?}
    G -->|No| H[Error: Invalid Expression]
    G -->|Yes| I[Perform Operation]
    I --> J[Push Result]
    J --> C

    D -->|Space| C

    D -->|End of Input| K{Stack Size == 1?}
    K -->|No| H
    K -->|Yes| L[Return Top as Result]

    D -->|Other| H

    style L fill:#c8e6c9
    style H fill:#ffcdd2
```

### Stack Visualization: "8 9 * 9 -"

```mermaid
flowchart LR
    subgraph "Step 1: Push 8"
        S1[" "]
        S1_8[8]
        S1 --> S1_8
    end

    subgraph "Step 2: Push 9"
        S2_8[8]
        S2_9[9]
        S2_8 --> S2_9
    end

    subgraph "Step 3: Multiply *"
        S3_POP["Pop 9, Pop 8<br/>8 × 9 = 72"]
        S3_72[72]
        S3_POP --> S3_72
    end

    subgraph "Step 4: Push 9"
        S4_72[72]
        S4_9[9]
        S4_72 --> S4_9
    end

    subgraph "Step 5: Subtract -"
        S5_POP["Pop 9, Pop 72<br/>72 - 9 = 63"]
        S5_63[63]
        S5_POP --> S5_63
    end
```

### Why std::stack?

```mermaid
flowchart TB
    subgraph "std::stack Properties"
        A[LIFO: Last In First Out]
        B[O(1) push/pop/top]
        C[No iteration needed]
        D[Perfect for expression evaluation]
    end

    subgraph "RPN Requirements"
        E[Push operands as encountered]
        F[Pop two operands for each operator]
        G[Push result back]
        H[Final result is last remaining element]
    end

    A -.-> E
    B -.-> F
    B -.-> G
    C -.-> H
```

---

## Exercise 02: PmergeMe

### Architecture

```mermaid
classDiagram
    class PmergeMe {
        -std::vector~int~ _vecOriginal
        -std::vector~int~ _vec
        -std::deque~int~ _deq
        -double _vecTime
        -double _deqTime
        +PmergeMe()
        +PmergeMe(const PmergeMe&)
        +operator=(const PmergeMe&)
        +~PmergeMe()
        +parseInput(int argc, char** argv) bool
        +sort() void
        +displayBefore() void
        +displayAfter() void
        +displayTimes() void
        +getSize() size_t
        -fordJohnsonVector(vector& arr) void
        -fordJohnsonDeque(deque& arr) void
        -generateJacobsthalSequence(size_t n) vector
        -generateInsertionOrder(size_t pendSize) vector
        -binarySearchInsert(Container& sorted, int value, iterator end) iterator
    }
```

### Ford-Johnson Algorithm Overview

```mermaid
flowchart TD
    subgraph "Phase 1: Pairing"
        A[Input: 3 5 9 7 4] --> B[Create pairs]
        B --> C["(5,3) (9,7)"]
        C --> D[Straggler: 4]
    end

    subgraph "Phase 2: Recursive Sort"
        C --> E[Extract larger elements: 5, 9]
        E --> F[Recursively sort: 5, 9]
        F --> G[Sorted main chain: 5, 9]
    end

    subgraph "Phase 3: Build Initial Chain"
        G --> H[Smaller element of first pair<br/>goes first: 3]
        H --> I[Initial chain: 3, 5, 9]
        D --> I
    end

    subgraph "Phase 4: Insert Remaining"
        I --> J[Insert 7 using binary search]
        J --> K[Chain: 3, 5, 7, 9]
        K --> L[Insert straggler 4]
        L --> M[Final: 3, 4, 5, 7, 9]
    end

    style M fill:#c8e6c9
```

### Ford-Johnson Detailed Flow

```mermaid
flowchart TD
    START[Input Array] --> CHECK{Size ≤ 1?}
    CHECK -->|Yes| DONE[Return as-is]
    CHECK -->|No| ODD{Odd length?}

    ODD -->|Yes| SAVE[Save straggler<br/>Remove from array]
    ODD -->|No| PAIR[Continue]
    SAVE --> PAIR

    PAIR --> CREATE[Create pairs<br/>Larger element first in each pair]
    CREATE --> EXTRACT[Extract all larger elements<br/>= Main Chain candidates]
    EXTRACT --> RECURSE[Recursively sort<br/>main chain]

    RECURSE --> REORDER[Reorder pairs to match<br/>sorted main chain]
    REORDER --> INIT[Initialize sorted array:<br/>1. First smaller element<br/>2. All main chain elements]

    INIT --> JACOB[Generate Jacobsthal<br/>insertion order]
    JACOB --> INSERT[Insert remaining smaller<br/>elements via binary search]

    INSERT --> STRAG{Had straggler?}
    STRAG -->|Yes| ADDSTRAG[Insert straggler<br/>via binary search]
    STRAG -->|No| DONE2[Done]
    ADDSTRAG --> DONE2

    style DONE fill:#c8e6c9
    style DONE2 fill:#c8e6c9
```

### Jacobsthal Numbers & Insertion Order

```mermaid
flowchart LR
    subgraph "Jacobsthal Sequence"
        J["J(n) = J(n-1) + 2×J(n-2)"]
        SEQ["0, 1, 1, 3, 5, 11, 21, 43, 85..."]
    end

    subgraph "Insertion Order for 6 elements"
        ORDER["b₁, b₃, b₂, b₅, b₄, b₆"]
        EXPLAIN["Insert in groups:<br/>Group 1: b₁<br/>Group 2: b₃, b₂<br/>Group 3: b₅, b₄<br/>Remaining: b₆"]
    end

    subgraph "Why This Order?"
        WHY["Minimizes comparisons!<br/>Each insertion searches<br/>in optimal-sized range"]
    end
```

### Binary Search Insertion

```mermaid
flowchart TD
    subgraph "Insert 7 into [3, 5, 9]"
        A[Sorted: 3, 5, 9] --> B[Value to insert: 7]
        B --> C[Binary Search]
        C --> D["left=0, right=3<br/>mid=1, arr[1]=5<br/>5 < 7 → left=2"]
        D --> E["left=2, right=3<br/>mid=2, arr[2]=9<br/>9 ≥ 7 → right=2"]
        E --> F["left=2, right=2<br/>Insert at position 2"]
        F --> G[Result: 3, 5, 7, 9]
    end

    style G fill:#c8e6c9
```

### Vector vs Deque Performance

```mermaid
flowchart TB
    subgraph "std::vector"
        V1[Contiguous Memory]
        V2[Cache-Friendly]
        V3[O(n) insertion in middle]
        V4[Fast random access]
        V1 --> V5["Better for:<br/>- Iteration<br/>- Binary search<br/>- Small to medium data"]
    end

    subgraph "std::deque"
        D1[Segmented Memory]
        D2[Less cache-friendly]
        D3[O(n) insertion in middle]
        D4[O(1) front/back insertion]
        D1 --> D5["Better for:<br/>- Frequent front insertion<br/>- Very large data<br/>- No reallocation"]
    end

    subgraph "For Ford-Johnson"
        RESULT["Vector typically faster<br/>due to cache locality<br/>during binary search"]
    end

    V5 --> RESULT
    D5 --> RESULT
```

### Complete Example: Sorting [3, 5, 9, 7, 4]

```mermaid
flowchart TD
    subgraph "Level 0"
        L0["[3, 5, 9, 7, 4]"]
    end

    subgraph "Pairing"
        L0 --> P1["Pairs: (5,3), (9,7)"]
        L0 --> P2["Straggler: 4"]
    end

    subgraph "Recursion on [5, 9]"
        P1 --> R1["[5, 9]"]
        R1 --> R2["Pairs: (9,5)"]
        R2 --> R3["Recurse on [9]"]
        R3 --> R4["[9] (base case)"]
        R4 --> R5["Build: [5, 9]"]
    end

    subgraph "Build Main Result"
        R5 --> B1["Pairs after sorting:<br/>(5,3), (9,7)"]
        B1 --> B2["Pend: [3, 7]"]
        B2 --> B3["Init sorted: [3, 5, 9]<br/>(first pend + main chain)"]
        B3 --> B4["Insert 7: [3, 5, 7, 9]"]
        B4 --> B5["Insert straggler 4:<br/>[3, 4, 5, 7, 9]"]
    end

    style B5 fill:#c8e6c9
```

---

## Key Concepts Summary

### STL Container Hierarchy

```mermaid
flowchart TB
    subgraph "Sequence Containers"
        VECTOR[std::vector<br/>Dynamic array]
        DEQUE[std::deque<br/>Double-ended queue]
        LIST[std::list<br/>Doubly-linked list]
    end

    subgraph "Associative Containers"
        SET[std::set<br/>Unique keys]
        MAP[std::map<br/>Key-value pairs]
        MULTISET[std::multiset]
        MULTIMAP[std::multimap]
    end

    subgraph "Container Adapters"
        STACK[std::stack<br/>LIFO adapter]
        QUEUE[std::queue<br/>FIFO adapter]
        PQUEUE[std::priority_queue]
    end

    subgraph "Used in Module 09"
        USED_MAP[std::map ✓]
        USED_STACK[std::stack ✓]
        USED_VECTOR[std::vector ✓]
        USED_DEQUE[std::deque ✓]
    end

    MAP -.-> USED_MAP
    STACK -.-> USED_STACK
    VECTOR -.-> USED_VECTOR
    DEQUE -.-> USED_DEQUE

    style USED_MAP fill:#c8e6c9
    style USED_STACK fill:#c8e6c9
    style USED_VECTOR fill:#c8e6c9
    style USED_DEQUE fill:#c8e6c9
```

### Complexity Comparison

```mermaid
flowchart LR
    subgraph "Operation Complexities"
        subgraph "std::map"
            M1["Insert: O(log n)"]
            M2["Find: O(log n)"]
            M3["lower_bound: O(log n)"]
        end

        subgraph "std::stack"
            S1["Push: O(1)"]
            S2["Pop: O(1)"]
            S3["Top: O(1)"]
        end

        subgraph "std::vector"
            V1["Access: O(1)"]
            V2["Insert mid: O(n)"]
            V3["Push back: O(1) amortized"]
        end

        subgraph "std::deque"
            D1["Access: O(1)"]
            D2["Insert mid: O(n)"]
            D3["Push front/back: O(1)"]
        end
    end
```

### Orthodox Canonical Form

```mermaid
classDiagram
    class CanonicalClass {
        +CanonicalClass() default constructor
        +CanonicalClass(const CanonicalClass&) copy constructor
        +operator=(const CanonicalClass&) copy assignment
        +~CanonicalClass() destructor
    }

    note for CanonicalClass "All classes in Module 09\nmust follow this form"
```

---

## Memory Layout Visualization

### std::map (Red-Black Tree)

```
                    [2012-01-11: 7.1]
                   /                 \
        [2011-06-01: 15.0]    [2013-01-01: 13.5]
        /            \
[2011-01-03: 0.3]  [2011-09-01: 5.0]

- Balanced binary search tree
- Each node: key + value + color + pointers
- O(log n) guaranteed for all operations
```

### std::vector vs std::deque

```
std::vector:
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 3 │ 5 │ 9 │ 7 │ 4 │   │   │   │  ← Contiguous memory
└───┴───┴───┴───┴───┴───┴───┴───┘
  ↑                   ↑       ↑
 begin               size  capacity


std::deque:
┌─────────┐   ┌─────────┐   ┌─────────┐
│ Block 0 │ → │ Block 1 │ → │ Block 2 │  ← Segmented memory
│ [3,5,9] │   │ [7,4,_] │   │ [_,_,_] │
└─────────┘   └─────────┘   └─────────┘
      ↑
   Central map of pointers
```

---

## Testing Checklist

### ex00: Bitcoin Exchange
- [ ] Empty file handling
- [ ] Invalid date formats (2001-42-42)
- [ ] Negative values
- [ ] Values > 1000
- [ ] Date before database start
- [ ] Missing pipe separator
- [ ] Correct lower-bound date lookup

### ex01: RPN
- [ ] Basic operations: `8 9 * 9 - 9 - 9 - 4 - 1 +` → 42
- [ ] Division: `7 7 * 7 -` → 42
- [ ] Complex: `1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /` → 15
- [ ] Parentheses rejection: `(1 + 1)` → Error
- [ ] Division by zero handling
- [ ] Invalid tokens

### ex02: PmergeMe
- [ ] Small input: `3 5 9 7 4` → `3 4 5 7 9`
- [ ] Negative numbers → Error
- [ ] Large input (3000 elements)
- [ ] Timing displayed correctly
- [ ] Both containers produce same result

---

## Further Reading

1. **Ford-Johnson Algorithm**: "The Art of Computer Programming, Vol. 3" by Donald Knuth, Section 5.3.1
2. **Jacobsthal Numbers**: OEIS A001045
3. **STL Containers**: cppreference.com
4. **Red-Black Trees**: Introduction to Algorithms (CLRS), Chapter 13
