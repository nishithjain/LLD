#include "MacFactory.h"

#include "MacUI.h"

std::unique_ptr<Button> MacFactory::CreateButton() const
{
	return std::make_unique<MacButton>();
}

std::unique_ptr<Checkbox> MacFactory::CreateCheckbox() const
{
	return std::make_unique<MacCheckbox>();
}

std::unique_ptr<Menu> MacFactory::CreateMenu() const
{
	return std::make_unique<MacMenu>();
}
