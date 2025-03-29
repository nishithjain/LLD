#pragma once

#include "ShowDTO.h"
#include "ShowSeatTypeDTO.h"
#include "PaymentDTO.h"
#include "UserDTO.h"
#include "TicketStatus.h"

#include <vector>
#include <memory>

namespace BookMyShow::DTO {

   struct TicketDTO {
   public:
      int id;
      std::shared_ptr<ShowDTO> show;
      std::vector<std::shared_ptr<ShowSeatTypeDTO>> showSeats;
      double amountPaid;
      BookMyShow::Model::TicketStatus status;
      std::vector<std::shared_ptr<PaymentDTO>> payments;
      std::shared_ptr<UserDTO> bookingUser;
   };
}
