#pragma once

#include "SeatType.h"
#include <string>

namespace BookMyShow::Model {
   using namespace BookMyShow::Common;

   class Seat {
   private:
      int id;
      int row;
      int column;
      SeatType seatType;
      std::string name; // A1, B13

   public:
      Seat(int id, int row, int column, SeatType seatType, const std::string& name);

      // Getters
      int getId() const;
      int getRow() const;
      int getColumn() const;
      SeatType getSeatType() const;
      const std::string& getName() const;

      // Setters
      void setId(int id);
      void setRow(int row);
      void setColumn(int column);
      void setSeatType(SeatType seatType);
      void setName(const std::string& name);
   };
}