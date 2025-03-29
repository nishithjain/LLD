#pragma once

#include "SeatType.h"
#include "Show.h"

#include <memory>

namespace BookMyShow::Model {

   class ShowSeatType {
   private:
      int id;
      std::shared_ptr<Show> show;
      SeatType seatType;
      double price;

   public:
      ShowSeatType(int id, std::shared_ptr<Show> show,
         SeatType seatType, double price);

      // Getters
      int getId() const;
      std::shared_ptr<Show> getShow() const;
      SeatType getSeatType() const;
      double getPrice() const;

      // Setters
      void setId(int id);
      void setShow(std::shared_ptr<Show> show);
      void setSeatType(SeatType seatType);
      void setPrice(double price);
   };
}