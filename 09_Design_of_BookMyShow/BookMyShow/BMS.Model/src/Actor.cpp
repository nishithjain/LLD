#include "Actor.h"
namespace BookMyShow::Model {

   Actor::Actor(int id, const std::string& name) 
      : id(id), name(name) {
   }

   int Actor::getId() const {
      return id;
   }

   const std::string& Actor::getName() const {
      return name;
   }

   void Actor::setId(int id) {
      this->id = id;
   }

   void Actor::setName(const std::string& name) {
      this->name = name;
   }
}