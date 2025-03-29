#include "User.h"

namespace BookMyShow::Model {

   User::User(int id, std::string name, std::string email, std::string phoneNumber)
      : id(id), name(std::move(name)), email(std::move(email)), 
      phoneNumber(std::move(phoneNumber)) {
   }

   int User::getId() const {
      return id;
   }

   const std::string& User::getName() const {
      return name;
   }

   const std::string& User::getEmail() const {
      return email;
   }

   const std::string& User::getPhoneNumber() const {
      return phoneNumber;
   }

   void User::setId(int id) {
      this->id = id;
   }

   void User::setName(std::string name) {
      this->name = std::move(name);
   }

   void User::setEmail(std::string email) {
      this->email = std::move(email);
   }

   void User::setPhoneNumber(std::string phoneNumber) {
      this->phoneNumber = std::move(phoneNumber);
   }
}