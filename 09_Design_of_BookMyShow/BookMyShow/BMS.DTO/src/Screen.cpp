#include "Screen.h"

namespace BookMyShow::Model {

   Screen::Screen(int id, const std::string& name) 
      : id(id), name(name) {
   }

   int Screen::getId() const {
      return id;
   }

   const std::string& Screen::getName() const {
      return name;
   }

   const std::vector<FeatureType>& Screen::getFeatures() const {
      return features;
   }

   const std::vector<Seat>& Screen::getSeats() const {
      return seats;
   }

   void Screen::setId(int id) {
      this->id = id;
   }

   void Screen::setName(const std::string& name) {
      this->name = name;
   }

   void Screen::addFeature(FeatureType feature) {
      features.push_back(feature);
   }

   void Screen::addSeat(const Seat& seat) {
      seats.push_back(seat);
   }
}