Space_Cruiser : main.o gameManager.o scene.o
	g++ -std=c++17 scene.o main.o gameManager.o -lsfml-graphics -lsfml-window -lsfml-system -o space_cruiser

main.o : main.cpp gameManager.h
	g++ -std=c++17 -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system

gameManager.o : gameManager.cpp gameManager.h scene.h spaceship.h
	g++ -std=c++17 -c gameManager.cpp -lsfml-graphics -lsfml-window -lsfml-system

scene.o : scene.cpp scene.h spaceship.h planet.h
	g++ -std=c++17 -c scene.cpp

clean:
	rm *.o space_cruiser