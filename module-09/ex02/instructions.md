# PmergeMe (ex02) - Test Instructions

## Build

```bash
make        # build
make re     # clean rebuild
```

## Run the automated test suite

```bash
bash test.sh
```

This runs 27 tests covering:
- Error cases (no args, negative, non-numeric, floats, special chars)
- Basic sorting with 5-10 elements
- Edge cases (1 element, 2 elements, already sorted, reverse, duplicates, INT_MAX)
- Element count preservation (output has same count as input)
- Medium (100) and large (3000) random inputs
- Output format verification (Before/After/vector time/deque time)

## Manual tests (what the evaluator will do)

### Step 1: Small manual input (5-10 positive integers)

```bash
./PmergeMe 5 3 8 1 9 2 7
./PmergeMe 42 21 7 99 3 15
./PmergeMe 9 8 7 6 5 4 3 2 1
```

Expected: prints Before, After (sorted), and timing for both containers.

### Step 2: Large input (eval command)

```bash
./PmergeMe $(shuf -i 1-1000 -n 3000 | tr "\n" " ")
```

Note: `shuf -i 1-1000 -n 3000` on Linux produces at most 1000 unique numbers
(range is 1-1000 without replacement). This is expected behavior.

For truly 3000 elements, use a wider range:

```bash
./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" " ")
```

### Step 3: Error cases

```bash
./PmergeMe              # no args -> Error
./PmergeMe 1 -2 3       # negative -> Error
./PmergeMe 1 abc 3      # non-numeric -> Error
```

## What the evaluator will ask about

### "Why is vector faster than deque?"

- `std::vector` stores elements contiguously in memory (single block of RAM),
  giving excellent cache locality. When iterating/inserting, the CPU cache
  prefetches nearby memory efficiently.
- `std::deque` stores elements in scattered fixed-size blocks. Traversal crosses
  block boundaries, causing more cache misses. The extra indirection (pointer to
  block, then offset within block) adds overhead.
- For `lower_bound` (binary search): vector's contiguous layout means random
  access is a simple pointer offset. Deque's random access requires computing
  which block + offset, adding constant overhead per access.

### "Explain the Ford-Johnson (merge-insertion sort) algorithm"

1. **Pair up** elements. Compare each pair, identify the larger (winner) and
   smaller (loser).
2. **Recursively sort** the winners using the same algorithm.
3. Build the **main chain** from sorted winners. Insert the first loser (partner
   of smallest winner) at the front — it's guaranteed to be smaller.
4. Insert remaining losers into the main chain using **binary search**
   (`std::lower_bound`), following the **Jacobsthal number sequence** for
   insertion order (1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, ...).
5. Handle the **straggler** (odd element out) by binary-inserting it last.

### "Why Jacobsthal insertion order?"

The Jacobsthal sequence (0, 1, 1, 3, 5, 11, 21, 43, ...) determines the
optimal insertion order to minimize the total number of comparisons. Each
pend element is inserted when the search range is a power of 2 minus 1
(e.g., 1, 3, 7, 15...), which is the sweet spot for binary search
(ceil(log2(n+1)) comparisons). This makes Ford-Johnson comparison-optimal
for small n.
