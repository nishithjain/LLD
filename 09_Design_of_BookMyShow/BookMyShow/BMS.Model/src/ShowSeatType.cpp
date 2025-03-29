#include "ShowSeatType.h"

namespace BookMyShow::Model {

   ShowSeatType::ShowSeatType(int id, std::shared_ptr<Show> show,
      SeatType seatType, double price)
      : id(id), show(show), seatType(seatType), price(price) {
   }

   int ShowSeatType::getId() const {
      return id;
   }

   std::shared_ptr<Show> ShowSeatType::getShow() const {
      return show;
   }

   SeatType ShowSeatType::getSeatType() const {
      return seatType;
   }

   double ShowSeatType::getPrice() const {
      return price;
   }

   void ShowSeatType::setId(int id) {
      this->id = id;
   }

   void ShowSeatType::setShow(std::shared_ptr<Show> show) {
      this->show = show;
   }

   void ShowSeatType::setSeatType(SeatType seatType) {
      this->seatType = seatType;
   }

   void ShowSeatType::setPrice(double price) {
      this->price = price;
   }
}