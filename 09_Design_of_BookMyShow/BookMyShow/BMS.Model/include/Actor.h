#pragma once
#include <string>

namespace BookMyShow::Model {

   class Actor {
   private:
      int id;
      std::string name;

   public:
      Actor() = default;
      Actor(int id, const std::string& name);

      int getId() const;
      const std::string& getName() const;

      void setId(int id);
      void setName(const std::string& name);
   };
}