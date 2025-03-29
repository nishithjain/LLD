#include "Theater.h"

namespace BookMyShow::Model {

   Theater::Theater(int id, const std::string& name, 
      const std::string& address, const City& city) 
      : id(id), name(name), address(address), city(city) {
   }

   void Theater::addScreen(std::unique_ptr<Screen> screen) {
      screens.push_back(std::move(screen));
   }

   int Theater::getId() const {
      return id;
   }

   const std::string& Theater::getName() const {
      return name;
   }

   const std::string& Theater::getAddress() const {
      return address;
   }

   const std::vector<std::unique_ptr<Screen>>& Theater::getScreens() const {
      return screens;
   }

   const City& Theater::getCity() const {
      return city;
   }

   void Theater::setId(int id) {
      this->id = id;
   }

   void Theater::setName(const std::string& name) {
      this->name = name;
   }

   void Theater::setAddress(const std::string& address) {
      this->address = address;
   }

   void Theater::setCity(const City& city) {
      this->city = city;
   }
}