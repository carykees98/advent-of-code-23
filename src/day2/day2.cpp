#include "../../include/aoc-includes.hpp"

int main(int argc, char const *argv[])
{
	const std::filesystem::path inputDir = std::filesystem::canonical("./inputs");
	std::string filename(__FILE_NAME__);
	filename.replace(filename.end() - 3, filename.end(), "txt");
	const std::string input = aoc::readInput(inputDir / filename);

	std::cout << "Answer 1: " << aoc::part1(input) << std::endl
			  << "Answer 2: " << aoc::part2(input) << std::endl;

	return 0;
}

namespace aoc
{
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

	int64_t part1(const std::string &input)
	{
		int64_t answer1 = 0;
		const int MAX_RED = 12;
		const int MAX_GREEN = 13;
		const int MAX_BLUE = 14;
		int currentNumber;
		std::string currentColor;

		auto games = split(input, '\n');
		for (int i = 0; i < games.size(); i++)
		{
			games[i].erase(0, games[i].find_first_of(':') + 2);

			auto turns = split(games[i], ';');
			for (auto &&turn : turns)
			{
				auto plays = split(turn, ',');
				for (auto &&play : plays)
				{
					std::istringstream playStream(play);

					playStream >> currentNumber >> currentColor;

					if (currentColor == "blue" && currentNumber > MAX_BLUE)
					{
						goto nextGame;
					}
					else if (currentColor == "red" && currentNumber > MAX_RED)
					{
						goto nextGame;
					}
					else if (currentColor == "green" && currentNumber > MAX_GREEN)
					{
						goto nextGame;
					}
				}
			}
			answer1 += i + 1;
		nextGame:
			continue;
		}

		return answer1;
	}

	int64_t part2(const std::string &input)
	{
		int64_t answer2 = 0;
		int maxBlue = 0;
		int maxRed = 0;
		int maxGreen = 0;
		int currentNumber;
		std::string currentColor;

		auto games = split(input, '\n');
		for (int i = 0; i < games.size(); i++)
		{
			games[i].erase(0, games[i].find_first_of(':') + 2);

			auto turns = split(games[i], ';');
			for (auto &&turn : turns)
			{
				auto plays = split(turn, ',');
				for (auto &&play : plays)
				{
					std::istringstream playStream(play);

					playStream >> currentNumber >> currentColor;

					if (currentColor == "blue" && currentNumber > maxBlue)
					{
						maxBlue = currentNumber;
					}
					else if (currentColor == "red" && currentNumber > maxRed)
					{
						maxRed = currentNumber;
					}
					else if (currentColor == "green" && currentNumber > maxGreen)
					{
						maxGreen = currentNumber;
					}
				}
			}
			unsigned long long power = maxBlue * maxGreen * maxRed;
			maxBlue = 0;
			maxGreen = 0;
			maxRed = 0;

			answer2 += power;
			std::cout << i + 1 << " " << power << std::endl;
		}

		return answer2;
	}
}