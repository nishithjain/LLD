#pragma once
namespace BookMyShow::Common {

   enum class TicketStatus {
      CONFIRMED,
      CANCELLED,
      WAITING,
      PENDING,   // Payment in progress
      FAILED     // Payment failed or booking failed
   };
}