#pragma once

#include <string>
namespace BookMyShow::Model {

   class User {
   private:
      int id;
      std::string name;
      std::string email;
      std::string phoneNumber;

   public:
      explicit User(int id, std::string name, std::string email, std::string phoneNumber);

      // Getters
      int getId() const;
      const std::string& getName() const;
      const std::string& getEmail() const;
      const std::string& getPhoneNumber() const;

      // Setters
      void setId(int id);
      void setName(std::string name);
      void setEmail(std::string email);
      void setPhoneNumber(std::string phoneNumber);
   };
}