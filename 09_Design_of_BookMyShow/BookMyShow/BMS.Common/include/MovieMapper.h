#pragma once
#include "Movie.h"
#include "MovieDTO.h"

namespace BookMyShow::Common {
   class MovieMapper {
   public:
      static DTO::MovieDTO toDTO(const Model::Movie& movie);
   };
}
