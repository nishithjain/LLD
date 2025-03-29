// MovieController.cpp
#include "MovieController.h"
#include <iostream>

using namespace BookMyShow;

Controller::MovieController::MovieController(Service::MovieService service)
   : service(std::move(service)) {
}

std::vector<DTO::MovieDTO> Controller::MovieController::getAllMovies() {
   std::vector<DTO::MovieDTO> movies = service.getAllMovies();
   return movies;
}
