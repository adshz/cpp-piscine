# Module 08 Deep Analysis
## Templated Containers, Iterators, Algorithms

---

## Table of Contents
1. [Core Concepts Overview](#core-concepts-overview)
2. [STL Architecture](#stl-architecture)
3. [Exercise 00: easyfind](#exercise-00-easyfind)
4. [Exercise 01: Span](#exercise-01-span)
5. [Exercise 02: MutantStack](#exercise-02-mutantstack)
6. [Key Takeaways](#key-takeaways)

---

## Core Concepts Overview

### The STL Triangle

```mermaid
graph TB
    subgraph "STL Core Components"
        C[Containers]
        A[Algorithms]
        I[Iterators]
    end

    C <-->|"provide"| I
    I <-->|"connect to"| A
    A <-->|"operate on"| C

    subgraph "Containers"
        C1[Sequence: vector, list, deque]
        C2[Associative: set, map]
        C3[Adapters: stack, queue]
    end

    subgraph "Algorithms"
        A1[Non-modifying: find, count]
        A2[Modifying: sort, copy]
        A3[Numeric: accumulate]
    end

    subgraph "Iterators"
        I1[Input/Output]
        I2[Forward]
        I3[Bidirectional]
        I4[Random Access]
    end

    C --> C1
    C --> C2
    C --> C3
    A --> A1
    A --> A2
    A --> A3
    I --> I1
    I --> I2
    I --> I3
    I --> I4
```

### Iterator Hierarchy

```mermaid
graph BT
    Input[Input Iterator<br/>read, ++]
    Output[Output Iterator<br/>write, ++]
    Forward[Forward Iterator<br/>read/write, ++]
    Bidirectional[Bidirectional Iterator<br/>read/write, ++, --]
    RandomAccess[Random Access Iterator<br/>read/write, ++, --, +n, -n, []]

    Input --> Forward
    Output --> Forward
    Forward --> Bidirectional
    Bidirectional --> RandomAccess

    style RandomAccess fill:#90EE90
    style Bidirectional fill:#87CEEB
    style Forward fill:#DDA0DD
```

**Container Iterator Types:**
| Container | Iterator Type |
|-----------|---------------|
| `vector` | Random Access |
| `deque` | Random Access |
| `list` | Bidirectional |
| `set/map` | Bidirectional |
| `stack/queue` | None (adapters) |

---

## STL Architecture

### How Algorithms Connect to Containers

```mermaid
sequenceDiagram
    participant User
    participant Algorithm as std::find
    participant Iterator
    participant Container as std::vector

    User->>Algorithm: find(vec.begin(), vec.end(), 42)
    Algorithm->>Iterator: Get begin iterator
    Iterator->>Container: Access element at position 0
    Container-->>Iterator: Return element
    Iterator-->>Algorithm: Return value

    loop Until found or end
        Algorithm->>Iterator: ++it (advance)
        Iterator->>Container: Access next element
        Container-->>Iterator: Return element
        Algorithm->>Algorithm: Compare with 42
    end

    Algorithm-->>User: Return iterator to found element (or end)
```

### Template Mechanism

```mermaid
graph LR
    subgraph "Compile Time"
        T1[Template Definition<br/>template &lt;typename T&gt;]
        T2[Template Instantiation<br/>easyfind&lt;vector&lt;int&gt;&gt;]
        T3[Generated Code<br/>Concrete function]
    end

    T1 -->|"When used with"| T2
    T2 -->|"Compiler generates"| T3

    subgraph "Example"
        E1["easyfind(vec, 5)"]
        E2["Compiler sees T = vector&lt;int&gt;"]
        E3["Generates: vector&lt;int&gt;::iterator easyfind(vector&lt;int&gt;&, int)"]
    end

    E1 --> E2 --> E3
```

---

## Exercise 00: easyfind

### Concept Map

```mermaid
graph TB
    subgraph "easyfind Function Template"
        EF[easyfind&lt;T&gt;]
        P1[Parameter 1: T& container]
        P2[Parameter 2: int value]
        R[Returns: T::iterator]
    end

    EF --> P1
    EF --> P2
    EF --> R

    subgraph "Implementation"
        SF[std::find algorithm]
        BEGIN[container.begin]
        END[container.end]
        COMP[Compare each element]
    end

    P1 --> BEGIN
    P1 --> END
    SF --> BEGIN
    SF --> END
    SF --> COMP
    P2 --> COMP

    subgraph "Result"
        FOUND[Element Found<br/>Return iterator to element]
        NOTFOUND[Not Found<br/>Throw exception]
    end

    COMP -->|"Match"| FOUND
    COMP -->|"End reached"| NOTFOUND
```

### Code Flow

```mermaid
flowchart TD
    A[Start: easyfind called] --> B[Get container.begin and container.end]
    B --> C[Call std::find with begin, end, value]
    C --> D{std::find returns iterator}
    D -->|"it == end"| E[Throw NotFoundException]
    D -->|"it != end"| F[Return iterator to found element]
    E --> G[Exception propagates to caller]
    F --> H[Caller receives valid iterator]

    style E fill:#ffcccc
    style F fill:#ccffcc
```

### Why Use std::find?

```mermaid
graph LR
    subgraph "Manual Search ❌"
        M1[Write loop]
        M2[Handle edge cases]
        M3[Error prone]
        M4[Reinvent the wheel]
    end

    subgraph "std::find ✓"
        S1[One line]
        S2[Tested & optimized]
        S3[Works with any container]
        S4[STL compliant]
    end

    M1 --> M2 --> M3 --> M4
    S1 --> S2 --> S3 --> S4
```

---

## Exercise 01: Span

### Class Architecture

```mermaid
classDiagram
    class Span {
        -unsigned int _maxSize
        -vector~int~ _numbers
        +Span()
        +Span(unsigned int n)
        +Span(const Span&)
        +~Span()
        +operator=(const Span&) Span&
        +addNumber(int) void
        +addNumber~Iterator~(Iterator, Iterator) void
        +shortestSpan() int
        +longestSpan() int
    }

    class SpanFullException {
        +what() const char*
    }

    class NoSpanException {
        +what() const char*
    }

    Span *-- SpanFullException : throws
    Span *-- NoSpanException : throws

    class std_exception {
        <<interface>>
        +what() const char*
    }

    SpanFullException --|> std_exception
    NoSpanException --|> std_exception
```

### shortestSpan Algorithm

```mermaid
flowchart TD
    A[Start shortestSpan] --> B{numbers.size < 2?}
    B -->|Yes| C[Throw NoSpanException]
    B -->|No| D[Create sorted copy of _numbers]
    D --> E[Initialize minSpan = INT_MAX]
    E --> F[Loop i = 1 to size-1]
    F --> G["diff = sorted[i] - sorted[i-1]"]
    G --> H{diff < minSpan?}
    H -->|Yes| I[minSpan = diff]
    H -->|No| J[Continue]
    I --> J
    J --> K{More elements?}
    K -->|Yes| F
    K -->|No| L[Return minSpan]

    style C fill:#ffcccc
    style L fill:#ccffcc
```

### Why Sort for Shortest Span?

```mermaid
graph TB
    subgraph "Example: [6, 3, 17, 9, 11]"
        U[Unsorted: 6, 3, 17, 9, 11]
        S[Sorted: 3, 6, 9, 11, 17]
    end

    subgraph "Adjacent Differences in Sorted"
        D1["6-3 = 3"]
        D2["9-6 = 3"]
        D3["11-9 = 2 ← minimum"]
        D4["17-11 = 6"]
    end

    S --> D1
    S --> D2
    S --> D3
    S --> D4

    subgraph "Key Insight"
        K["In a sorted array, the minimum<br/>difference is ALWAYS between<br/>adjacent elements"]
    end

    style D3 fill:#90EE90
```

### longestSpan Algorithm

```mermaid
flowchart LR
    A[_numbers] --> B[std::min_element]
    A --> C[std::max_element]
    B --> D[min value]
    C --> E[max value]
    D --> F["longestSpan = max - min"]
    E --> F

    subgraph "Example"
        EX["[6, 3, 17, 9, 11]<br/>min=3, max=17<br/>span = 17-3 = 14"]
    end
```

### Range-based addNumber

```mermaid
sequenceDiagram
    participant User
    participant Span
    participant Vector as std::vector

    User->>Vector: Create vector with values
    User->>Span: addNumber(vec.begin(), vec.end())

    loop For each element
        Span->>Span: addNumber(*iterator)
        Span->>Span: Check if full
        alt Is Full
            Span-->>User: Throw SpanFullException
        else Has Space
            Span->>Span: Push to _numbers
        end
        Span->>Span: ++iterator
    end

    Span-->>User: All numbers added
```

---

## Exercise 02: MutantStack

### Inheritance Architecture

```mermaid
classDiagram
    class std_stack~T~ {
        #container_type c
        +push(const T&) void
        +pop() void
        +top() T&
        +size() size_type
        +empty() bool
    }

    class MutantStack~T~ {
        +MutantStack()
        +MutantStack(const MutantStack&)
        +~MutantStack()
        +operator=(const MutantStack&) MutantStack&
        +begin() iterator
        +end() iterator
        +rbegin() reverse_iterator
        +rend() reverse_iterator
    }

    MutantStack --|> std_stack : inherits

    note for std_stack "Protected member 'c' is the<br/>underlying container (deque by default)"
    note for MutantStack "Exposes c's iterators<br/>via this->c.begin() etc."
```

### How std::stack Works Internally

```mermaid
graph TB
    subgraph "std::stack<int>"
        STACK[stack interface]
        subgraph "Protected Member"
            C["container_type c<br/>(default: std::deque)"]
        end

        PUSH[push] -->|"c.push_back"| C
        POP[pop] -->|"c.pop_back"| C
        TOP[top] -->|"c.back"| C
        SIZE[size] -->|"c.size"| C
    end

    subgraph "Underlying deque"
        D1[5]
        D2[3]
        D3[737]
        D4[0]
    end

    C --> D1
    D1 --> D2
    D2 --> D3
    D3 --> D4

    style STACK fill:#87CEEB
```

### MutantStack Iterator Access

```mermaid
flowchart LR
    subgraph "MutantStack"
        MS[MutantStack instance]
        BEGIN["begin()<br/>returns this->c.begin()"]
        END["end()<br/>returns this->c.end()"]
    end

    subgraph "Underlying Container (deque)"
        IT1["iterator → [0]"]
        IT2["iterator → [1]"]
        IT3["iterator → [2]"]
        IT4["iterator → end"]
    end

    MS --> BEGIN
    MS --> END
    BEGIN --> IT1
    IT1 -->|"++"| IT2
    IT2 -->|"++"| IT3
    IT3 -->|"++"| IT4
    END --> IT4
```

### Comparison: stack vs MutantStack vs list

```mermaid
graph TB
    subgraph "std::stack"
        S1[push/pop/top only]
        S2[No iteration]
        S3[LIFO access]
    end

    subgraph "MutantStack"
        M1[push/pop/top]
        M2[Full iteration ✓]
        M3[LIFO + Sequential access]
    end

    subgraph "std::list"
        L1[push_back/pop_back]
        L2[Full iteration ✓]
        L3[Sequential access]
    end

    S1 --> S2 --> S3
    M1 --> M2 --> M3
    L1 --> L2 --> L3

    style M2 fill:#90EE90
    style L2 fill:#90EE90
    style S2 fill:#ffcccc
```

### Type Definitions Explained

```mermaid
graph LR
    subgraph "MutantStack Type Aliases"
        T1["typedef typename<br/>std::stack<T>::container_type::iterator<br/>iterator"]
    end

    subgraph "What This Means"
        A["std::stack<int>"]
        B["container_type = std::deque<int>"]
        C["iterator = std::deque<int>::iterator"]
    end

    T1 --> A
    A --> B
    B --> C

    subgraph "Why typename?"
        W["Tells compiler that<br/>container_type::iterator<br/>is a TYPE, not a value"]
    end
```

---

## Key Takeaways

### Mental Model: STL Design Philosophy

```mermaid
graph TB
    subgraph "Generic Programming"
        G1[Write once]
        G2[Work with any type]
        G3[No runtime overhead]
    end

    subgraph "Separation of Concerns"
        S1[Containers store data]
        S2[Algorithms process data]
        S3[Iterators connect them]
    end

    subgraph "Efficiency"
        E1[Compile-time polymorphism]
        E2[Inlined template code]
        E3[Zero-cost abstractions]
    end

    G1 --> G2 --> G3
    S1 --> S2 --> S3
    E1 --> E2 --> E3
```

### Summary Table

| Exercise | Key Concept | STL Components Used |
|----------|-------------|---------------------|
| ex00 | Function templates + Algorithms | `std::find`, iterators |
| ex01 | Class design + Algorithms | `std::vector`, `std::sort`, `std::min_element`, `std::max_element` |
| ex02 | Inheritance + Container adapters | `std::stack`, underlying container iterators |

### Common Pitfalls to Avoid

```mermaid
graph TB
    subgraph "❌ Wrong"
        W1[Manual loops instead of algorithms]
        W2[Forgetting to check iterator validity]
        W3[Not using const where appropriate]
        W4[Ignoring exception safety]
    end

    subgraph "✓ Correct"
        C1[Use std::find, std::sort, etc.]
        C2[Always check against end]
        C3[Use const_iterator for read-only]
        C4[Throw meaningful exceptions]
    end

    W1 -.->|"Replace with"| C1
    W2 -.->|"Replace with"| C2
    W3 -.->|"Replace with"| C3
    W4 -.->|"Replace with"| C4
```

---

## Memory Layout Visualization

### Span Internal Structure

```
Span object (stack)
┌─────────────────────────────────┐
│ _maxSize: unsigned int (4 bytes)│
├─────────────────────────────────┤
│ _numbers: std::vector<int>      │
│   ┌─────────────────────────┐   │
│   │ pointer to data (heap)  │───┼──► [3, 6, 9, 11, 17] (heap)
│   │ size: 5                 │   │
│   │ capacity: 8             │   │
│   └─────────────────────────┘   │
└─────────────────────────────────┘
```

### MutantStack Internal Structure

```
MutantStack<int> (inherits from std::stack<int>)
┌─────────────────────────────────────────┐
│ std::stack<int> base                    │
│   ┌─────────────────────────────────┐   │
│   │ c: std::deque<int> (protected)  │   │
│   │   ┌─────────────────────────┐   │   │
│   │   │ chunk pointers          │───┼───┼──► [5, 3, 737, 0]
│   │   │ size: 4                 │   │   │
│   │   └─────────────────────────┘   │   │
│   └─────────────────────────────────┘   │
│ (no additional members)                 │
└─────────────────────────────────────────┘

Iterator points into the deque's internal storage
begin() → [5]  (first element)
end()   → [past 0] (one past last)
```

---

## Quick Reference Card

```
┌────────────────────────────────────────────────────────────────┐
│                    MODULE 08 CHEAT SHEET                       │
├────────────────────────────────────────────────────────────────┤
│ EASYFIND:                                                      │
│   std::find(container.begin(), container.end(), value)         │
│   Returns: iterator to element or end() if not found           │
├────────────────────────────────────────────────────────────────┤
│ SPAN:                                                          │
│   shortestSpan: sort → find min adjacent difference            │
│   longestSpan:  max_element - min_element                      │
│   Range add:    template<Iterator> addNumber(begin, end)       │
├────────────────────────────────────────────────────────────────┤
│ MUTANTSTACK:                                                   │
│   Inherit from std::stack<T>                                   │
│   Access underlying container: this->c                         │
│   Expose iterators: this->c.begin(), this->c.end()            │
├────────────────────────────────────────────────────────────────┤
│ ITERATOR TYPES:                                                │
│   typename T::iterator              (modifiable)               │
│   typename T::const_iterator        (read-only)                │
│   typename T::reverse_iterator      (backwards)                │
└────────────────────────────────────────────────────────────────┘
```
