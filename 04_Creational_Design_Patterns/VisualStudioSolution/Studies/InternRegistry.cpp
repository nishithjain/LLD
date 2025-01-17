#include "InternRegistry.h"

#include <iostream>

void InternRegistry::RegisterIntern(const std::string& key, std::unique_ptr<Intern> prototype)
{
	registry_[key] = std::move(prototype);
}

std::unique_ptr<Intern> InternRegistry::CreateIntern(const std::string& key) const
{
	if (const auto it = registry_.find(key); it != registry_.end()) 
    {
        return it->second->clone();
    }
    std::cerr << "No intern found for key: " << key << '\n';
    return nullptr;
}