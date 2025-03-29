#include "EnumToStringHelper.h"  
#include "FeatureType.h"
#include <stdexcept>

namespace BookMyShow::Common::Helpers {

   std::string MovieGenreToString(BookMyShow::Common::MovieGenre genre) {
      switch (genre) {
      case MovieGenre::Action:       return "Action";
      case MovieGenre::Comedy:       return "Comedy";
      case MovieGenre::Drama:        return "Drama";
      case MovieGenre::SciFi:        return "Sci-Fi";
      case MovieGenre::Horror:       return "Horror";
      case MovieGenre::Thriller:     return "Thriller";
      case MovieGenre::Romance:      return "Romance";
      case MovieGenre::Animation:    return "Animation";
      case MovieGenre::Documentary:  return "Documentary";
      case MovieGenre::Fantasy:      return "Fantasy";
      case MovieGenre::Mystery:      return "Mystery";
      case MovieGenre::Adventure:    return "Adventure";
      case MovieGenre::Crime:        return "Crime";
      case MovieGenre::Musical:      return "Musical";
      case MovieGenre::Western:      return "Western";
      case MovieGenre::Historical:   return "Historical";
      case MovieGenre::War:          return "War";
      case MovieGenre::Sport:        return "Sport";
      case MovieGenre::Family:       return "Family";
      case MovieGenre::Other:        return "Other";
      default:                       return "Unknown";
      }
   }

   std::string FeatureTypeToString(FeatureType featureType) {
      switch (featureType) {
      case FeatureType::TWOD:
         return "2D";
      case FeatureType::THREED:
         return "3D";
      case FeatureType::IMAX:
         return "IMAX";
      case FeatureType::DOLBY:
         return "DOLBY";
      default:
         throw std::invalid_argument("Invalid FeatureType");
      }
   }
}
