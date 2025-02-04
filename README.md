# 42_so_long
A project working with 3D game designing and window management


OS:----------------------------------------------------------------------------
Needs Linux as Operating System.
If you have WINDOWs then you can install "Windows Subsytem for Linux".

Requirements:------------------------------------------------------------------
Requires X11 and some other things I dont fully understand.
Run:
"sudo apt-get install gcc make xorg libxext-dev libbsd-dev"
to get the required packages.
Also requires git to be able to clone the minilibx into the project,
as well as needing Make to be able to compile the necessary files. (Make is included in the above command)


Installation:------------------------------------------------------------------
Just run "make" in the terminal at the root.
(where the highest Makefile is located)
Alternatively run <make bonus> to compile the bonus version of the programm,
which allows for enemy patrols.
Then run "./so_long" or "./so_long_bonus" followed by a space and the
name of a vaild map file ending in .ber
Example: ./so_long empty.ber
Example: ./so_long_bonus maps/map1/enemy.ber
There is a tutorial below to create valid maps.


Maps:--------------------------------------------------------------------------
Maps are provided as text files ending in ".ber".
A line is delimited by being between start of file, 
'\n' and by the end of file.
Maps consist of valid Ascii-Characters (further info see 'Map Characters')
Maps have to be rectangular
Maps have to be closed on all sides, diagonals included, this means that they
have to be encircled in walls.
Maps need exactly 1 Exit, exactly 1 Player and at least 1 Collectable

Map Characters:
1 		- 	Wall; that stops movement, they close off the map.
0 		- 	Free space; that anyone can move to.
P 		- 	Player; or their starting position.
E 		- 	Exit; that blocks movement until all collectables have been 
			gathered. At which point it opens up and allows the user
			to win the game.
C 		- 	Collectables; that all need to be gathered in order to win the game.
The following only works for the bonus version:
U/D/L/R -	Enemies; which move [U]pward [D]ownward, [L]eft or [R]ight.
			They move until they hit anything, at which point they will turn
			around next round, turning a [L]eftie into a [R]ight enemy.
			After that they will continue moving in this new direction.
Here is a valid map as text:
1111111
1E010C1
1P0C001
1111111

Controls:----------------------------------------------------------------------
W/A/S/D	-	to move around
ESC		-	to close the game
Clicking the X in the top right also closes the Game

Rules:-------------------------------------------------------------------------
The player moves before the enemies. If the player enters a field,
where an enemy stands, then that enemy is defeated.
Should the player move to a field, and an enemy then move to that field,
the player is defeated.
The player has to move into all collectables and then move into the exit.
Should an enemy move into the player before that, the player will lose.

There are 2 Achievements hidden in the game, can you find them
without looking into the source code?


Sprites:-----------------------------------------------------------------------
The player, wall and free sprites were drawn by me and were inspired by Warframe.

The enemy, coin and exit sprites are scaled down and slightly adjusted screenshots of textures from Warfrane.
A picture of a Grineer Elite Soldier for the Enemy, a picture of Endo for the Collectable Texture and some random hatch from a Grineer Tileset on Earth for the Exit.