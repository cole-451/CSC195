#include "Employee.h"
#include <iostream>

int main()
{
    int numOfEmployees;
    std::cout << "Number of Employees (max 5):";
    std::cin >> numOfEmployees;

    if (numOfEmployees > 5) {
        numOfEmployees = 5;
    }

        Employee employees[5]; //since Employee is an object, we can make an array of said objects.

        for (int i = 0; i < numOfEmployees; i++) {
            std::cout << "Enter details for Employee number " << (i + 1) << ":\n";
            employees[i].Read();

        }

        std::cout << "\n Payroll Report \n";
        for (int i = 0; i < numOfEmployees; i++) {
            employees[i].Write();
        }
        return 0;
        
    

}
