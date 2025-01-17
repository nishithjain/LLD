#include <iostream>

#include "Bird.h"
#include "BirdFactory.h"
#include "BirdType.h"
#include "Crow.h"
#include "GUIFactory.h"
#include "Hen.h"
#include "LinuxFactor.h"
#include "MacFactory.h"
#include "Peacock.h"
#include "Sparrow.h"
#include "VehicleFactory.h"
#include "WindowsFactory.h"

using namespace std;

void RenderUI(const GUIFactory& factory) {
	const auto button = factory.CreateButton();
	const auto checkbox = factory.CreateCheckbox();
	const auto menu = factory.CreateMenu();

	button->Render();
	checkbox->Render();
	menu->Render();
}

int main() {
	// Create Windows UI
	const std::unique_ptr<GUIFactory> factory =
		std::make_unique<WindowsFactory>();
	RenderUI(*factory);

	return 0;
}
/*
Rendering Windows Button
Rendering Windows Checkbox
Rendering Windows Menu
 */