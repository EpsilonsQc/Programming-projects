// Composition as an alternative to inheritance
// Main.cpp (Main function | Program execution begins and ends there) 

#include "CommissionEmployee.h" // CommissionEmployee class definition
#include "BasePlusCommissionEmployee.h" // BasePlusCommissionEmployee class definition
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "###############################################" << endl;

	// instantiate CommissionEmployee object
	CommissionEmployee employee{ "Sue", "Jones", "222-222-222", 10000, .06 };

	// get commission employee data
	cout << "\nEmployee information obtained by get functions:"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is " << employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommision rate is " << employee.getCommissionRate() << endl;

	employee.setGrossSales(8000); // set gross sales
	employee.setCommissionRate(.1); // set commission rate

	cout << "\nUpdated employee information from function to String:\n" << employee.toString();

	// display the commission employee's earning
	cout << "\nEmployee's earnings: $" << employee.earnings() << endl << endl;
	cout << "###############################################" << endl;

	// instantiate BasePlusCommissionEmployee object
	BasePlusCommissionEmployee basePlusEmployeeObj{ "Bob", "Lewis", "333-333-333", 5000, .04, 300 };

	// get base plus commission employee data
	cout << "\nEmployee information obtained by get functions:"
		 << "\nFirst name is " << basePlusEmployeeObj.getFirstName()
		 << "\nLast name is " << basePlusEmployeeObj.getLastName()
		 << "\nSocial security number is " << basePlusEmployeeObj.getSocialSecurityNumber()
		 << "\nGross sales is " << basePlusEmployeeObj.getGrossSales()
		 << "\nCommision rate is " << basePlusEmployeeObj.getCommissionRate()
		 << "\nBase salary is " << basePlusEmployeeObj.getBaseSalary() << endl;
		
	basePlusEmployeeObj.setBaseSalary(1000); // set base salary

	cout << "\nUpdated employee information from function to String:\n" << basePlusEmployeeObj.toString();

	// display the base plus commission employee's earning
	cout << "\nBase plus commission employee's earnings: $" << basePlusEmployeeObj.earnings() << endl << endl;
	cout << "###############################################" << endl << endl;

	system("pause");

	return 0;
}