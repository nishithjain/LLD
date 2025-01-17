#include "Intern.h"
#include <iostream>

Intern::Intern(std::string batch_name, std::string start_date, std::string end_date, std::string duration,
               std::string location)
	: age_(0), batch_name_(std::move(batch_name)), batch_start_date_(std::move(start_date)),
	  batch_end_date_(std::move(end_date)), batch_duration_(std::move(duration)),
	  batch_location_(std::move(location))
{
}

std::unique_ptr<Intern> Intern::clone() const
{
    return std::make_unique<Intern>(*this);
}

void Intern::Display() const
{
    std::cout << "Intern Details:" << '\n';
    std::cout << "Name: " << name_
        << "\nAge: " << age_
        << "\nUniversity: " << university_name_
        << "\nGender: " << gender_
        << "\nPhone: " << phone_number_
        << "\nEmail: " << email_
        << '\n';

    std::cout << "Batch Details:" << '\n';
    std::cout << "Batch Name: " << batch_name_
        << "\nStart Date: " << batch_start_date_
        << "\nEnd Date: " << batch_end_date_
        << "\nDuration: " << batch_duration_
        << "\nLocation: " << batch_location_
        << '\n';
}

void Intern::SetName(const std::string& name)
{
    name_ = name;
}

void Intern::SetAge(int age)
{
    age_ = age;
}

void Intern::SetUniversity(const std::string& university)
{
    university_name_ = university;
}

void Intern::SetGender(const std::string& gender)
{
    gender_ = gender;
}

void Intern::SetPhoneNumber(const std::string& phone)
{
    phone_number_ = phone;
}

void Intern::SetEmail(const std::string& email)
{
    email_ = email;
}
