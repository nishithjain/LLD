#pragma once
#include <vector>
#include <memory>
#include "D:\GitHub\LLD\09_Design_of_BookMyShow\BookMyShow\BMS.Model\include\Movie.h"

namespace BookMyShow::Repository {

   class IMovieRepository {
   public:
      virtual std::vector<std::shared_ptr<BookMyShow::Model::Movie>> getAll() = 0;
      virtual ~IMovieRepository() = default;
   };
}
