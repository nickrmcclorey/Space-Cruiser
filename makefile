Space_Cruiser : main.o
	g++ main.o -lsfml-graphics -lsfml-window -lsfml-system -o Space_Cruiser

main.o : main.cpp scene.h planet.h spaceship.h
	g++ -std=c++17 -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm main.o Space_Cruiser