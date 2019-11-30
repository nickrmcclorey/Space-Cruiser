Space_Cruiser : main.o gameManager.o scene.o camera.o
	g++ -std=c++17 camera.o scene.o main.o gameManager.o -lsfml-graphics -lsfml-window -lsfml-system -o space_cruiser

main.o : main.cpp gameManager.h
	g++ -std=c++17 -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system

gameManager.o : gameManager.cpp gameManager.h scene.h spaceship.h camera.h
	g++ -std=c++17 -c gameManager.cpp -lsfml-graphics -lsfml-window -lsfml-system

scene.o : scene.cpp scene.h spaceship.h planet.h
	g++ -std=c++17 -c scene.cpp

camera.o : camera.cpp camera.h scene.h
	g++ -std=c++17 -c camera.cpp

clean:
	rm *.o space_cruiser