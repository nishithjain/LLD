#pragma once
#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"

// There are 3 Abstract Products, Button,
// Checkbox and Menu. Keeping concrete products
// related to Windows here.

// Concrete Product A1 (WindowsButton)
class WindowsButton final : public Button {
public:
    void Render() const override;
};

// Concrete Product B1 (WindowsCheckbox)
class WindowsCheckbox final : public Checkbox {
public:
    void Render() const override;
};

// Concrete Product C1 (WindowsMenu)
class WindowsMenu final : public Menu {
public:
    void Render() const override;
};