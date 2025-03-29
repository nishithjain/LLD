#pragma once

#include <vector>
#include <string>
#include "FeatureType.h"
#include "Seat.h"

namespace BookMyShow::Model {
   using namespace BookMyShow::Common;

   class Screen {
   private:
      int id;
      std::string name; // Screen 1, Screen 2
      std::vector<FeatureType> features;
      std::vector<Seat> seats;

   public:
      Screen(int id, const std::string& name);

      // Getters
      int getId() const;
      const std::string& getName() const;
      const std::vector<FeatureType>& getFeatures() const;
      const std::vector<Seat>& getSeats() const;

      // Setters
      void setId(int id);
      void setName(const std::string& name);

      // Methods
      void addFeature(FeatureType feature);
      void addSeat(const Seat& seat);
   };
}