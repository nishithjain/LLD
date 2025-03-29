#pragma once

#include "SeatType.h"
#include "ShowDTO.h"

#include <memory>

namespace BookMyShow::DTO {

   struct ShowSeatTypeDTO {
   public:
      int id;
      std::shared_ptr<ShowDTO> show;
      Model::SeatType seatType;
      double price;
   };
}
