#pragma once

#include "ShowStatus.h"
#include "MovieDTO.h"
#include "ScreenDTO.h"

#include <string>
#include <memory>
#include <chrono>

namespace BookMyShow::DTO {

   struct ShowDTO {
   public:
      int id;
      std::shared_ptr<MovieDTO> movie;
      std::shared_ptr<ScreenDTO> screen;
      std::chrono::system_clock::time_point startTime;
      std::chrono::system_clock::time_point endTime;
      Model::ShowStatus status;
   };
}
