#pragma once
#include "Button.h"
#include "Checkbox.h"
#include "Menu.h"

// There are 3 Abstract Products, Button,
// Checkbox and Menu. Keeping concrete products
// related to Linux here.

// Concrete Product A3 (LinuxButton)
class LinuxButton final : public Button {
public:
    void Render() const override;
};

// Concrete Product B3 (LinuxCheckbox)
class LinuxCheckbox final : public Checkbox {
public:
    void Render() const override;
};

// Concrete Product C3 (LinuxMenu)
class LinuxMenu final : public Menu {
public:
    void Render() const override;
};