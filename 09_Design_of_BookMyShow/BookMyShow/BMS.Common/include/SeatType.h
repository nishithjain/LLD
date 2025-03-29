#pragma once
namespace BookMyShow::Common {

   enum class SeatType {
      VIP,
      GOLD,
      PLATINUM,
      REGULAR,
      INVALID,   // For invalid seats or empty spaces
      WALKWAY    // For walkways or gaps
   };
}