#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
	// Open File
	std::string fileName(__FILE_NAME__);
	fileName.replace(fileName.end() - 3, fileName.end(), "txt");
	std::ifstream infile(fileName);

	// Variable Declarations
	int answer1 = 0, answer2 = 0;
	std::string line;

	// Solution
	while (infile >> line)
	{
		int number1;
		int number2;

		for (size_t i = 0; i < line.size(); i++)
		{
			if (isdigit(line.at(i)))
			{
				number1 = std::stoi(line.substr(i, 1));
				break;
			}
		}

		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (isdigit(line.at(i)))
			{
				number2 = std::stoi(line.substr(i, 1));
				break;
			}
		}

		answer1 = (10 * number1) + number2 + answer1;

		for (size_t i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]))
			{
				number1 = std::stoi(line.substr(i, 1));
				break;
			}
			else
			{
				for (size_t j = 3; j < 6; j++)
				{
					std::string substr = line.substr(i, j);

					if (substr == "one")
					{
						number1 = 1;
						goto loop2;
					}
					else if (substr == "two")
					{
						number1 = 2;
						goto loop2;
					}
					else if (substr == "three")
					{
						number1 = 3;
						goto loop2;
					}
					else if (substr == "four")
					{
						number1 = 4;
						goto loop2;
					}
					else if (substr == "five")
					{
						number1 = 5;
						goto loop2;
					}
					else if (substr == "six")
					{
						number1 = 6;
						goto loop2;
					}
					else if (substr == "seven")
					{
						number1 = 7;
						goto loop2;
					}
					else if (substr == "eight")
					{
						number1 = 8;
						goto loop2;
					}
					else if (substr == "nine")
					{
						number1 = 9;
						goto loop2;
					}
				}
			}
		}
	loop2:

		for (int i = line.size() - 1; i >= 0; i--)
		{
			if (isdigit(line[i]))
			{
				number2 = std::stoi(line.substr(i, 1));
				break;
			}
			else
			{
				for (size_t j = 3; j < 6; j++)
				{
					std::string substr = line.substr(i, j);

					if (substr == "one")
					{
						number2 = 1;
						goto total;
					}
					else if (substr == "two")
					{
						number2 = 2;
						goto total;
					}
					else if (substr == "three")
					{
						number2 = 3;
						goto total;
					}
					else if (substr == "four")
					{
						number2 = 4;
						goto total;
					}
					else if (substr == "five")
					{
						number2 = 5;
						goto total;
					}
					else if (substr == "six")
					{
						number2 = 6;
						goto total;
					}
					else if (substr == "seven")
					{
						number2 = 7;
						goto total;
					}
					else if (substr == "eight")
					{
						number2 = 8;
						goto total;
					}
					else if (substr == "nine")
					{
						number2 = 9;
						goto total;
					}
				}
			}
		}
	total:
		answer2 = (number1 * 10) + number2 + answer2;
	}

	// Print Answer
	std::cout << "Answer 1: " << answer1 << std::endl
			  << "Answer 2: " << answer2 << std::endl;

	return 0;
}
