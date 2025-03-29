#pragma once
#include <string>
namespace BookMyShow::Model {

   class City {
   private:
      int id;
      std::string name;

   public:
      City(int id, const std::string& name);

      int getId() const;
      void setId(int id);
      const std::string& getName() const;
      void setName(const std::string& name);
   };
}