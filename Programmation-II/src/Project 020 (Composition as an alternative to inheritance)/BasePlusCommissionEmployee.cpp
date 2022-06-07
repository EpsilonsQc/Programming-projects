// Composition as an alternative to inheritance
// BasePlusCommissionEmployee.cpp (Implementation file | Constructor and member functions definitions)

#include "BasePlusCommissionEmployee.h" // BasePlusCommissionEmployee class definition
#include <stdexcept>
#include <sstream>

using namespace std;

// CTOR
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary) :
	CommissionEmployeeObj(first, last,  ssn, sales, rate), // explicitly call base-class CTOR
	baseSalary(salary)
{
	// Empty CTOR body
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary < 0.0)
	{
		throw invalid_argument("Salary must be >= 0.0");
	}
	
	baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
	return getBaseSalary() + CommissionEmployeeObj.earnings();
}

// return string reprensetation of BasePlusCommissionEmployee object
string BasePlusCommissionEmployee::toString() const
{
	ostringstream output;
	output << "Base-salaried " << CommissionEmployeeObj.toString() << "\nBase salary: " << getBaseSalary();

	return output.str();
}

void BasePlusCommissionEmployee::setFirstName(const std::string& firstName) 
{
	CommissionEmployeeObj.setFirstName(firstName);
}

std::string BasePlusCommissionEmployee::getFirstName() const 
{
	return CommissionEmployeeObj.getFirstName();
}

void BasePlusCommissionEmployee::setLastName(const std::string& lastName) 
{
	CommissionEmployeeObj.setLastName(lastName);
}

std::string BasePlusCommissionEmployee::getLastName() const 
{
	return CommissionEmployeeObj.getLastName();
}

void BasePlusCommissionEmployee::setSocialSecurityNumber(const std::string& ssn) 
{
	CommissionEmployeeObj.setLastName(ssn);
}

std::string BasePlusCommissionEmployee::getSocialSecurityNumber() const 
{
	return CommissionEmployeeObj.getSocialSecurityNumber();
}

void BasePlusCommissionEmployee::setGrossSales(double grossSales) 
{
	CommissionEmployeeObj.setGrossSales(grossSales);
}

double BasePlusCommissionEmployee::getGrossSales() const
{
	return CommissionEmployeeObj.getGrossSales();
}

void BasePlusCommissionEmployee::setCommissionRate(double commissionRate) 
{
	CommissionEmployeeObj.setCommissionRate(commissionRate);
}

double BasePlusCommissionEmployee::getCommissionRate() const
{
	return CommissionEmployeeObj.getCommissionRate();
}