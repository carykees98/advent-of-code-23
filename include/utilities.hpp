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

	std::vector<std::string> split(std::string toSplit, char delimiter)
	{
		std::vector<std::string> tokens;
		std::istringstream toSplitStream(toSplit);
		std::string currentToken;

		while (std::getline(toSplitStream, currentToken, delimiter))
		{
			tokens.push_back(currentToken);
		}

		return tokens;
	}
}