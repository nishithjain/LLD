#include "Employee.h"

#include <iostream>
#include <stdexcept>

Employee::Employee(const EmployeeBuilder& emp_builder)
{
	if (emp_builder.GetFirstName().empty() || emp_builder.GetLastName().empty())
	{
		throw std::invalid_argument("First and last names are required.");
	}
	if (emp_builder.GetAge() <= 21) {
		throw std::invalid_argument("Age must be greater than 21.");
	}
	if (emp_builder.GetPhoneNumber().empty()) {
		throw std::invalid_argument("Phone number is required.");
	}
	if (emp_builder.GetNationality() != "Indian") {
		throw std::invalid_argument("Only Indian nationality is allowed.");
	}

	// After validation, we can create Employee object...
	this->employee_id_ = emp_builder.GetEmployeeId();
	this->first_name_ = emp_builder.GetFirstName();
	this->last_name_ = emp_builder.GetLastName();
	this->date_of_birth_ = emp_builder.GetDateOfBirth();
	this->gender_ = emp_builder.GetGender();
	this->age_ = emp_builder.GetAge();
	this->nationality_ = emp_builder.GetNationality();
	this->address_ = emp_builder.GetAddress();
	this->phone_number_ = emp_builder.GetPhoneNumber();
	this->email_ = emp_builder.GetEmail();
}

void Employee::PrintEmployeeDetails() const
{
	std::cout << "Employee ID: " << employee_id_ << "\n"
		<< "Name: " << first_name_ << " " << last_name_ << "\n"
		<< "Date of Birth: " << date_of_birth_ << "\n"
		<< "Gender: " << gender_ << "\n"
		<< "Age: " << age_ << "\n"
		<< "Nationality: " << nationality_ << "\n"
		<< "Address: " << address_ << "\n"
		<< "Phone Number: " << phone_number_ << "\n"
		<< "Email: " << email_ << std::endl;
}

std::string Employee::EmployeeBuilder::GetEmployeeId() const
{
	return employee_id_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetEmployeeId(const std::string& employee_id)
{
	employee_id_ = employee_id;
	return *this;
}

std::string Employee::EmployeeBuilder::GetFirstName() const
{
	return first_name_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetFirstName(const std::string& first_name)
{
	first_name_ = first_name;
	return *this;
}

std::string Employee::EmployeeBuilder::GetLastName() const
{
	return last_name_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetLastName(const std::string& last_name)
{
	last_name_ = last_name;
	return *this;
}

std::string Employee::EmployeeBuilder::GetDateOfBirth() const
{
	return date_of_birth_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetDateOfBirth(const std::string& date_of_birth)
{
	date_of_birth_ = date_of_birth;
	return *this;
}

std::string Employee::EmployeeBuilder::GetGender() const
{
	return gender_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetGender(const std::string& gender)
{
	gender_ = gender;
	return *this;
}

int Employee::EmployeeBuilder::GetAge() const
{
	return age_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetAge(const int age)
{
	age_ = age;
	return *this;
}

std::string Employee::EmployeeBuilder::GetNationality() const
{
	return nationality_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetNationality(const std::string& nationality)
{
	nationality_ = nationality;
	return *this;
}

std::string Employee::EmployeeBuilder::GetAddress() const
{
	return address_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetAddress(const std::string& address)
{
	address_ = address;
	return *this;
}

std::string Employee::EmployeeBuilder::GetPhoneNumber() const
{
	return phone_number_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetPhoneNumber(const std::string& phone_number)
{
	phone_number_ = phone_number;
	return *this;
}

std::string Employee::EmployeeBuilder::GetEmail() const
{
	return email_;
}

Employee::EmployeeBuilder& Employee::EmployeeBuilder::SetEmail(const std::string& email)
{
	email_ = email;
	return *this;
}

Employee Employee::EmployeeBuilder::Build() const
{
	return Employee(*this);
}
