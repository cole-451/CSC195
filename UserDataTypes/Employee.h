#pragma once
#include <iostream>
#include <string>

class Employee { // possibly an interface or abstract class?
public:
    void Read();
    void Write();

private:
    std::string name; // REMINDER: if you didn't put "using namespace std;", you need to add std:: in front of cin and cout commands too!
    short age;
    unsigned int zipcode;
    float wage;
    float hoursWorked;
    static const float TAX;


};