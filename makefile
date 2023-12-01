all: day1 day1-cleaned

day1: src/day1/day1.cpp
	g++ -std=c++20 src/day1/day1.cpp -o build/day1
	build/day1

day1-cleaned: src/day1/day1-cleaned.cpp
	g++ -std=c++20 src/day1/day1-cleaned.cpp -o build/day1-cleaned
	build/day1-cleaned

day2: src/day2/day2.cpp
	g++ -std=c++20 src/day2/day2.cpp -o build/day2
	build/day2