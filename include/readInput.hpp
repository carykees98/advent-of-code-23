#pragma once

#include <fstream>
#include <string>

namespace aoc
{
	std::string readInput(std::filesystem::path pathToInput)
	{
		std::string fileContent;
		std::getline(std::ifstream(pathToInput), fileContent, char(EOF));
		return fileContent;
	}
}