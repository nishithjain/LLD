#pragma once

#include "IMovieRepository.h"

namespace BookMyShow::Repository {

   class MySqlMovieRepository : public IMovieRepository {
   public:
      std::vector<std::shared_ptr<BookMyShow::Model::Movie>> getAll() override;
   };
}
