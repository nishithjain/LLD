#pragma once

#include <string>

namespace BookMyShow::DTO {

   struct UserDTO {
   public:
      int id;
      std::string name;
      std::string email;
      std::string phoneNumber;
   };
}
