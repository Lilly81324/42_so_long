# 42_so_long
A project working with 3D game designing and window management<br />

OS:----------------------------------------------------------------------------<br />
Needs Linux as Operating System.<br />
If you have WINDOWs then you can install "Windows Subsytem for Linux".<br />
<br />
<br />
Requirements:------------------------------------------------------------------<br />
Requires X11 and some other things I dont fully understand.<br />
Run:<br />
"**sudo apt-get install gcc make xorg libxext-dev libbsd-dev**"
to get the required packages.<br />
Also requires git to be able to clone the minilibx into the project,
as well as needing Make to be able to compile the necessary files. 
(Make is included in the above command)<br />
<br />
<br />
Installation:------------------------------------------------------------------<br />
Just run "**make**" in the terminal at the root.
(where the highest Makefile is located)<br />
Alternatively run "**make bonus**" to compile the bonus version of the programm,
which allows for enemy patrols.<br />
Running "**make**" and "**make bonus**" is exclusive and switches the version of
the so_long programm respectively.<br />
<br />
<br />
Starting:----------------------------------------------------------------------<br />
Then run "**./so_long**" followed by a space and the
name of a vaild map file ending in .ber.<br />
Example: "**./so_long empty.ber**"<br />
Example: "**./so_long maps/map1/enemy.ber**"<br />
There is a tutorial below to create valid maps.<br />
<br />
<br />
Maps:--------------------------------------------------------------------------<br />
Maps are provided as text files ending in ".ber".
A line is delimited by being between start of file, 
'\n' and by the end of file.<br />
Maps consist of valid Ascii-Characters. (further info see 'Map Characters')<br />
Maps have to be rectangular.<br />
Maps have to be surrounded in walls on all sides, including diagonals.<br />
Maps need exactly 1 Exit, exactly 1 Player and at least 1 Collectable.<br />

Map Characters:<br />
1 		- 	Wall; that stops movement, they close off the map.<br />
0 		- 	Free space; that anyone can move to.<br />
P 		- 	Player; or their starting position.<br />
E 		- 	Exit; that blocks movement until all collectables have been 
gathered. At which point it opens up and allows the user to win the game.<br />
C 		- 	Collectables; that all need to be gathered in order to win the game.<br />
**The following only works for the bonus version:**<br />
U/D/L/R -	Enemies; which move [U]pward [D]ownward, [L]eft or [R]ight.
They move until they hit anything, at which point they will turn
around next round, turning a [L]eftie into a [R]ight enemy.
After that they will continue moving in this new direction.<br />
Here is a valid map as text:<br />
1111111<br />
1E010C1<br />
1P0C001<br />
1111111<br />
<br />
<br />
Controls:----------------------------------------------------------------------<br />
W/A/S/D	-	to move around<br />
ESC		-	to close the game<br />
Clicking the X in the top right also closes the Game<br />
<br />
<br />
Rules:-------------------------------------------------------------------------<br />
The player moves before the enemies. If the player enters a field,
where an enemy stands, then that enemy is defeated.<br />
Should the player move to a field, and an enemy then move to that field,
the player is defeated.<br />
The player has to move into all collectables and then move into the exit.<br />
Should an enemy move into the player before that, the player will lose.<br />

There are 2 Achievements hidden in the bonus version of the game, can you find them
without looking into the source code?<br />
<br />
<br />
Sprites:-----------------------------------------------------------------------<br />
The player, wall and free sprites were drawn by me and were inspired by Warframe.<br />

The enemy, coin and exit sprites are scaled down and slightly adjusted screenshots of textures from Warfrane.<br />
A picture of a Grineer Elite Soldier for the Enemy, a picture of Endo for the Collectable Texture and some random hatch from a Grineer Tileset on Earth for the Exit.<br />