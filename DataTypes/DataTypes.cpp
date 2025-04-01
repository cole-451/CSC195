#include <iostream>
using namespace std;

int main() {
	string name;
	char initial;
	short age;
	bool isAdult;
	unsigned int zipcode;
	float wage;
	short daysWorked;
	float hoursWorkedPerDay[7];

	const float TAX = 0.1f; // 10% tax rate

	cout << "Give me a name!" << endl;
	cin >> name;

	cout << "Initial?" << endl;
	cin >> initial;

	cout << "Age?" << endl;
	cin >> age;
	isAdult = (age >= 18);

	cout << "Zipcode?" << endl;
	cin >> zipcode;

	cout << "Hourly wage?" << endl;
	cin >> wage;

	cout << "Number of working days (max 7)?" << endl;
	cin >> daysWorked;

	float totalHours = 0;
	for (int i = 0; i < daysWorked; i++) {
		cout << "Enter hours worked for day " + (i+1) << endl;
		cin >> hoursWorkedPerDay[i];

		totalHours += hoursWorkedPerDay[i];
	}

	float grossIncome = totalHours * wage;
	float taxAmount = grossIncome * TAX;
	float netIncome = grossIncome - taxAmount;

	cout << "\nEmployee Payroll Summary\n";
	cout << "-------------------------\n";
	cout << "Name: " << name << " " << initial << ".\n";
	cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")\n";
	cout << "Zipcode: " << zipcode << "\n";
	cout << "Hourly Wage: $" << wage << " per hour\n";
	cout << "Total Hours Worked: " << totalHours << " hours\n";
	cout << "Gross Income: $" << grossIncome << "\n";
	cout << "Tax Amount: $" << taxAmount << "\n";
	cout << "Net Income: $" << netIncome << "\n";
}