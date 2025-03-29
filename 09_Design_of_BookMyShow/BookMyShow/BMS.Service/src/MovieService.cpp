#include "MovieService.h"
#include "Movie.h"
#include "EnumToStringHelper.h"

using namespace BookMyShow::Model;
using namespace BookMyShow::DTO;

BookMyShow::Service::MovieService::MovieService(std::shared_ptr<BookMyShow::Repository::IMovieRepository> repo)
   : repository(repo) {
}

std::vector<MovieDTO> BookMyShow::Service::MovieService::getAllMovies() {
   std::vector<MovieDTO> dtos;
   auto movies = repository->getAll();

   for (const auto& movie : movies) {
      MovieDTO dto;
      dto.id = movie->getId();
      dto.name = movie->getName();
      dto.rating = movie->getRating();
      dto.durationMinutes = static_cast<int>(movie->getDuration().count());

      // Convert genres
      for (auto g : movie->getGenres()) {
         dto.genreNames.push_back(BookMyShow::Common::Helpers::MovieGenreToString(g)); // You can implement this helper
      }

      dtos.push_back(dto);
   }
   return dtos;
}
