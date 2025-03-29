#pragma once

#include "Movie.h"
#include "Screen.h"
#include "FeatureType.h"
#include "ShowStatus.h"

#include <chrono>
#include <memory>
#include <vector>
#include <string>

namespace BookMyShow::Model {
   using namespace BookMyShow::Common;

   class Show {
   private:
      int id;
      std::chrono::system_clock::time_point startTime;
      std::chrono::system_clock::time_point endTime;
      std::shared_ptr<Movie> movie;
      std::shared_ptr<Screen> screen;
      std::vector<FeatureType> features;
      std::chrono::system_clock::time_point date;
      ShowStatus status;
      std::string language;

   public:
      Show(int id, std::chrono::system_clock::time_point startTime,
         std::chrono::system_clock::time_point endTime,
         std::shared_ptr<Movie> movie, std::shared_ptr<Screen> screen,
         std::chrono::system_clock::time_point date, ShowStatus status,
         const std::string& language);

      // Getters
      int getId() const;
      std::chrono::system_clock::time_point getStartTime() const;
      std::chrono::system_clock::time_point getEndTime() const;
      std::shared_ptr<Movie> getMovie() const;
      std::shared_ptr<Screen> getScreen() const;
      const std::vector<FeatureType>& getFeatures() const;
      std::chrono::system_clock::time_point getDate() const;
      ShowStatus getStatus() const;
      const std::string& getLanguage() const;

      // Setters
      void setId(int id);
      void setStartTime(std::chrono::system_clock::time_point startTime);
      void setEndTime(std::chrono::system_clock::time_point endTime);
      void setMovie(std::shared_ptr<Movie> movie);
      void setScreen(std::shared_ptr<Screen> screen);
      void addFeature(const FeatureType& feature);
      void setDate(std::chrono::system_clock::time_point date);
      void setStatus(ShowStatus status);
      void setLanguage(const std::string& language);
   };
}