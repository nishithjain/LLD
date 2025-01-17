#include "WindowsUI.h"

#include <iostream>

void WindowsButton::Render() const
{
	std::cout << "Rendering Windows Button\n";
}

void WindowsCheckbox::Render() const
{
	std::cout << "Rendering Windows Checkbox\n";
}

void WindowsMenu::Render() const
{
	std::cout << "Rendering Windows Menu\n";
}
