#include "Seat.h"

namespace BookMyShow::Model {

   Seat::Seat(int id, int row, int column, SeatType seatType, 
      const std::string& name) 
      : id(id), row(row), column(column), 
      seatType(seatType), name(name) {
   }

   int Seat::getId() const {
      return id;
   }

   int Seat::getRow() const {
      return row;
   }

   int Seat::getColumn() const {
      return column;
   }

   SeatType Seat::getSeatType() const {
      return seatType;
   }

   const std::string& Seat::getName() const {
      return name;
   }

   void Seat::setId(int id) {
      this->id = id;
   }

   void Seat::setRow(int row) {
      this->row = row;
   }

   void Seat::setColumn(int column) {
      this->column = column;
   }

   void Seat::setSeatType(SeatType seatType) {
      this->seatType = seatType;
   }

   void Seat::setName(const std::string& name) {
      this->name = name;
   }
}