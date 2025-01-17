#include <iostream>
#include "ConfigManager.h"

using namespace std;

ConfigManager& ConfigManager::getInstance()
{
    static ConfigManager instance;
    return instance;
}

void ConfigManager::loadSettings()
{
    settings_["app_name"] = "MyApp";
    settings_["version"] = "1.0.0";
    settings_["max_users"] = "100";
    std::cout << "Settings loaded successfully." << std::endl;
}

std::string ConfigManager::getSetting(const std::string& key) const
{
    auto it = settings_.find(key);
    if (it != settings_.end())
    {
        return it->second;
    }
    return "Setting not found";
}

void ConfigManager::setSetting(const std::string& key, 
    const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    settings_[key] = value;
    std::cout << "Setting updated: " << key << " = " 
        << value << std::endl;
}

ConfigManager::ConfigManager() 
{
    loadSettings();
}
