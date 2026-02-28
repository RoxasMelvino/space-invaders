# Space-invaders
This is a simple space-invaders game in the making using C++ and raylib. Right now, it is really bare bones. 
So far, I've coded player and enemy movement, and currently making a bullet system for the player to shoot.


## Hierarchy
The `Game` class "owns" most, if not all, of the objects. As of now, it keeps track of the player, enemies, and bullets, 
updating and drawing them in the canvas.