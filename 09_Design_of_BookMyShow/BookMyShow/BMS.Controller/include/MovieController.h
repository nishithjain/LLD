#pragma
#include "MovieService.h"

namespace BookMyShow::Controller {
   class MovieController {
   private:
      BookMyShow::Service::MovieService service;
   public:
      MovieController(Service::MovieService service);
      std::vector<DTO::MovieDTO> getAllMovies();
   };
}