#pragma once

#include "Show.h"
#include "Seat.h"
#include "SeatStatus.h"

#include <memory>

namespace BookMyShow::Model {

   class ShowSeat {
   private:
      int id;
      std::shared_ptr<Show> show;
      std::shared_ptr<Seat> seat;
      SeatStatus status;

   public:
      ShowSeat(int id, std::shared_ptr<Show> show,
         std::shared_ptr<Seat> seat, SeatStatus status);

      // Getters
      int getId() const;
      std::shared_ptr<Show> getShow() const;
      std::shared_ptr<Seat> getSeat() const;
      SeatStatus getStatus() const;

      // Setters
      void setId(int id);
      void setShow(std::shared_ptr<Show> show);
      void setSeat(std::shared_ptr<Seat> seat);
      void setStatus(SeatStatus status);
   };
}