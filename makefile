Space_Cruiser : main.o gameManager.o scene.o
	g++ -std=c++17 scene.o main.o gameManager.o -lsfml-graphics -lsfml-window -lsfml-system -o Space_Cruiser

main.o : main.cpp scene.h planet.h spaceship.h
	g++ -std=c++17 -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system

gameManager.o : gameManager.cpp gameManager.h scene.h
	g++ -std=c++17 -c gameManager.cpp -lsfml-graphics -lsfml-window -lsfml-system

scene.o : scene.cpp scene.h
	g++ -std=c++17 -c scene.cpp

clean:
	rm *.o Space_Cruiser