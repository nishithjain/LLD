#include "LinuxUI.h"

#include <iostream>

void LinuxButton::Render() const
{
	std::cout << "Rendering Linux Button\n";
}

void LinuxCheckbox::Render() const
{
	std::cout << "Rendering Linux Checkbox\n";
}

void LinuxMenu::Render() const
{
	std::cout << "Rendering Linux Menu\n";
}

