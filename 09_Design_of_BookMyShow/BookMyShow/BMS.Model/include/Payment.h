#pragma once

#include <memory>
#include <chrono>
#include "PaymentStatus.h"

namespace BookMyShow::Model {
   using namespace BookMyShow::Common;

   class Ticket; // Forward declaration to avoid cyclic dependency

   class Payment {
   private:
      int id;
      int transactionId;
      double amount;
      PaymentStatus status;
      std::weak_ptr<Ticket> ticket;
      std::chrono::system_clock::time_point transactionTime;

   public:
      Payment(int id, int transactionId, double amount, PaymentStatus status,
         std::weak_ptr<Ticket> ticket,
         std::chrono::system_clock::time_point transactionTime);

      // Getters
      int getId() const;
      int getTransactionId() const;
      double getAmount() const;
      PaymentStatus getStatus() const;
      std::weak_ptr<Ticket> getTicket() const;
      std::chrono::system_clock::time_point getTransactionTime() const;

      // Setters
      void setId(int id);
      void setTransactionId(int transactionId);
      void setAmount(double amount);
      void setStatus(PaymentStatus status);
      void setTicket(std::weak_ptr<Ticket> ticket);
      void setTransactionTime(std::chrono::system_clock::time_point transactionTime);
   };
}