// Test file to understand pointer vs reference
#include <iostream>

class Bureaucrat {
public:
    Bureaucrat(std::string name) : _name(name) {}
    std::string getName() const { return _name; }
private:
    std::string _name;
};

// Version 1: Takes POINTER (wrong for operator<<)
void printWithPointer(Bureaucrat const* ptr) {
    std::cout << "Pointer version: " << ptr->getName() << std::endl;
    //                                     ^^ use arrow!
}

// Version 2: Takes REFERENCE (correct for operator<<)
void printWithReference(Bureaucrat const& ref) {
    std::cout << "Reference version: " << ref.getName() << std::endl;
    //                                      ^^ use dot!
}

// Correct operator<< (uses REFERENCE)
std::ostream& operator<<(std::ostream& os, Bureaucrat const& obj) {
    os << "Bureaucrat: " << obj.getName();
    return os;
}

int main() {
    Bureaucrat b("Alice");

    // Test pointer version
    printWithPointer(&b);  // Need & to pass address!
    //               ^

    // Test reference version
    printWithReference(b);  // Pass directly!
    //                 ^

    // Test operator<<
    std::cout << b << std::endl;  // Natural syntax!
    //           ^
    //           No & needed! Reference handles it!

    // This shows the difference:
    std::cout << "\nDemonstration:\n";
    std::cout << "Address of b: " << &b << std::endl;

    Bureaucrat* ptr = &b;
    std::cout << "ptr holds: " << ptr << " (same address!)" << std::endl;
    std::cout << "ptr->getName(): " << ptr->getName() << std::endl;

    Bureaucrat& ref = b;
    std::cout << "ref.getName(): " << ref.getName() << std::endl;
    std::cout << "Address of ref: " << &ref << " (same as b!)" << std::endl;

    return 0;
}
