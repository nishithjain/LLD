#pragma once

#include "Show.h"
#include "ShowSeat.h"
#include "Payment.h"
#include "User.h"
#include "TicketStatus.h"

#include <vector>
#include <memory>

namespace BookMyShow::Model {

   class Ticket {
   private:
      int id;
      std::shared_ptr<Show> show;
      std::vector<std::shared_ptr<ShowSeat>> showSeats;
      double amountPaid;
      TicketStatus status;
      std::vector<std::shared_ptr<Payment>> payments;
      std::shared_ptr<User> bookingUser;

   public:
      Ticket(int id, std::shared_ptr<Show> show,
         std::vector<std::shared_ptr<ShowSeat>>&& showSeats,
         double amountPaid, TicketStatus status,
         std::vector<std::shared_ptr<Payment>>&& payments,
         std::shared_ptr<User> bookingUser);

      // Getters
      int getId() const;
      std::shared_ptr<Show> getShow() const;
      const std::vector<std::shared_ptr<ShowSeat>>& getShowSeats() const;
      double getAmountPaid() const;
      TicketStatus getStatus() const;
      const std::vector<std::shared_ptr<Payment>>& getPayments() const;
      std::shared_ptr<User> getBookingUser() const;

      // Setters
      void setId(int id);
      void setShow(std::shared_ptr<Show> show);
      void addShowSeat(std::shared_ptr<ShowSeat> showSeat);
      void setAmountPaid(double amountPaid);
      void setStatus(TicketStatus status);
      void addPayment(std::shared_ptr<Payment> payment);
      void setBookingUser(std::shared_ptr<User> bookingUser);
   };
}