// Demonstration: Why testing assignment operator is CRITICAL
#include <iostream>
#include <string>

// Example 1: BAD implementation (no self-assignment check)
class BadBureaucrat {
private:
    std::string _name;
    int* _gradePtr;  // Using pointer to show the danger

public:
    BadBureaucrat(std::string name, int grade) : _name(name) {
        _gradePtr = new int(grade);
        std::cout << "BadBureaucrat " << _name << " created\n";
    }

    ~BadBureaucrat() {
        std::cout << "BadBureaucrat " << _name << " destroyed\n";
        delete _gradePtr;
    }

    // BAD: No self-assignment check!
    BadBureaucrat& operator=(BadBureaucrat const& source) {
        std::cout << "BAD assignment: " << _name << " = " << source._name << "\n";

        // DANGER: What if 'this' == &source?
        delete _gradePtr;  // Delete our memory
        _name = source._name;
        _gradePtr = new int(*source._gradePtr);  // Copy from source
        // If source is 'this', we just copied from DELETED memory!

        return *this;
    }

    int getGrade() const { return *_gradePtr; }
    std::string getName() const { return _name; }
};

// Example 2: GOOD implementation (with self-assignment check)
class GoodBureaucrat {
private:
    std::string _name;
    int* _gradePtr;

public:
    GoodBureaucrat(std::string name, int grade) : _name(name) {
        _gradePtr = new int(grade);
        std::cout << "GoodBureaucrat " << _name << " created\n";
    }

    ~GoodBureaucrat() {
        std::cout << "GoodBureaucrat " << _name << " destroyed\n";
        delete _gradePtr;
    }

    // GOOD: Check for self-assignment!
    GoodBureaucrat& operator=(GoodBureaucrat const& source) {
        std::cout << "GOOD assignment: " << _name << " = " << source._name << "\n";

        if (this != &source) {  // CRITICAL CHECK!
            delete _gradePtr;
            _name = source._name;
            _gradePtr = new int(*source._gradePtr);
        }
        else {
            std::cout << "  → Self-assignment detected, skipping!\n";
        }

        return *this;
    }

    int getGrade() const { return *_gradePtr; }
    std::string getName() const { return _name; }
};

int main() {
    std::cout << "═══════════════════════════════════════\n";
    std::cout << "TEST 1: Normal Assignment (BAD version)\n";
    std::cout << "═══════════════════════════════════════\n";
    {
        BadBureaucrat b1("Alice", 42);
        BadBureaucrat b2("Bob", 100);

        std::cout << "\nBefore assignment:\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";

        b1 = b2;  // Normal assignment

        std::cout << "After assignment:\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";
    }

    std::cout << "\n═══════════════════════════════════════\n";
    std::cout << "TEST 2: Self-Assignment (BAD version)\n";
    std::cout << "═══════════════════════════════════════\n";
    {
        BadBureaucrat b("Carol", 50);

        std::cout << "\nBefore self-assignment:\n";
        std::cout << "  b: " << b.getName() << " (grade: " << b.getGrade() << ")\n";

        std::cout << "\nAttempting self-assignment b = b...\n";
        b = b;  // Self-assignment - DANGER!

        std::cout << "After self-assignment:\n";
        try {
            std::cout << "  b: " << b.getName() << " (grade: " << b.getGrade() << ")\n";
        }
        catch (...) {
            std::cout << "  ❌ CRASH! Undefined behavior!\n";
        }
    }

    std::cout << "\n═══════════════════════════════════════\n";
    std::cout << "TEST 3: Normal Assignment (GOOD version)\n";
    std::cout << "═══════════════════════════════════════\n";
    {
        GoodBureaucrat b1("David", 42);
        GoodBureaucrat b2("Eve", 100);

        std::cout << "\nBefore assignment:\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";

        b1 = b2;

        std::cout << "After assignment:\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";
    }

    std::cout << "\n═══════════════════════════════════════\n";
    std::cout << "TEST 4: Self-Assignment (GOOD version)\n";
    std::cout << "═══════════════════════════════════════\n";
    {
        GoodBureaucrat b("Frank", 50);

        std::cout << "\nBefore self-assignment:\n";
        std::cout << "  b: " << b.getName() << " (grade: " << b.getGrade() << ")\n";

        std::cout << "\nAttempting self-assignment b = b...\n";
        b = b;  // Self-assignment - SAFE!

        std::cout << "After self-assignment:\n";
        std::cout << "  b: " << b.getName() << " (grade: " << b.getGrade() << ")\n";
        std::cout << "  ✅ No crash! Handled safely!\n";
    }

    std::cout << "\n═══════════════════════════════════════\n";
    std::cout << "TEST 5: Assignment Chaining\n";
    std::cout << "═══════════════════════════════════════\n";
    {
        GoodBureaucrat b1("George", 10);
        GoodBureaucrat b2("Helen", 50);
        GoodBureaucrat b3("Iris", 100);

        std::cout << "\nBefore: b1 = b2 = b3\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";
        std::cout << "  b3: " << b3.getName() << " (grade: " << b3.getGrade() << ")\n";

        b1 = b2 = b3;  // Chained assignment

        std::cout << "\nAfter: b1 = b2 = b3\n";
        std::cout << "  b1: " << b1.getName() << " (grade: " << b1.getGrade() << ")\n";
        std::cout << "  b2: " << b2.getName() << " (grade: " << b2.getGrade() << ")\n";
        std::cout << "  b3: " << b3.getName() << " (grade: " << b3.getGrade() << ")\n";
        std::cout << "  ✅ All three should be Iris (100)!\n";
    }

    return 0;
}
