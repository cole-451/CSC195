#include <iostream>
#include "Student.h"

struct Person
{
std::string name;
int age;
void f(){}
};


int main() {
	Student student("Kevin");
	Student setName("Clark");
	Person person;
	person.age = 19;
	student.Write();
	f();
	std::cout << "Hello, World!" << std::endl;
	std::cout << "muahahaha i now know how to use git" << std::endl;

	unsigned int i = -23; // if a negative is unsigned, it will overflow to the next positive number
	char lol = 67;
	std::cout << &i; // how to see the ID (its hex!!!)
	std::cout << i;
	std::cout << sizeof(int) << std::endl;
	return 0;
}






