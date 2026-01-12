#include "Serializer.hpp"
#include <iostream>

int main() {
	Data original;
	original.id = 42;
	original.name = "Test Data";

	std::cout << "Original pointer: " << &original << std::endl;
	std::cout << "Original data: id=" << original.id << ", name=" << original.name << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* result = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << result << std::endl;
	std::cout << "Deserialized data: id=" << result->id << ", name=" << result->name << std::endl;

	if (result == &original)
		std::cout << "Success: pointers match!" << std::endl;
	else
		std::cout << "Error: pointers don't match!" << std::endl;

	return 0;
}
