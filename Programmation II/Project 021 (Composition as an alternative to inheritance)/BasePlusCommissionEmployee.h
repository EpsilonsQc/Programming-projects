// Composition as an alternative to inheritance
// BasePlusCommissionEmployee.h (Class definition | Function prototypes and data members)

#pragma once

#include <string>
#include "CommissionEmployee.h" // CommissionEmployee class declaration

class BasePlusCommissionEmployee 
{
public:
	BasePlusCommissionEmployee(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0.0, double = 0.0);

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary

	double earnings() const; // calculate earnings
	std::string toString() const; // create string representation

	void setFirstName(const std::string&); // set first name
	std::string getFirstName() const; // return first name

	void setLastName(const std::string&);  // set last name
	std::string getLastName() const; // return last name

	void setSocialSecurityNumber(const std::string&); // set SSN
	std::string getSocialSecurityNumber() const; // get SSN

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	void setCommissionRate(double); // set commission rate
	double getCommissionRate() const; // return commission rate

private:
	CommissionEmployee CommissionEmployeeObj;
	double baseSalary; // base salary
};