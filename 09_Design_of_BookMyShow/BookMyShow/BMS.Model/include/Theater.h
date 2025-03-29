#pragma once

#include "Screen.h"
#include "City.h"

#include <vector>
#include <string>
#include <memory>

namespace BookMyShow::Model {

   class Theater {
   private:
      int id;
      std::string name;
      std::string address;
      std::vector<std::unique_ptr<Screen>> screens;
      City city;

   public:
      Theater(int id, const std::string& name, const std::string& address, const City& city);

      void addScreen(std::unique_ptr<Screen> screen);

      Theater(const Theater&) = delete;
      Theater& operator=(const Theater&) = delete;
      Theater(Theater&&) = default;
      Theater& operator=(Theater&&) = default;

      int getId() const;
      const std::string& getName() const;
      const std::string& getAddress() const;
      const std::vector<std::unique_ptr<Screen>>& getScreens() const;
      const City& getCity() const;

      void setId(int id);
      void setName(const std::string& name);
      void setAddress(const std::string& address);
      void setCity(const City& city);
   };
}