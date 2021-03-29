Space_Cruiser : main.o gameManager.o scene.o dynamicScene.o menu.o collision.o controls.o
	g++ -std=c++17 scene.o main.o menu.o dynamicScene.o collision.o gameManager.o controls.o -lsfml-graphics -lsfml-window -lsfml-system -pthread -o space_cruiser

main.o : main.cpp gameManager.h
	g++ -std=c++17 -c main.cpp -lsfml-graphics -lsfml-window -lsfml-system

gameManager.o : gameManager.cpp gameManager.h scene.h spaceship.h planet.h dynamicScene.h menu.h
	g++ -std=c++17 -c gameManager.cpp -lsfml-graphics -lsfml-window -lsfml-system

scene.o : scene.cpp scene.h spaceship.h planet.h astroid.h collision.h
	g++ -std=c++17 -c scene.cpp

dynamicScene.o : dynamicScene.cpp dynamicScene.h scene.h planet.h astroid.h
	g++ -std=c++17 -c dynamicScene.cpp

collision.o : collision.h collision.cpp
	g++ -std=c++17 -c collision.cpp

menu.o : menu.h menu.cpp
	g++ -std=c++17 -c menu.cpp

controls.o : controls/*
	g++ -std=c++17 -c controls/ClientControls.cpp controls/AFKControls.cpp -o controls.o

clean:
	rm *.o space_cruiser
