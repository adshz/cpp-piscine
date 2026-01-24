# C++ Module 07: Templates - Evaluation Review Guide

> Quick reference for evaluation preparation. Covers all exercises, key concepts, pitfalls, and practical tips.

---

## Table of Contents

1. [Module Overview](#module-overview)
2. [Exercise 00: Start with a Few Functions](#exercise-00-start-with-a-few-functions)
3. [Exercise 01: Iter](#exercise-01-iter)
4. [Exercise 02: Array](#exercise-02-array)
5. [Quick Reference Cheatsheet](#quick-reference-cheatsheet)
6. [Common Evaluation Questions](#common-evaluation-questions)
7. [Shell Tips for Evaluation](#shell-tips-for-evaluation)

---

## Module Overview

### What This Module Covers
- **C++ Templates** - Generic programming fundamentals
- **Function Templates** - Functions that work with any type
- **Class Templates** - Classes parameterized by type

### Compilation Requirements
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### Key Rules
| Rule | Description |
|------|-------------|
| Templates in headers | Template definitions MUST be in `.hpp` files |
| No STL containers | Containers/algorithms forbidden until Module 08-09 |
| Orthodox Canonical Form | Required for all classes |
| Memory management | Use `new`/`delete`, NOT `malloc`/`free` |

---

## Exercise 00: Start with a Few Functions

### Purpose
Implement three **function templates**: `swap`, `min`, `max`

### The Code
```cpp
// whatever.hpp
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
    return (a < b) ? a : b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
    return (a > b) ? a : b;
}
```

### Things to Master

| Concept | Why It Matters |
|---------|----------------|
| `template <typename T>` | Declares a type parameter - can also use `class` instead of `typename` |
| Pass by reference `T &` | Avoids copying, allows modification |
| Return `T const &` | Returns reference to original, prevents copying |
| Comparison operators | Type `T` must support `<` and `>` |

### Things to Be Careful About

1. **Equal values behavior**:
   ```cpp
   min(a, b)  // Returns b if a == b (second argument)
   max(a, b)  // Returns b if a == b (second argument)
   ```
   This matches the subject requirement!

2. **Global scope operator `::swap`**:
   - Use `::` to call YOUR functions, not `std::swap`
   ```cpp
   ::swap(a, b);   // Your function
   std::swap(a,b); // STL function (different!)
   ```

3. **Why `const &` return?**
   - Returning by value would create a copy
   - Returning non-const ref could allow modification of temporaries
   - `const &` is safe and efficient

### Test It
```cpp
int a = 2, b = 3;
::swap(a, b);
std::cout << a << " " << b << std::endl;  // Output: 3 2
std::cout << ::min(a, b) << std::endl;    // Output: 2
std::cout << ::max(a, b) << std::endl;    // Output: 3
```

---

## Exercise 01: Iter

### Purpose
Implement a function template that applies a function to each element of an array.

### The Code
```cpp
// iter.hpp
template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}
```

### Things to Master

| Concept | Explanation |
|---------|-------------|
| Multiple template params | `<typename T, typename F>` - two type parameters |
| Function as parameter | `F func` can be function pointer OR functor |
| Type deduction | Compiler figures out T and F from arguments |
| Higher-order functions | Functions that take functions as arguments |

### Things to Be Careful About

1. **Passing template functions**:
   ```cpp
   // WRONG - compiler doesn't know which instantiation
   iter(arr, 5, print);

   // CORRECT - explicitly instantiate
   iter(arr, 5, print<int>);
   ```

2. **Const correctness of passed function**:
   ```cpp
   // For reading elements (const reference)
   template <typename T>
   void print(T const &x) { std::cout << x << std::endl; }

   // For modifying elements (non-const reference)
   template <typename T>
   void increment(T &x) { x++; }
   ```

3. **Array size type**: Use `size_t` (unsigned) not `int`

### Test It
```cpp
int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, print<int>);      // Prints: 1 2 3 4 5
iter(arr, 5, increment<int>);  // arr becomes: 2 3 4 5 6
```

---

## Exercise 02: Array

### Purpose
Implement a **class template** for a safe array with bounds checking.

### The Code (Complete)
```cpp
// Array.hpp
#include <exception>

template <typename T>
class Array
{
private:
    T           *_data;
    unsigned int _size;

public:
    // Default constructor - empty array
    Array() : _data(NULL), _size(0) {}

    // Parametric constructor - n elements, default initialized
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor - deep copy
    Array(Array const &src) : _data(NULL), _size(0)
    {
        *this = src;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // Assignment operator - deep copy
    Array &operator=(Array const &rhs)
    {
        if (this != &rhs)
        {
            delete[] _data;
            _size = rhs._size;
            _data = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _data[i] = rhs._data[i];
        }
        return *this;
    }

    // Subscript operator (non-const)
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::exception();
        return _data[index];
    }

    // Subscript operator (const)
    T const &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::exception();
        return _data[index];
    }

    // Size getter
    unsigned int size() const { return _size; }
};
```

### Things to Master

| Concept | Why It Matters |
|---------|----------------|
| `new T[n]()` | The `()` ensures default initialization (int = 0) |
| `delete[]` | MUST match `new[]` - not `delete` |
| Deep copy | Both copy ctor and `operator=` must copy data |
| Self-assignment check | `if (this != &rhs)` prevents bugs |
| Two `operator[]` | Const and non-const versions needed |
| Exception on bounds | `throw std::exception()` when out of range |

### Things to Be Careful About

1. **The Critical `()` in `new T[n]()`**:
   ```cpp
   new T[n]    // Elements UNINITIALIZED (garbage values!)
   new T[n]()  // Elements DEFAULT-INITIALIZED (int=0, ptr=NULL)
   ```
   **This is a common evaluation question!**

2. **Why two `operator[]`?**
   ```cpp
   Array<int> arr(5);
   arr[0] = 42;           // Calls non-const version

   const Array<int> carr(5);
   int x = carr[0];       // Calls const version
   // carr[0] = 42;       // Error! Returns const reference
   ```

3. **Deep vs Shallow copy**:
   ```cpp
   // WRONG (shallow copy - shares pointer!)
   _data = rhs._data;

   // CORRECT (deep copy - separate memory)
   _data = new T[_size]();
   for (unsigned int i = 0; i < _size; i++)
       _data[i] = rhs._data[i];
   ```

4. **Memory leak prevention in `operator=`**:
   ```cpp
   delete[] _data;  // Free OLD memory BEFORE allocating new
   ```

5. **Bounds checking with unsigned**:
   ```cpp
   arr[-1]  // -1 becomes huge positive number (unsigned wrap)
            // Still caught by: index >= _size
   ```

### Test It
```cpp
try {
    Array<int> arr(5);
    arr[0] = 42;
    arr[10] = 0;  // Throws!
} catch (std::exception &e) {
    std::cout << "Out of bounds!" << std::endl;
}
```

---

## Quick Reference Cheatsheet

### Template Syntax
```cpp
// Function template
template <typename T>
T func(T param) { return param; }

// Class template
template <typename T>
class MyClass {
    T member;
};

// Multiple parameters
template <typename T, typename U>
void func(T a, U b) { }
```

### Orthodox Canonical Form (for templates)
```cpp
template <typename T>
class Example {
public:
    Example();                              // Default ctor
    Example(Example const &src);            // Copy ctor
    ~Example();                             // Destructor
    Example &operator=(Example const &rhs); // Assignment
};
```

### Common Patterns
| Pattern | Code |
|---------|------|
| Pass by const ref | `T const &param` |
| Return by const ref | `T const &func()` |
| Default initialization | `new T[n]()` |
| Bounds check | `if (index >= size) throw std::exception();` |
| Self-assignment check | `if (this != &rhs)` |

---

## Common Evaluation Questions

### Q1: Why use `typename` vs `class` in templates?
**A:** They're interchangeable for type parameters. `typename` is more modern and clear that it's a type, not necessarily a class.

### Q2: Why must templates be in header files?
**A:** The compiler needs to see the full template definition to generate code for each type used. Separating into `.cpp` files causes linker errors.

### Q3: What does `new T[n]()` do differently from `new T[n]`?
**A:** The `()` adds value-initialization:
- `new int[5]` → garbage values
- `new int[5]()` → all zeros

### Q4: Why two versions of `operator[]`?
**A:**
- Non-const: allows modification (`arr[0] = 5`)
- Const: allows reading from const objects (`cout << constArr[0]`)

### Q5: What happens if you forget self-assignment check?
**A:** `arr = arr` would:
1. Delete `_data`
2. Try to copy from deleted memory
3. Crash or undefined behavior

### Q6: Why return `*this` in `operator=`?
**A:** Enables chaining: `a = b = c;`

---

## Shell Tips for Evaluation

### Copying Files Correctly

When setting up your evaluation workspace:

```bash
# WRONG - causes conflicts with duplicate filenames
cp -r module-07/** destination/

# CORRECT - preserves directory structure
cp -r module-07/* destination/
```

| Glob | What It Does |
|------|--------------|
| `*` | Matches files/dirs in current directory only |
| `**` | Matches recursively (flattens structure - causes conflicts!) |

### Verifying Copy Success

```bash
# Method 1: Check exit code
cp -r source/* dest/ && echo "SUCCESS" || echo "FAILED"

# Method 2: Compare directories
diff -r source dest

# Method 3: Verbose mode
cp -rv source/* dest/
```

### Quick Compilation Test

```bash
# Compile all exercises quickly
for ex in ex00 ex01 ex02; do
    echo "=== $ex ===" && cd $ex && make && cd ..
done
```

### Memory Leak Check (if valgrind available)

```bash
valgrind --leak-check=full ./program
```

---

## Final Checklist Before Evaluation

### Code Quality
- [ ] All templates in header files
- [ ] No memory leaks (`new`/`delete` paired)
- [ ] Bounds checking throws exceptions
- [ ] Deep copy implemented correctly
- [ ] Self-assignment check in `operator=`
- [ ] Two versions of `operator[]` (const/non-const)
- [ ] `new T[n]()` with parentheses for initialization

### Compilation
- [ ] Compiles with `-Wall -Wextra -Werror`
- [ ] No warnings
- [ ] C++98 standard compliant

### Understanding
- [ ] Can explain why templates must be in headers
- [ ] Can explain `new T[n]()` vs `new T[n]`
- [ ] Can explain deep copy vs shallow copy
- [ ] Can explain const correctness in templates
- [ ] Can demonstrate bounds checking with exceptions

---

*Good luck with your evaluation!*
