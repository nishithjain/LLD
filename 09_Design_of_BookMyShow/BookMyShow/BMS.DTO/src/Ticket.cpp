#include "Ticket.h"

namespace BookMyShow::Model {

   Ticket::Ticket(int id, std::shared_ptr<Show> show,
      std::vector<std::shared_ptr<ShowSeat>>&& showSeats,
      double amountPaid, TicketStatus status,
      std::vector<std::shared_ptr<Payment>>&& payments,
      std::shared_ptr<User> bookingUser) 
      : id(id), show(std::move(show)),
      showSeats(std::move(showSeats)),
      amountPaid(amountPaid), status(status),
      payments(std::move(payments)),
      bookingUser(std::move(bookingUser)) {
   }

   int Ticket::getId() const {
      return id;
   }

   std::shared_ptr<Show> Ticket::getShow() const {
      return show;
   }

   const std::vector<std::shared_ptr<ShowSeat>>& Ticket::getShowSeats() const {
      return showSeats;
   }

   double Ticket::getAmountPaid() const {
      return amountPaid;
   }

   TicketStatus Ticket::getStatus() const {
      return status;
   }

   const std::vector<std::shared_ptr<Payment>>& Ticket::getPayments() const {
      return payments;
   }

   std::shared_ptr<User> Ticket::getBookingUser() const {
      return bookingUser;
   }

   void Ticket::setId(int id) {
      this->id = id;
   }

   void Ticket::setShow(std::shared_ptr<Show> show) {
      this->show = std::move(show);
   }

   void Ticket::addShowSeat(std::shared_ptr<ShowSeat> showSeat) {
      showSeats.push_back(std::move(showSeat));
   }

   void Ticket::setAmountPaid(double amountPaid) {
      this->amountPaid = amountPaid;
   }

   void Ticket::setStatus(TicketStatus status) {
      this->status = status;
   }

   void Ticket::addPayment(std::shared_ptr<Payment> payment) {
      payments.push_back(std::move(payment));
   }

   void Ticket::setBookingUser(std::shared_ptr<User> bookingUser) {
      this->bookingUser = std::move(bookingUser);
   }
}