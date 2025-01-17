#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>

class ConfigManager 
{
    // Storage for settings
    std::unordered_map<std::string, std::string> settings_;
    ConfigManager();            // Private constructor
    mutable std::mutex mutex_;
public:
    // Delete copy constructor. 
    ConfigManager(const ConfigManager&) = delete;
    // Delete assignment operator.
    ConfigManager& operator=(const ConfigManager&) = delete;
    static ConfigManager& getInstance(); // Static method.
    
    void setSetting(const std::string& key, const std::string& value);
    std::string getSetting(const std::string& key) const;
    void loadSettings();
};