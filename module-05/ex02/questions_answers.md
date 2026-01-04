# Questions & Answers - C++98 Module 05

This document provides detailed explanations for each question raised during the practice of CPP Module 05 exercises.

---

## Question 1 - Are `const` in return type with different positions the same?

```cpp
std::string const& getName(void) const;
```
vs
```cpp
const std::string& getName(void) const;
```

<ANSWER>

**Yes, they are semantically identical in C++.**

In C++, the `const` qualifier can be placed either **before** or **after** the type it modifies when dealing with the base type. 
Both declarations mean exactly the same thing: "return a const reference to a std::string."

```cpp
const std::string&   // "const" before the type
std::string const&   // "const" after the type
```

This equivalence applies to the **base type** only. The two styles are called:
- **West const**: `const` on the left side (`const int x`)
- **East const**: `const` on the right side (`int const x`)

**Why East const exists:**
East const proponents argue it reads more consistently from right-to-left:
```cpp
int const * const ptr;  // ptr is a const pointer to a const int
```
Reading right-to-left: "ptr is const, pointer to, const int"

**Important distinction with pointers:**
```cpp
const int* ptr;      // pointer to const int (can change pointer, not value)
int* const ptr;      // const pointer to int (can change value, not pointer)
int const* ptr;      // SAME as "const int*" - pointer to const int
```

The position matters when `const` appears on different sides of `*`.

</ANSWER>

---

## Question 2 - Returning references and const correctness

Your understanding about returning `const std::string&` vs `std::string` is worth exploring.

<ANSWER>

**Your understanding is partially correct. Let me clarify:**

### Case 1: Returning `const std::string&`
```cpp
const std::string& Bureaucrat::getName(void) const {
    return this->_name;
}
```
This returns a **const reference** to the private member. The caller can read but **cannot modify** it through the returned reference.

```cpp
const std::string& name = b.getName();  // OK: binds to const reference
std::string copy = b.getName();         // OK: makes a copy
name = "hacked";                        // ERROR: cannot modify const reference
```

### Case 2: Returning `std::string` (by value)
```cpp
std::string Bureaucrat::getName(void) const {
    return this->_name;
}
```
This returns a **copy** of the private member. Safer in terms of encapsulation but has copy overhead.

### Your question: What if we use `std::string noConstName = b.getName();`?

```cpp
const std::string& Bureaucrat::getName(void) const { return _name; }

std::string noConstName = b.getName();  // WORKS! Creates a copy
```

**This compiles and works fine!** When you assign a `const std::string&` to a `std::string`, C++ makes a **copy**. The `noConstName` is now an independent string that has nothing to do with `_name`.

### The danger scenario (without `const` in return type):
```cpp
std::string& Bureaucrat::getName(void) const {  // BAD: non-const reference return
    return this->_name;  // Compiler error: returning non-const ref to member in const function
}
```

Even if this compiled:
```cpp
std::string& nameRef = b.getName();
nameRef = "hacked";  // Would modify private member!
```

### Summary:
| Return Type | Can modify original? | Copy overhead? |
|-------------|---------------------|----------------|
| `std::string` | No (returns copy) | Yes |
| `const std::string&` | No (const prevents it) | No |
| `std::string&` | YES (dangerous!) | No |

**Best practice:** Use `const std::string&` for getters - it's efficient (no copy) and safe (const prevents modification).

</ANSWER>

---

## Question 3 - Form vs AForm and Polymorphism

You're comparing `signForm(Form& form)` in ex01 vs `signForm(AForm& form)` in ex02.

<ANSWER>

**The key concept here is Polymorphism via abstract base classes.**

### The Design Evolution:

**ex01 - Concrete Form class:**
```
+------------+
|   Form     |  <-- Concrete class, can be instantiated
+------------+
```

**ex02 - Abstract AForm with derived classes:**
```
        +------------+
        |   AForm    |  <-- Abstract class (has pure virtual function)
        +------------+
              ^
              |  (inheritance)
    +---------+---------+---------+
    |                   |                   |
+--------+      +--------+      +--------+
|Shrubbery|     |Robotomy|      |Presidential|
|Creation |     |Request |      |Pardon      |
|  Form   |     |  Form  |      |   Form     |
+--------+      +--------+      +--------+
```

### ASCII Art Class Hierarchy:

```
                        +---------------------------+
                        |          AForm            |
                        |---------------------------|
                        | - _name: string const     |
                        | - _signed: bool           |
                        | - _gradeToSign: int const |
                        | - _gradeToExec: int const |
                        |---------------------------|
                        | + beSigned(Bureaucrat&)   |
                        | + execute(Bureaucrat&)    |
                        | # executeAction() = 0     | <-- Pure virtual (abstract)
                        +---------------------------+
                                    ^
                                    | inherits
          +-------------------------+-------------------------+
          |                         |                         |
+---------+---------+   +-----------+---------+   +-----------+---------+
|ShrubberyCreation  |   |  RobotomyRequest    |   |PresidentialPardon   |
|       Form        |   |       Form          |   |       Form          |
|-------------------|   |---------------------|   |---------------------|
| - _target: string |   | - _target: string   |   | - _target: string   |
|-------------------|   |---------------------|   |---------------------|
| + executeAction() |   | + executeAction()   |   | + executeAction()   |
| (creates ASCII    |   | (50% success rate   |   | (pardons the target)|
|  tree file)       |   |  robotomy)          |   |                     |
+-------------------+   +---------------------+   +---------------------+
```

### Why this matters for `signForm(AForm& form)`:

```cpp
void Bureaucrat::signForm(AForm& form) const;  // Takes reference to BASE class
```

Thanks to **polymorphism**, this single function can handle ANY derived form:

```cpp
ShrubberyCreationForm shrub("home");
RobotomyRequestForm robot("Bender");
PresidentialPardonForm pardon("Ford");

bureaucrat.signForm(shrub);   // Works! Shrubbery IS-A AForm
bureaucrat.signForm(robot);   // Works! Robotomy IS-A AForm
bureaucrat.signForm(pardon);  // Works! Presidential IS-A AForm
```

### The Purpose:
1. **Code reuse**: One `signForm` function works for all form types
2. **Open-Closed Principle**: Can add new form types without modifying Bureaucrat
3. **Runtime polymorphism**: The correct `executeAction()` is called based on actual object type

</ANSWER>

---

## Question 4 - `virtual` vs pure `virtual` and `throw()`

<ANSWER>

### Virtual vs Pure Virtual

**Virtual function:**
```cpp
class Base {
public:
    virtual const char* what() const throw();  // CAN be overridden
};
```
- Provides a **default implementation**
- Derived classes **may** override it
- Class **can** be instantiated

**Pure virtual function:**
```cpp
class Base {
public:
    virtual const char* what() const throw() = 0;  // MUST be overridden
};
```
- No default implementation (the `= 0` makes it pure)
- Derived classes **must** override it
- Class **cannot** be instantiated (becomes abstract)

### The `throw()` Specification (C++98)

```cpp
virtual const char* what(void) const throw();
```

The `throw()` at the end is an **exception specification** (deprecated in C++11, removed in C++17):

| Syntax | Meaning |
|--------|---------|
| `throw()` | Function promises to throw **no exceptions** |
| `throw(ExceptionType)` | Function may only throw `ExceptionType` |
| (nothing) | Function may throw any exception |

**Why `what()` uses `throw()`:**
The `std::exception::what()` promises it won't throw exceptions because:
1. It's called during exception handling
2. Throwing while handling an exception causes `std::terminate()`
3. It must be reliable for error reporting

**Modern C++ equivalent:**
```cpp
virtual const char* what() const noexcept;  // C++11 and later
```

### Your Exception Class:
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what(void) const throw();  // Override from std::exception
};

// Implementation
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
```

</ANSWER>

---

## Question 5 - Is `std::exception` a base class? Where to read source code?

<ANSWER>

**Yes, `std::exception` is the standard base class for all standard library exceptions.**

### Exception Hierarchy:
```
                    std::exception
                          |
     +--------------------+--------------------+
     |                    |                    |
std::logic_error    std::runtime_error    std::bad_alloc
     |                    |
     +--+--+--+      +----+----+
     |  |  |  |      |    |    |
     (various derived exceptions...)
```

### Reading the Source Code:

**Location on Linux (GCC):**
```bash
# Standard exception header
/usr/include/c++/VERSION/exception

# For example:
cat /usr/include/c++/11/exception
cat /usr/include/c++/11/bits/exception.h
```

**Simplified definition:**
```cpp
namespace std {
    class exception {
    public:
        exception() noexcept;
        exception(const exception&) noexcept;
        exception& operator=(const exception&) noexcept;
        virtual ~exception() noexcept;

        virtual const char* what() const noexcept;  // THE KEY METHOD
    };
}
```

### Why inherit from `std::exception`:
1. **Standardization**: All exceptions can be caught with `catch(std::exception& e)`
2. **Interface**: Provides `what()` for error messages
3. **Interoperability**: Works with standard library components

```cpp
try {
    // ... code that might throw ...
} catch (std::exception& e) {
    // Catches ANY standard exception or custom ones inheriting from it
    std::cout << e.what() << std::endl;
}
```

</ANSWER>

---

## Question 6 - `int const _grade` vs `const int _grade`

<ANSWER>

**They are identical. Both mean "a constant int that cannot be reassigned."**

```cpp
int const _grade;   // East const style
const int _grade;   // West const style (more common)
```

### What `const` prevents:

```cpp
class Bureaucrat {
private:
    int const _grade;  // Once initialized, CANNOT be changed

public:
    Bureaucrat(int grade) : _grade(grade) {}  // Must use initializer list!

    void setGrade(int g) {
        _grade = g;  // ERROR: cannot assign to const member
    }
};
```

### Key points:

1. **Cannot reassign**: After initialization, the value is fixed
2. **Must initialize in initializer list**: Since you can't assign later
3. **Type cannot "change"**: The type is always `int` - `const` restricts modification, not type

### Common mistake:
```cpp
Bureaucrat::Bureaucrat(int grade) {
    _grade = grade;  // ERROR: _grade is const, can't assign in body
}

// Correct way:
Bureaucrat::Bureaucrat(int grade) : _grade(grade) {}  // Initialization, not assignment
```

</ANSWER>

---

## Question 7 - `std::string const &` vs `const std::string &`

<ANSWER>

**Yes, they are exactly the same.** This is the same as Question 1.

```cpp
std::string const &  // East const: const after the type
const std::string &  // West const: const before the type
```

Both mean: "a reference to a constant string" - you cannot modify the string through this reference.

### Consistency matters more than choice:

Pick one style and stick with it. The 42 norm seems to prefer East const (`std::string const &`), so use that consistently in your code.

```cpp
// 42-style (East const):
std::string const & getName(void) const;
void setName(std::string const & name);

// Alternative (West const):
const std::string& getName(void) const;
void setName(const std::string& name);
```

</ANSWER>

---

## Question 8 - What is `protected` keyword and why do we need it?

<ANSWER>

### Access Specifiers in C++:

| Specifier | Same Class | Derived Class | Outside |
|-----------|------------|---------------|---------|
| `public` | Yes | Yes | Yes |
| `protected` | Yes | Yes | **No** |
| `private` | Yes | **No** | **No** |

### Why `protected` exists:

```cpp
class AForm {
private:
    std::string const _name;        // Only AForm can access
    bool _signed;                   // Only AForm can access

protected:
    void checkExecuteRequirements() const;  // AForm and derived classes can access
    virtual void executeAction() const = 0;  // Must be implemented by derived

public:
    void execute() const;           // Anyone can call
};

class ShrubberyCreationForm : public AForm {
public:
    void executeAction() const {
        // Can access protected members of AForm
        // Cannot access private members of AForm
    }
};
```

### Use case in ex02:

```cpp
class AForm {
protected:
    // Derived classes need to implement this
    virtual void executeAction(void) const = 0;

    // Helper that derived classes might need
    void checkExecutionRequirements(Bureaucrat const & executor) const;
};
```

**Why not `private`?** Derived classes couldn't call or implement them.

**Why not `public`?** External code shouldn't call `executeAction()` directly - they should use `execute()` which does permission checks first.

### Summary:
`protected` = "I trust my children (derived classes), but not strangers (external code)"

</ANSWER>

---

## Question 9 - No pure virtual function until `protected`

<ANSWER>

**This is a design decision about interface vs implementation details.**

### The pattern you're seeing:

```cpp
class AForm {
public:
    // Public interface - what external code calls
    void execute(Bureaucrat const & executor) const;

protected:
    // Implementation detail - what derived classes must provide
    virtual void executeAction(void) const = 0;
};
```

### Why pure virtual in `protected`:

1. **Encapsulation**: External code calls `execute()`, not `executeAction()`
2. **Template Method Pattern**: Base class controls the algorithm flow

```cpp
// AForm.cpp
void AForm::execute(Bureaucrat const & executor) const {
    // 1. Check if signed
    if (!this->_signed)
        throw FormNotSignedException();

    // 2. Check executor's grade
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();

    // 3. Delegate actual action to derived class
    this->executeAction();  // Polymorphic call!
}
```

The derived class ONLY implements `executeAction()` - it doesn't need to worry about permission checks.

### Visual:
```
External Code                    AForm                      ShrubberyCreationForm
     |                             |                               |
     |-- execute(bureaucrat) ----->|                               |
     |                             |-- Check permissions           |
     |                             |-- executeAction() ----------->|
     |                             |                               |-- Create tree file
     |                             |<------------------------------|
     |<----------------------------|                               |
```

</ANSWER>

---

## Question 10 - Why is destructor `virtual` but not constructor?

<ANSWER>

### Why destructors CAN be virtual:

**Problem without virtual destructor:**
```cpp
class AForm {
public:
    ~AForm() { /* cleanup AForm */ }  // Non-virtual
};

class ShrubberyCreationForm : public AForm {
    std::ofstream* _file;  // Some resource
public:
    ~ShrubberyCreationForm() { delete _file; }  // NEVER CALLED!
};

// The problem:
AForm* form = new ShrubberyCreationForm("garden");
delete form;  // Only calls ~AForm(), leaks _file!
```

**Solution - virtual destructor:**
```cpp
class AForm {
public:
    virtual ~AForm() { }  // Virtual!
};

// Now:
AForm* form = new ShrubberyCreationForm("garden");
delete form;  // Calls ~ShrubberyCreationForm() THEN ~AForm()
```

### Why constructors CANNOT be virtual:

1. **Virtual requires existing object**: Virtual dispatch uses the vtable (virtual table), which is set up BY the constructor. During construction, the object doesn't exist yet!

2. **Construction order is fixed**: Base class constructor runs first, THEN derived. This must happen in order to initialize base parts before derived parts.

3. **No polymorphism during construction**: The object IS a Base while Base constructor runs. It becomes Derived only after Derived constructor starts.

```cpp
AForm()                    // Object is an AForm
  ShrubberyCreationForm()  // NOW object becomes ShrubberyCreationForm
```

### Memory layout visualization:
```
Before constructor:        After AForm():           After Shrubbery():
+------------+            +------------+            +------------+
| ????????   |            | vtable ptr |---> AForm  | vtable ptr |---> Shrubbery
| ????????   |            | _name      |            | _name      |
| ????????   |            | _signed    |            | _signed    |
+------------+            +------------+            | _target    |
                                                    +------------+
```

**Rule**: If a class has any virtual function, make its destructor virtual too.

</ANSWER>

---

## Question 11 - Why `executeAction()` in derived class without `virtual`?

<ANSWER>

### The declaration:
```cpp
// In ShrubberyCreationForm.hpp
void executeAction(void) const;  // No "virtual" keyword
```

### This is still an override!

Once a function is declared `virtual` in a base class, it remains virtual in ALL derived classes, whether you write `virtual` or not.

```cpp
class AForm {
protected:
    virtual void executeAction(void) const = 0;  // Virtual in base
};

class ShrubberyCreationForm : public AForm {
protected:
    void executeAction(void) const;  // Still virtual! Keyword optional
    // Same as: virtual void executeAction(void) const;
};
```

### Best practices:

**C++98 style** (what you're using):
```cpp
void executeAction(void) const;  // Virtual implied, keyword optional
```

**C++11 style** (better, but not C++98):
```cpp
void executeAction(void) const override;  // Explicit override
```

### Why `virtual` in derived class is optional:

1. **Once virtual, always virtual**: The property inherits automatically
2. **Less typing**: No need to repeat `virtual`
3. **Clarity vs verbosity**: Some prefer explicit `virtual`, others find it redundant

### The purpose of `executeAction()`:

```
AForm::execute()  <-- Public interface, does permission checks
      |
      v
AForm::executeAction()  <-- Pure virtual, must be implemented
      |
      +-- ShrubberyCreationForm::executeAction()  --> Creates tree file
      +-- RobotomyRequestForm::executeAction()    --> 50% robotomy
      +-- PresidentialPardonForm::executeAction() --> Pardons target
```

Each derived class provides its OWN implementation. The base class calls it polymorphically.

</ANSWER>

---

## Question 12 - How to solve problems from vague requirements?

<ANSWER>

This is an excellent meta-question about problem-solving and learning.

### The Challenge:
You see a solution and think "Aha!" but struggle to derive it from scratch. This is the **gap between recognition and generation**.

### Strategies to Bridge the Gap:

**1. Identify the Nouns and Verbs in Requirements**
```
Subject says:
"A Bureaucrat can sign a Form"
  ^noun          ^verb   ^noun

"A Form can be executed by a Bureaucrat"
  ^noun      ^verb         ^noun
```

This naturally suggests:
- Classes: Bureaucrat, Form
- Methods: Bureaucrat::signForm(), Form::execute()

**2. Ask "What information does each action need?"**
```
To sign a form:
- Bureaucrat needs: its own grade
- Form needs: required signing grade
- Outcome: form's signed status changes

To execute a form:
- Bureaucrat needs: its own grade
- Form needs: required execution grade, signed status
- Outcome: form's action happens
```

**3. Draw Interaction Diagrams**
```
    Bureaucrat                    Form
         |                          |
         |----signForm(form)------->|
         |                          |
         |      beSigned(this)      |
         |<-------------------------|
         |                          |
         |---executeForm(form)----->|
         |                          |
         |     execute(this)        |
         |<-------------------------|
```

**4. Pattern Recognition Through Practice**

The more designs you see, the more patterns you recognize:
- Observer pattern
- Template method pattern (what ex02 uses!)
- Factory pattern

**5. Start Small, Then Expand**

Don't try to design everything at once:
1. Make Bureaucrat work alone
2. Add Form as a simple class
3. Add their interaction
4. Make Form abstract
5. Add derived classes

**6. The "What if?" Game**

Ask yourself:
- What if Bureaucrat's grade is too low?
- What if form isn't signed?
- What if we want different form types?

Each question leads to design decisions.

### Building Your Mental Library:
Your plan to create a "memory palace" is good. But I suggest:
1. **Understand the WHY**: Not just "AForm is abstract" but "AForm is abstract BECAUSE different forms need different actions"
2. **Build associations**: "Template Method Pattern" = AForm.execute() calling derived.executeAction()
3. **Practice recall**: Try to redraw the class diagram from memory

</ANSWER>

---

## Question 13 - Can we modify private members via returned reference?

<ANSWER>

### Your confusion clarified:

```cpp
std::string& Bureaucrat::getName(void) const {
    return this->_name;  // This won't compile!
}
```

**This code has TWO problems:**

1. **const member function returning non-const reference**: The function is `const` but tries to return a modifiable reference to a member. The compiler prevents this.

2. **If it compiled (without the trailing const):**
```cpp
std::string& Bureaucrat::getName(void) {  // Non-const function
    return this->_name;  // Returns alias to private member!
}

// External code could do:
bureaucrat.getName() = "hacked";  // Modifies _name directly!
```

### About the "function call stack" (correct term!):

You're right that the function call uses stack memory. But here's the key:

**Reference does NOT create a copy.**

```cpp
std::string& ref = bureaucrat.getName();
// ref IS the private member, not a copy
// The function returned, but ref still points to _name
// because _name lives in the Bureaucrat object, not the function's stack
```

### Lifetime visualization:
```
Stack                           Heap/Object
+-----------------+            +------------------+
| getName() frame |            | Bureaucrat obj   |
| (temporary)     |            | +-------------+  |
|                 |            | | _name       |<-------- ref points here
+-----------------+            | +-------------+  |
       ^                       +------------------+
       |
  This disappears                This persists
  when function returns          as long as object exists
```

### The safe pattern:
```cpp
const std::string& Bureaucrat::getName(void) const {
    return this->_name;
}
```

- Returns reference (efficient, no copy)
- `const` in return type: caller can't modify
- `const` method: this function promises not to modify the object

</ANSWER>

---

## Question 14 - Function overloading in C++ vs C

<ANSWER>

**Yes, function overloading is a C++ feature not available in C.**

### C++ Function Overloading:
```cpp
void Bureaucrat::incrementGrade(void);     // Version 1
void Bureaucrat::incrementGrade(int i);    // Version 2

b.incrementGrade();    // Calls version 1
c.incrementGrade(10);  // Calls version 2
```

### Why C can't do this:

**C uses only the function name for linking:**
```c
// In C, this creates a conflict:
void increment(void);
void increment(int i);  // ERROR: redefinition of 'increment'
```

**C++ uses "name mangling" - encodes parameters in function name:**
```cpp
// C++ internally sees these as different names:
void increment(void);   // Becomes: _Z9incrementv
void increment(int i);  // Becomes: _Z9incrementi
```

You can see this with `nm` command:
```bash
nm your_program | grep increment
# _Z9incrementv
# _Z9incrementi
```

### Overloading rules in C++:

Functions are **different** if they differ in:
- Number of parameters
- Type of parameters
- Order of parameter types

Functions are **NOT different** based on:
- Return type alone
- Parameter names

```cpp
int foo(int x);
float foo(int x);  // ERROR: only return type differs

int foo(int x);
int foo(int y);    // ERROR: same signature (names don't matter)

int foo(int x);
int foo(double x); // OK: different parameter type
```

</ANSWER>

---

## Question 15 - What headers for `try/catch`?

<ANSWER>

**No special header is needed for `try/catch` - it's a language feature.**

```cpp
// This works without any includes:
try {
    throw 42;
} catch (int e) {
    // handle
}
```

### Headers you MIGHT need:

| Header | When to use |
|--------|-------------|
| `<exception>` | For `std::exception` base class |
| `<stdexcept>` | For standard exceptions like `std::runtime_error`, `std::logic_error` |
| `<new>` | For `std::bad_alloc` (memory allocation failure) |

### Common usage:
```cpp
#include <exception>   // For std::exception
#include <stdexcept>   // For std::runtime_error

try {
    throw std::runtime_error("Something went wrong");
} catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

### For your Bureaucrat exceptions:
```cpp
#include <exception>  // Only this is needed

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
};
```

</ANSWER>

---

## Question 16 - Initialization list vs function body: what executes first?

<ANSWER>

**Initialization list ALWAYS executes before the function body.**

### Execution order:
```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)                      // Step 1: Initialize _name
    , _grade(Bureaucrat::lowestGrade)  // Step 2: Initialize _grade to 150
{
    // Step 3: Body executes
    if (grade < Bureaucrat::highestGrade)
        throw Bureaucrat::GradeTooHighException();  // Exception thrown here
    // ...
}
```

### What happens when exception is thrown in constructor body?

**The object is considered NOT fully constructed.**

```cpp
try {
    Bureaucrat b("Bad", 0);  // grade 0 is too high
} catch (...) {
    // Object 'b' does not exist here
    // But _name and _grade WERE initialized before the throw
}
```

### Memory cleanup:

When constructor throws:
1. Members that were initialized are destroyed (in reverse order)
2. Memory for the object is deallocated
3. No destructor is called (object never fully existed)

```cpp
class Demo {
    std::string a;  // Has constructor/destructor
    std::string b;
public:
    Demo() : a("first"), b("second") {
        throw std::runtime_error("oops");
    }
};

// When exception throws:
// 1. b's destructor called (reverse order)
// 2. a's destructor called
// 3. Memory freed
// Demo's destructor NOT called (wasn't fully constructed)
```

### Your code is safe:
```cpp
: _name(name), _grade(Bureaucrat::lowestGrade)
{
    if (grade < highestGrade) throw ...;
}
```

If exception throws, `_name` (a `std::string`) properly cleans itself up.

</ANSWER>

---

## Question 17 - How does `e.what()` work?

<ANSWER>

### The mechanism:

**1. Base class declares virtual `what()`:**
```cpp
// In <exception> header
class exception {
public:
    virtual const char* what() const throw();  // Returns "std::exception"
};
```

**2. Your class overrides it:**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too high!";  // Your custom message
    }
};
```

**3. Polymorphism in action:**
```cpp
try {
    throw Bureaucrat::GradeTooHighException();
} catch (std::exception& e) {  // Catches by BASE class reference
    std::cout << e.what();     // Calls DERIVED class's what()
}
```

### Why this works - Virtual dispatch:

```
+-----------------+
| std::exception  |  vtable: [what -> "std::exception"]
+-----------------+
        ^
        |
+-------------------+
|GradeTooHighExcept |  vtable: [what -> "Grade is too high!"]
+-------------------+
```

When you call `e.what()`:
1. Look up the vtable pointer in the object
2. Find the `what()` entry in vtable
3. Call that function

Since the actual object is `GradeTooHighException`, its vtable points to your override.

### Complete example:
```cpp
// Declaration
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what(void) const throw();
    };
};

// Implementation
const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

// Usage
try {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;  // Prints: "Grade is too high!"
}
```

</ANSWER>

---

## Question 18 - Two ways of using throw?

<ANSWER>

### The two syntaxes you showed:

```cpp
// With parentheses:
throw (Bureaucrat::GradeTooLowException());

// Without parentheses:
throw Bureaucrat::GradeTooLowException();
```

**Both are valid and equivalent!** Parentheses are optional.

### What you CAN throw:

```cpp
throw 42;                              // int
throw "error message";                 // const char*
throw std::runtime_error("message");   // Object
throw;                                 // Re-throw current exception (in catch block)
```

### Your `return` before `throw` is redundant:

```cpp
// This:
return (throw (Bureaucrat::GradeTooLowException()));  // Weird but compiles

// Should just be:
throw Bureaucrat::GradeTooLowException();  // No return needed
```

`throw` transfers control immediately - code after it never executes. Adding `return` before `throw` in a void function is pointless.

### Other C++ features with optional parentheses:

```cpp
sizeof x        // or sizeof(x)
return x        // or return(x)
throw x         // or throw(x)
new Type        // or new (Type)  -- placement new is different though
```

### Exception specification (related but different):

```cpp
void foo() throw();              // C++98: promises no exceptions
void foo() throw(std::exception); // C++98: may throw std::exception only
void foo() noexcept;             // C++11: promises no exceptions
```

</ANSWER>

---

## Question 19 - When and why to use try/catch?

<ANSWER>

### When to use try/catch - The "parking" analogy you wanted:

**Use try/catch when:**

| Situation | Example | Why |
|-----------|---------|-----|
| **Boundary crossing** | User input validation | External data can't be trusted |
| **Resource acquisition** | File operations, network | May fail due to external factors |
| **Object interaction** | Bureaucrat signs Form | Different objects have different rules |
| **Recovery is possible** | Try backup server | Can handle failure gracefully |

**DON'T use try/catch when:**

| Situation | Better approach |
|-----------|-----------------|
| Programmer error | Assert, fix the bug |
| Normal flow control | Use if/else |
| Every single function | Only at boundaries |

### The Pattern in ex02:

```cpp
// In main.cpp - the BOUNDARY where user creates objects
try {
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm form("garden");

    boss.signForm(form);      // Might fail
    boss.executeForm(form);   // Might fail

} catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

### Why Bureaucrat::signForm has its own try/catch:

```cpp
void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName();
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign because " << e.what();
    }
}
```

**The interaction between objects can fail:**
- Bureaucrat's grade might be too low
- Form might already be signed
- etc.

Bureaucrat handles this gracefully instead of crashing.

### Your "parking" intuition:

```
                    +-----------------+
                    |   main()        |
                    |  try/catch here |  <-- "Driveway" - main entry point
                    +-----------------+
                           |
              +------------+------------+
              |                         |
    +-----------------+       +-----------------+
    |   Bureaucrat    |       |     AForm       |
    | try/catch here  |       | throws errors   |
    +-----------------+       +-----------------+
           ^                         ^
           |                         |
    "Garage" - handles         "Neighbor's yard" -
    interactions gracefully    can reject parking
```

**Rules:**
1. Try at entry points (main, public interfaces)
2. Throw when something goes wrong
3. Catch where you can handle it meaningfully
4. Let it propagate if you can't handle it

</ANSWER>

---

## Question 20 - Is `else` needed before final assignment?

<ANSWER>

### Your two versions:

**With else:**
```cpp
if (grade < highestGrade)
    throw GradeTooHighException();
else if (grade > lowestGrade)
    throw GradeTooLowException();
else
    this->_grade = grade;
```

**Without else:**
```cpp
if (grade < highestGrade)
    throw GradeTooHighException();
else if (grade > lowestGrade)
    throw GradeTooLowException();
this->_grade = grade;  // No else
```

### They are functionally identical here!

Because `throw` transfers control immediately (never returns), if either condition is true, `this->_grade = grade` never executes.

### Why use `else` anyway?

1. **Explicit intent**: Makes it clear this is the "success" case
2. **Future-proofing**: If someone changes `throw` to something else
3. **Compiler optimization**: Some compilers generate slightly different code
4. **Style consistency**: Some style guides require it

### When removing `else` IS dangerous:

```cpp
// DANGEROUS without else:
if (condition)
    doSomething();  // Does NOT throw/return
else if (otherCondition)
    doOtherThing(); // Does NOT throw/return
doFinalThing();     // Executes even when conditions are true!

// SAFE without else:
if (condition)
    return;         // Control leaves function
else if (otherCondition)
    return;         // Control leaves function
doFinalThing();     // Only executes when both conditions false
```

### My recommendation:

For your specific case, both are correct. But for code clarity, I prefer:

```cpp
if (grade < highestGrade)
    throw GradeTooHighException();
if (grade > lowestGrade)    // Changed else if to if
    throw GradeTooLowException();
this->_grade = grade;
```

Why? The first condition's throw means we never reach the second check if it's true. Using just `if` makes this obvious. The `else` chain suggests mutual exclusivity, but `throw` already guarantees that.

</ANSWER>

---

## Question 21 - Why use initializer list default then reassign?

<ANSWER>

### The pattern you're asking about:

```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(Bureaucrat::lowestGrade)  // Initialize to default
{
    // ... validation ...
    this->_grade = grade;  // Then set actual value
}
```

### Why initialize to `lowestGrade` first?

**Reason 1: Const members MUST be initialized**
```cpp
class Bureaucrat {
    int const _grade;  // If const, MUST use initializer list!
};
```
Wait, but then you can't reassign in body... This code suggests `_grade` is NOT const.

**Reason 2: Safe default**

If validation throws, what value does `_grade` have?
```cpp
: _name(name), _grade(grade)  // Use parameter directly
{
    if (grade < 1) throw ...;  // Throws, but _grade is already invalid!
}
```

vs

```cpp
: _name(name), _grade(150)  // Safe default
{
    if (grade < 1) throw ...;  // Throws, _grade has valid value (150)
    _grade = grade;           // Only set if valid
}
```

This is **defensive programming** - even in error cases, the object has a valid state.

**Reason 3: Your observation about scope**

```cpp
_grade   // Member variable (the object's data)
grade    // Parameter (what user passed in)
```

Clear naming prevents confusion. Some prefer:
```cpp
Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)  // Same name, different scope
```

### Better mental model:

Think of initialization in two phases:

```
Phase 1 (Initializer List):     Phase 2 (Body):
"Build the scaffolding"          "Validate and customize"

_name = name ✓                   Check grade range
_grade = 150 (safe default) ✓    If valid: _grade = grade
                                 If invalid: throw
```

### Alternative design (arguably cleaner):

```cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(validateGrade(grade))  // Validate IN initializer
{ }

int Bureaucrat::validateGrade(int grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    return grade;
}
```

</ANSWER>

---

## Question 22 - Building a memory palace for CPP05

<ANSWER>

**Your approach is not silly at all - it's evidence-based learning!**

### Spaced Repetition + Memory Palace = Effective

The schedule you mentioned (1 day, 3 days, 5 days) aligns with spaced repetition research.

### Suggested Memory Palace Structure for CPP05:

**Location: Your school building**

```
Entrance (ex00): Bureaucrat alone
├── Guard desk = Bureaucrat class
├── Grade badge = _grade (1-150)
├── Name tag = _name (const)
└── Exception warnings = GradeTooHigh/Low

Hallway (ex01): Bureaucrat + Form interaction
├── Bulletin board = Form class
├── Signature line = beSigned()
├── Sign-in sheet = signForm()
└── Form requirements = gradeToSign, gradeToExecute

Main Hall (ex02): Abstract Forms + Polymorphism
├── Abstract sculpture = AForm (can't touch = can't instantiate)
├── Three doors = Three derived form types
│   ├── Garden door = ShrubberyCreationForm
│   ├── Robot door = RobotomyRequestForm
│   └── President's door = PresidentialPardonForm
├── Security check = execute() checks before executeAction()
└── Different actions behind each door = polymorphism

Office (ex03): Intern creates forms
├── Intern desk = Intern class
├── Form factory = makeForm()
└── The pattern continues...
```

### Chunks to memorize:

1. **Exception Pattern**:
   - Nested class
   - Inherits std::exception
   - Override what()

2. **Orthodox Canonical Form**:
   - Default constructor
   - Copy constructor
   - Assignment operator
   - Destructor

3. **Abstract Class Pattern**:
   - Pure virtual function (= 0)
   - Protected section for derived classes
   - Virtual destructor

4. **Template Method Pattern** (ex02's core):
   - Public function calls protected virtual
   - Base handles common logic
   - Derived handles specific action

### Review Schedule:

| Day | Activity |
|-----|----------|
| Day 0 | Study and create palace |
| Day 1 | Walk through palace, recall details |
| Day 3 | Redraw class diagram from memory |
| Day 7 | Code a mini version without looking |
| Day 14 | Teach someone else |
| Day 30 | Review, should be automatic now |

This is an excellent learning strategy. Keep doing it!

</ANSWER>

---

## Summary

These 22 questions cover essential C++98 concepts:

1. **const correctness** (Q1, 2, 6, 7)
2. **References and memory** (Q2, 13)
3. **Polymorphism and inheritance** (Q3, 9, 10, 11)
4. **Virtual functions** (Q4, 10, 11)
5. **Exception handling** (Q4, 5, 15, 17, 18, 19)
6. **Access specifiers** (Q8)
7. **C vs C++ differences** (Q14)
8. **Constructor mechanics** (Q16, 20, 21)
9. **Problem-solving strategies** (Q12, 22)

Keep asking questions like these - understanding the "why" makes you a better programmer!
