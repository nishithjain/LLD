#pragma once

#include "ActorDTO.h"
#include <string>
#include <vector>

namespace BookMyShow::DTO {

   struct MovieDTO {
      int id;
      std::string name;
      std::vector<std::string> actorNames;
      std::vector<std::string> genreNames;
      std::vector<std::string> languages;
      int durationMinutes; // to represent std::chrono::minutes as an int
      double rating;
      std::vector<std::string> featureNames;
   };
}
