#pragma once
#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"

// There are 3 Abstract Products, Button,
// Checkbox and Menu. Keeping concrete products
// related to Mac here.

// Concrete Product A2 (MacButton)
class MacButton final : public Button {
public:
    void Render() const override;
};

// Concrete Product B2 (MacCheckbox)
class MacCheckbox final : public Checkbox {
public:
    void Render() const override;
};

// Concrete Product C2 (MacMenu)
class MacMenu final : public Menu {
public:
    void Render() const override;
};
