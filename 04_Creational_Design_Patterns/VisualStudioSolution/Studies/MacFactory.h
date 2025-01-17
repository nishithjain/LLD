#pragma once
#include <memory>

#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"
#include "GUIFactory.h"

class MacFactory final : public GUIFactory {
public:
    std::unique_ptr<Button> CreateButton() const override;
    std::unique_ptr<Checkbox> CreateCheckbox() const override;
    std::unique_ptr<Menu> CreateMenu() const override;
};
