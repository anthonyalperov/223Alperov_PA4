main: main.cpp city.cpp
	g++ -g -Wall -std=c++17 main.cpp city.cpp -o main

test: test.cpp city.cpp
	g++ -g -Wall -std=c++17 test.cpp city.cpp -o test

execute: main
	./main

runtest: test
	./test

clean:
	rm -f main test 
