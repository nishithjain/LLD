#include "LinuxFactor.h"

#include "LinuxUI.h"

std::unique_ptr<Button> LinuxFactor::CreateButton() const
{
    return std::make_unique<LinuxButton>();
}

std::unique_ptr<Checkbox> LinuxFactor::CreateCheckbox() const
{
    return std::make_unique<LinuxCheckbox>();
}

std::unique_ptr<Menu> LinuxFactor::CreateMenu() const
{
    return std::make_unique<LinuxMenu>();
}



