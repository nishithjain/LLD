#pragma once
#include <memory>
#include <string>

class Intern
{
	std::string name_;
    int age_;
    std::string university_name_;
    std::string gender_;
    std::string phone_number_;
    std::string email_;
    std::string batch_name_;        // Common for a batch
    std::string batch_start_date_;  // Common for a batch
    std::string batch_end_date_;    // Common for a batch
    std::string batch_duration_;    // Common for a batch
    std::string batch_location_;    // Common for a batch
public:
    virtual ~Intern() = default;
    Intern(std::string batch_name, std::string start_date,
           std::string end_date, std::string duration,
           std::string location);
    [[nodiscard]] std::unique_ptr<Intern> clone() const;
    void Display() const;

    void SetName(const std::string& name);
    void SetAge(int age);
    void SetUniversity(const std::string& university);
    void SetGender(const std::string& gender);
    void SetPhoneNumber(const std::string& phone);
    void SetEmail(const std::string& email);
};

