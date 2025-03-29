#include "Movie.h"

namespace BookMyShow::Model {
   
   Movie::Movie(int id, const std::string& name,
      const std::vector<MovieGenre>& genres,
      const std::vector<std::string>& languages,
      std::chrono::minutes duration, double rating) 
      : id(id), name(name), genres(genres), languages(languages), 
      duration(duration), rating(rating) {
   }

   void Movie::addActor(std::shared_ptr<Actor> actor) {
      actors.push_back(actor);
   }

   int Movie::getId() const {
      return id;
   }

   const std::string& Movie::getName() const {
      return name;
   }

   const std::vector<std::shared_ptr<Actor>>& Movie::getActors() const {
      return actors;
   }

   const std::vector<MovieGenre>& Movie::getGenres() const {
      return genres;
   }

   const std::vector<std::string>& Movie::getLanguages() const {
      return languages;
   }

   std::chrono::minutes Movie::getDuration() const {
      return duration;
   }

   double Movie::getRating() const {
      return rating;
   }

   const std::vector<FeatureType>& Movie::getFeatures() const {
      return features;
   }

   void Movie::setId(int id) {
      this->id = id;
   }

   void Movie::setName(const std::string& name) {
      this->name = name;
   }

   void Movie::setGenres(const std::vector<MovieGenre>& genre) {
      this->genres = genre;
   }

   void Movie::setLanguages(const std::vector<std::string>& languages) {
      this->languages = languages;
   }

   void Movie::setDuration(std::chrono::minutes duration) {
      this->duration = duration;
   }

   void Movie::setRating(double rating) {
      this->rating = rating;
   }

   void Movie::addFeature(FeatureType feature) {
      features.push_back(feature);
   }

   void Movie::setActors(const std::vector<std::shared_ptr<Actor>>& actors) {
      this->actors = actors;
   }
}