#include "WindowsFactory.h"

#include "WindowsUI.h"

std::unique_ptr<Button> WindowsFactory::CreateButton() const
{
	return std::make_unique<WindowsButton>();
}

std::unique_ptr<Checkbox> WindowsFactory::CreateCheckbox() const
{
	return std::make_unique<WindowsCheckbox>();
}

std::unique_ptr<Menu> WindowsFactory::CreateMenu() const
{
	return std::make_unique<WindowsMenu>();
}

