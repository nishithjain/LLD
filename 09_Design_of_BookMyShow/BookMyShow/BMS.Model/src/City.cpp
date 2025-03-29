#include "City.h"

namespace BookMyShow::Model {

   City::City(int id, const std::string& name)
      : id(id), name(name) {
   }

   int City::getId() const {
      return id;
   }

   void City::setId(int id) {
      this->id = id;
   }

   const std::string& City::getName() const {
      return name;
   }

   void City::setName(const std::string& name) {
      this->name = name;
   }
}