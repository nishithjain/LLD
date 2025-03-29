#pragma once

#include <string>
#include "SeatType.h"

namespace BookMyShow::DTO {

   struct SeatDTO {
   public:
      int id;
      std::string seatNumber;
      Model::SeatType seatType;
      int screenId; // Reference to the screen this seat belongs to
   };
}
