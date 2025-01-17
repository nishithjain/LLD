#pragma once
#include <string>

class Employee
{
	std::string employee_id_;
	std::string first_name_;
	std::string last_name_;
	std::string date_of_birth_;
	std::string gender_;
	int age_ = 0;
	std::string nationality_;
	std::string address_;
	std::string phone_number_;
	std::string email_;

public:
	class EmployeeBuilder
	{
		std::string employee_id_;
		std::string first_name_;
		std::string last_name_;
		std::string date_of_birth_;
		std::string gender_;
		int age_ = 0;
		std::string nationality_;
		std::string address_;
		std::string phone_number_;
		std::string email_;
	public:
		std::string GetEmployeeId() const;
		EmployeeBuilder& SetEmployeeId(const std::string& employee_id);
		std::string GetFirstName() const;
		EmployeeBuilder& SetFirstName(const std::string& first_name);
		std::string GetLastName() const;
		EmployeeBuilder& SetLastName(const std::string& last_name);
		std::string GetDateOfBirth() const;
		EmployeeBuilder& SetDateOfBirth(const std::string& date_of_birth);
		std::string GetGender() const;
		EmployeeBuilder& SetGender(const std::string& gender);
		int GetAge() const;
		EmployeeBuilder& SetAge(const int age);
		std::string GetNationality() const;
		EmployeeBuilder& SetNationality(const std::string& nationality);
		std::string GetAddress() const;
		EmployeeBuilder& SetAddress(const std::string& address);
		std::string GetPhoneNumber() const;
		EmployeeBuilder& SetPhoneNumber(const std::string& phone_number);
		std::string GetEmail() const;
		EmployeeBuilder& SetEmail(const std::string& email);

		Employee Build() const;
	};
	explicit Employee(const EmployeeBuilder& emp_builder);
	void PrintEmployeeDetails() const;
};


