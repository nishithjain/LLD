#pragma once
namespace BookMyShow::Common {

   enum class SeatStatus {
      AVAILABLE,     // Seat can be selected
      BOOKED,        // Seat is confirmed and paid
      LOCKED,        // Seat is temporarily held (e.g., during checkout or payment window)
      CANCELLED,     // In case of refunds
      MAINTENANCE,   // Unusable temporarily (broken seat, etc.)
      RESERVED,      // For bulk or partner booking
   };
}