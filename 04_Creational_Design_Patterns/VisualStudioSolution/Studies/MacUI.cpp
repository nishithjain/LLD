#include "MacUI.h"

#include <iostream>

void MacButton::Render() const
{
	std::cout << "Rendering Mac Button\n";
}

void MacCheckbox::Render() const
{
	std::cout << "Rendering Mac Checkbox\n";
}

void MacMenu::Render() const
{
	std::cout << "Rendering Mac Menu\n";
}
