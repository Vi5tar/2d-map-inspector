compile:
	g++ -std=c++11 main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system -o build/main

run:
	./build/main

freshrun:
	make compile
	make run