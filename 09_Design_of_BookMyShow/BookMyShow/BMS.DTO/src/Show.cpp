#include "Show.h"

namespace BookMyShow::Model {

   Show::Show(int id, std::chrono::system_clock::time_point startTime,
      std::chrono::system_clock::time_point endTime,
      std::shared_ptr<Movie> movie, std::shared_ptr<Screen> screen,
      std::chrono::system_clock::time_point date, ShowStatus status,
      const std::string& language) 
      : id(id), startTime(startTime), endTime(endTime), movie(movie),
      screen(screen), date(date), status(status), language(language) {
   }

   int Show::getId() const {
      return id;
   }

   std::chrono::system_clock::time_point Show::getStartTime() const {
      return startTime;
   }

   std::chrono::system_clock::time_point Show::getEndTime() const {
      return endTime;
   }

   std::shared_ptr<Movie> Show::getMovie() const {
      return movie;
   }

   std::shared_ptr<Screen> Show::getScreen() const {
      return screen;
   }

   const std::vector<FeatureType>& Show::getFeatures() const {
      return features;
   }

   std::chrono::system_clock::time_point Show::getDate() const {
      return date;
   }

   ShowStatus Show::getStatus() const {
      return status;
   }

   const std::string& Show::getLanguage() const {
      return language;
   }

   void Show::setId(int id) {
      this->id = id;
   }

   void Show::setStartTime(std::chrono::system_clock::time_point startTime) {
      this->startTime = startTime;
   }

   void Show::setEndTime(std::chrono::system_clock::time_point endTime) {
      this->endTime = endTime;
   }

   void Show::setMovie(std::shared_ptr<Movie> movie) {
      this->movie = movie;
   }

   void Show::setScreen(std::shared_ptr<Screen> screen) {
      this->screen = screen;
   }

   void Show::addFeature(const FeatureType& feature) {
      features.push_back(feature);
   }

   void Show::setDate(std::chrono::system_clock::time_point date) {
      this->date = date;
   }

   void Show::setStatus(ShowStatus status) {
      this->status = status;
   }

   void Show::setLanguage(const std::string& language) {
      this->language = language;
   }
}