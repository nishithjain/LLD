#pragma once

#include <string>

namespace BookMyShow::DTO {

   struct ScreenDTO {
   public:
      int id;
      std::string name;
      int totalSeats;
      int theaterId; // To reference the parent theater
   };
}
