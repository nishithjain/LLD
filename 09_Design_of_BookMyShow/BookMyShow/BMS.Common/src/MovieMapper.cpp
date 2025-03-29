#include "MovieMapper.h"
#include "EnumToStringHelper.h"
using namespace BookMyShow;

DTO::MovieDTO Common::MovieMapper::toDTO(const Model::Movie& movie) {
   DTO::MovieDTO dto;
   dto.id = movie.getId();
   dto.name = movie.getName();
   dto.durationMinutes = movie.getDuration().count();
   dto.rating = movie.getRating();

   for (const auto& actor : movie.getActors()) {
      dto.actorNames.push_back(actor->getName());
   }

   for (const auto& genre : movie.getGenres()) {
      dto.genreNames.push_back(Common::Helpers::MovieGenreToString(genre));
   }

   dto.languages = movie.getLanguages();

   for (const auto& feature : movie.getFeatures()) {
      dto.featureNames.push_back(Common::Helpers::FeatureTypeToString(feature));
   }

   return dto;
}
