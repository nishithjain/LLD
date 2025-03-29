#pragma once

#include "PaymentMode.h"
#include <string>
#include <chrono>

namespace BookMyShow::DTO {

   struct PaymentDTO {
   public:
      int id;
      double amount;
      Model::PaymentMode mode;
      std::chrono::system_clock::time_point paymentTime;
      std::string transactionId;
   };
}
