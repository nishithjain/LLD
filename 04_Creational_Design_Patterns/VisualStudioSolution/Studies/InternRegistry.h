#pragma once
#include <unordered_map>
#include "Intern.h"

class InternRegistry
{
	std::unordered_map<std::string, std::unique_ptr<Intern>> registry_;
public:
	void RegisterIntern(const std::string& key, std::unique_ptr<Intern> prototype);
	[[nodiscard]] std::unique_ptr<Intern> CreateIntern(const std::string& key) const;
};

