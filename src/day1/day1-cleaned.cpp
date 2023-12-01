#include "../../include/aoc-includes.hpp"

int main(int argc, char const *argv[])
{
	const std::filesystem::path inputDir = std::filesystem::canonical("./inputs");
	const std::string filename = "day1.txt";
	const std::string input = aoc::readInput(inputDir / filename);

	std::cout << "Answer 1: " << aoc::part1(input) << std::endl
			  << "Answer 2: " << aoc::part2(input) << std::endl;

	return 0;
}

namespace aoc
{

	int64_t part1(const std::string &input)
	{
		int64_t answer1 = 0;

		size_t startOfLine = 0, endOfLine = input.find('\n');
		while (endOfLine != std::string::npos)
		{
			std::string current = input.substr(startOfLine, endOfLine - startOfLine);

			answer1 += 10 * std::stoi(
								current.substr(
									current.find_first_of("0123456789"), 1));
			answer1 += std::stoi(
				current.substr(
					current.find_last_of("0123456789"), 1));

			startOfLine = endOfLine + 1; // +1 moves past newline character
			endOfLine = input.find_first_of("\n", startOfLine);
		}

		return answer1;
	}

	std::optional<std::pair<size_t, uint8_t>> checkForNumberString(const std::string &currentLine)
	{
		std::map<std::string, uint8_t> stringsToNumbers{
			{"zero", 0},
			{"one", 1},
			{"two", 2},
			{"three", 3},
			{"four", 4},
			{"five", 5},
			{"six", 6},
			{"seven", 7},
			{"eight", 8},
			{"nine", 9}};

		for (size_t i = 0; i < currentLine.size(); i++)
		{
			for (size_t j = 3; j < 6; j++)
			{
				auto result = stringsToNumbers.find(currentLine.substr(i, j));
				if (result != stringsToNumbers.end())
					return std::pair{i, result->second};
			}
		}
		return std::nullopt;
	}

	std::optional<std::pair<size_t, uint8_t>> checkForNumberStringReverse(const std::string &currentLine)
	{
		std::map<std::string, uint8_t> stringsToNumbers{
			{"zero", 0},
			{"one", 1},
			{"two", 2},
			{"three", 3},
			{"four", 4},
			{"five", 5},
			{"six", 6},
			{"seven", 7},
			{"eight", 8},
			{"nine", 9}};

		for (int i = currentLine.size() - 1; i >= 0; i--)
		{
			for (size_t j = 3; j < 6; j++)
			{
				auto result = stringsToNumbers.find(currentLine.substr(i, j));
				if (result != stringsToNumbers.end())
					return std::pair{i, result->second};
			}
		}

		return std::nullopt;
	}

	int64_t part2(const std::string &input)
	{
		int64_t answer2 = 0;

		size_t startOfLine = 0, endOfLine = input.find('\n');
		while (endOfLine != std::string::npos)
		{
			std::string current = input.substr(startOfLine, endOfLine - startOfLine);

			auto stringResult = checkForNumberString(current);
			size_t numberResult = current.find_first_of("0123456789");

			if (stringResult.has_value())
				answer2 += 10 * (stringResult.value().first < numberResult ? stringResult.value().second
																		   : std::stoi(current.substr(numberResult, 1)));
			else
				answer2 += 10 * std::stoi(current.substr(numberResult, 1));

			stringResult = checkForNumberStringReverse(current);
			numberResult = current.find_last_of("0123456789");

			if (stringResult.has_value())
				answer2 += (stringResult.value().first > numberResult ? stringResult.value().second
																	  : std::stoi(current.substr(numberResult, 1)));
			else
				answer2 += std::stoi(current.substr(numberResult, 1));

			startOfLine = endOfLine + 1; // +1 moves past newline character
			endOfLine = input.find_first_of("\n", startOfLine);
		}

		return answer2;
	}

} // namespace aoc