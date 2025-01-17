#pragma once
#include <memory>

#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"

// We group all the factory methods in a class.
class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> CreateButton() const = 0;
    virtual std::unique_ptr<Checkbox> CreateCheckbox() const = 0;
    virtual std::unique_ptr<Menu> CreateMenu() const = 0;
};
