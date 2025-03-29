#include "MySqlMovieRepository.h"
#include "MovieGenre.h"
#include "FeatureType.h"
#include "Actor.h"
#include "C:\Program Files (x86)\MySQL\MySQL Connector C++ 8.0\include\mysqlx\xdevapi.h"
#include <sstream>
#include <iostream>

using namespace BookMyShow::Model;
using namespace mysqlx;
using namespace std;

std::vector<std::shared_ptr<Movie>> BookMyShow::Repository::MySqlMovieRepository::getAll() {
   std::vector<std::shared_ptr<Movie>> movies;

   try {
      // Establish session
      Session session("mysqlx://root:Welcome%40123@localhost:33060");

      // Access schema and movies table
      Schema db = session.getSchema("BookMyShowDB");
      Table table = db.getTable("movies");

      // Only select actual columns from the MOVIES table
      RowResult result = table.select("MOVIE_ID", "NAME", "DURATION_MINUTES", "RATING").execute();

      for (const Row& row : result) {
         int id = row[0];
         std::string name = row[1].get<std::string>();
         int durationMinutes = row[2];
         double rating = row[3];

         auto movie = std::make_shared<Movie>();
         movie->setId(id);
         movie->setName(name);
         movie->setDuration(std::chrono::minutes(durationMinutes));
         movie->setRating(rating);

         // Related data (genres, languages, actors, features) should be fetched separately
         // and added to the movie object here (if needed).

         movies.push_back(movie);
      }
   }
   catch (const mysqlx::Error& err) {
      cerr << "MySQL Error: " << err.what() << endl;
   }
   catch (const std::exception& ex) {
      cerr << "STD Exception: " << ex.what() << endl;
   }
   catch (...) {
      cerr << "Unknown exception!" << endl;
   }

   return movies;
}

