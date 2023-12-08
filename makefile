all: day1 day1-cleaned day2

day1: src/day1/day1.cpp
	g++ -std=c++20 src/day1/day1.cpp -o build/day1
	build/day1

day1-cleaned: src/day1/day1-cleaned.cpp
	g++ -std=c++20 src/day1/day1-cleaned.cpp -o build/day1-cleaned
	build/day1-cleaned

day2: src/day2/day2.cpp
	g++ -std=c++20 src/day2/day2.cpp -o build/day2
	build/day2

day3: src/day3/day3.cpp
	g++ -std=c++20 src/day3/day3.cpp -o build/day3
	build/day3

day4: src/day4/day4.cpp
	g++ -std=c++20 src/day4/day4.cpp -o build/day4
	build/day4

day5: src/day5/day5.cpp
	g++ -std=c++20 src/day5/day5.cpp -o build/day5 -O3 -fconstexpr-ops-limit=2000000000
	build/day5