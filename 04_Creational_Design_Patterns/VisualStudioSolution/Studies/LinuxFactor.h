#pragma once
#include "GUIFactory.h"

class LinuxFactor final : public GUIFactory {
public:
	std::unique_ptr<Button> CreateButton() const override;
	std::unique_ptr<Checkbox> CreateCheckbox() const override;
	std::unique_ptr<Menu> CreateMenu() const override;
};

