## Introduction
This is a simple spaceship game similar to astroids.
The user controls a small spaceship that is affected by gravity from various planets. SFML is used to draw shapes on the screen.

## Features
Currently astroids are randomly generated and spawned.
When they collide with planets or they stray too far from the spaceship, they are destroyed.

Each planet has a gravitational field that will affect the spaceship.

The game stops when the spaceship crashes into a planet.
The game can be restarted by pressing "R"

The game can be paused by pressing the escape key.

## Future Improvements
I'd like to tweak the astroids to be a litle bigger and make their speed more consistent. I'd like to modify the seeding of the RNG to make different maps each time. I'd like to add enemies that fire projectiles at the player. I'd like to add multiplayer but this is an aggresive and time-consuming endevor.

## Compiling

#### Linux

If you're on Linux, there's a makefile. You'll need to install SFML. You can download it [here](https://www.sfml-dev.org/download/sfml/2.5.1/). However, I recommend using your preffered package manager. If you're on Arch Linux, you can install SFML via pacman.

`sudo pacman -S sfml`

Debian can use apt-get

`sudo apt-get install libsfml-dev`

Once you've installed the library you can use the makefile to compile the program.

### Windows

I've spent some time trying to get SFML installed on Windows. I didn't want to use Visual Studio to manage my project and I was never able to install this library on Windows. If you find a way, more power to you. Just know that if you pursue this, there's no package manager to make things easy. I wish you luck.