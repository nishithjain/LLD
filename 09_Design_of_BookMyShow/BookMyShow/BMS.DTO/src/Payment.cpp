#include "Payment.h"
#include "Ticket.h" // Now include Ticket since it's used in function implementations

namespace BookMyShow::Model {

   Payment::Payment(int id, int transactionId, double amount, PaymentStatus status,
      std::weak_ptr<Ticket> ticket,
      std::chrono::system_clock::time_point transactionTime) 
      : id(id), transactionId(transactionId), amount(amount), status(status),
      ticket(ticket), transactionTime(transactionTime) {
   }

   // Getters
   int Payment::getId() const {
      return id;
   }

   int Payment::getTransactionId() const {
      return transactionId;
   }

   double Payment::getAmount() const {
      return amount;
   }

   PaymentStatus Payment::getStatus() const {
      return status;
   }

   std::weak_ptr<Ticket> Payment::getTicket() const {
      return ticket;
   }

   std::chrono::system_clock::time_point Payment::getTransactionTime() const {
      return transactionTime;
   }

   // Setters
   void Payment::setId(int id) {
      this->id = id;
   }

   void Payment::setTransactionId(int transactionId) {
      this->transactionId = transactionId;
   }

   void Payment::setAmount(double amount) {
      this->amount = amount;
   }

   void Payment::setStatus(PaymentStatus status) {
      this->status = status;
   }

   void Payment::setTicket(std::weak_ptr<Ticket> ticket) {
      this->ticket = ticket;
   }

   void Payment::setTransactionTime(std::chrono::system_clock::time_point transactionTime) {
      this->transactionTime = transactionTime;
   }
}