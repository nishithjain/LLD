#pragma once
#include <vector>
#include <memory>
#include "MovieDTO.h"
#include "D:\GitHub\LLD\09_Design_of_BookMyShow\BookMyShow\BMS.Repository\include\IMovieRepository.h"

namespace BookMyShow::Service {
   class MovieService {
   private:
      std::shared_ptr<BookMyShow::Repository::IMovieRepository> repository;
   public:
      MovieService(std::shared_ptr<BookMyShow::Repository::IMovieRepository> repo);
      std::vector<BookMyShow::DTO::MovieDTO> getAllMovies();
   };
}
