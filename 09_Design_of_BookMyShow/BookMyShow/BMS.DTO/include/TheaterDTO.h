#pragma once

#include "CityDTO.h"
#include "ScreenDTO.h"

#include <string>
#include <vector>
#include <memory>

namespace BookMyShow::DTO {

   struct TheaterDTO {
   public:
      int id;
      std::string name;
      std::string address;
      CityDTO city;
      std::vector<std::shared_ptr<ScreenDTO>> screens;
   };
}
