#pragma once
#include <string>

//header files are for declaration

void f();
class Student {
public:
	Student(){}
	Student(std::string name) { this->name = name; }
	
	void Write();
	std::string getName() { return name; }
	void setName(std::string name) {  this->name = name; }
private:
	std::string name;
	unsigned int age;

};

class RockBandController {
public:
	void Strum();
	void WhammyDistort();

private:
	std::string modelName = "Riffmaster";
	bool isActive = false;
	int numberOfFrets = 10;

};

class XboxRemote {
public:
	void TurnOnXbox();
	bool isConnectedToXbox();

private:
	std::string color = "black";
	bool isActive = false;
	int numberOfButtons = 27;

};
