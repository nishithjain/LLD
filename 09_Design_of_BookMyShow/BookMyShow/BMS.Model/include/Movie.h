#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include "D:\GitHub\LLD\09_Design_of_BookMyShow\BookMyShow\BMS.Common\include\FeatureType.h"
#include "Actor.h"
#include "D:\GitHub\LLD\09_Design_of_BookMyShow\BookMyShow\BMS.Common\include\MovieGenre.h"

namespace BookMyShow::Model {
   using namespace BookMyShow::Common;
   class Movie {
   private:
      int id;
      std::string name;
      std::vector<std::shared_ptr<Actor>> actors;
      std::vector<MovieGenre> genres;
      std::vector<std::string> languages;
      std::chrono::minutes duration; // Runtime in minutes
      double rating; // Movie rating (e.g., IMDb rating)
      std::vector<FeatureType> features;

   public:
      Movie() = default;
      Movie(int id, const std::string& name,
         const std::vector<MovieGenre>& genres,
         const std::vector<std::string>& languages,
         std::chrono::minutes duration, double rating);

      void addActor(std::shared_ptr<Actor> actor);

      // Getters
      int getId() const;
      const std::string& getName() const;
      const std::vector<std::shared_ptr<Actor>>& getActors() const;
      const std::vector<MovieGenre>& getGenres() const;
      const std::vector<std::string>& getLanguages() const;
      std::chrono::minutes getDuration() const;
      double getRating() const;
      const std::vector<FeatureType>& getFeatures() const;

      // Setters
      void setId(int id);
      void setName(const std::string& name);
      void setGenres(const std::vector<MovieGenre>& genre);
      void setLanguages(const std::vector<std::string>& languages);
      void setDuration(std::chrono::minutes duration);
      void setRating(double rating);
      void setActors(const std::vector<std::shared_ptr<Actor>>& actors);
      void addFeature(FeatureType feature);
   };
}