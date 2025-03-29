#include "ShowSeat.h"

namespace BookMyShow::Model {

   ShowSeat::ShowSeat(int id, std::shared_ptr<Show> show,
      std::shared_ptr<Seat> seat, SeatStatus status)
      : id(id), show(show), seat(seat), status(status) {
   }

   int ShowSeat::getId() const {
      return id;
   }

   std::shared_ptr<Show> ShowSeat::getShow() const {
      return show;
   }

   std::shared_ptr<Seat> ShowSeat::getSeat() const {
      return seat;
   }

   SeatStatus ShowSeat::getStatus() const {
      return status;
   }

   void ShowSeat::setId(int id) {
      this->id = id;
   }

   void ShowSeat::setShow(std::shared_ptr<Show> show) {
      this->show = show;
   }

   void ShowSeat::setSeat(std::shared_ptr<Seat> seat) {
      this->seat = seat;
   }

   void ShowSeat::setStatus(SeatStatus status) {
      this->status = status;
   }
}