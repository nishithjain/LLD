#pragma once
#include <string>
#include "MovieGenre.h"
#include "FeatureType.h"

namespace BookMyShow::Common::Helpers {
   std::string MovieGenreToString(MovieGenre genre);
   std::string FeatureTypeToString(FeatureType featureType);
}