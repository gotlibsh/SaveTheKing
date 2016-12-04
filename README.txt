1.Title:
	Save The king

2.Written by:
	a.Name:	Shlomo Gottlieb, 	Id:313377145
	b.Name:	Naftali Lewenstein, Id:302538517

3.General Explanation:
	This program is a multifunctional game, the goal of the game is to get the king to the Throne.
	There is in default 3 boards to the game, you may add more as you wish.
	There are a few charecters in the game:
	a.King Symbol:	'K' - Can move in any direction but can't do anything else, when he gets to the Throne you won the game.
	b.Thief Symbol:	'T' - Can open a gate in case that he has a key, A thief can't carry more than one key at a time.
	c.Giant Symbol:	'G' - The Giant moves the midgets back to there home base.
	d.Mage Symbol:	'M' - The mage's job is to turn off fire.
	e.Midget Symbol:'^' - Are in the game mainly to disturb the charecters from moving arround.

4.Detailed Explanation:
	a.Main - Loads the file 'levels.txt' which has the actual drawing of the board, and calls the controller.
	b.Controller - The "core of the program". 
		Controller Main functionalities:
		1.Starts a new level by reading 'levels.txt'(level by level till:EOF) and inserts the text drawing into a 2D vector of strings.
		2.Sends the vector to board and gets back a 2D vector of bricks
		3.Now the game is ready to run, every move of characters made by the user is modified by a function called "stepTo" which is in each of the character's class.
	c.Point - Holds a point as x and y coordinates.
	d.Utilities - Holds main functions and enums (Active-Char, Key-Press, Brick-State).
	e.Board - Holds the board to draw after each move or update.
		Board Main functionalities:
		1.Sets a 2D vector of bricks given a describing vector of the file.
		2.Returns a neighbor of a given point and direction.
		3.Prints the board down to the console.
	f.Brick - Holds the state of a brick (Fire, Gate, Wall, Key, Throne) and it's point on the board (+ getters/setters).
	g.Characters - Each character's class holds his place, stepTo policy, is-above-a-key, and more.

5.Format of the levels file:
	The File "levels.txt" holds the board of the game, by default there are three levels.
	a.Every level must be framed with '='.
	b.No tabs allowed.
	c.Level ends with '$$$' (in a new line).
	d.All charecters must exist in every level.
	e.You can't have empty lines in the middle of a level.
	f.Adding a level is simple, Just go to "levels.txt". 


6.File list:
	Header Files:
	Controller.h - In-charge on the run of the game.
	Board.h - Holds the board of the game.
	Utilities.h - The tool-box of the program takes care of the keyboard etc.
	Point.h - Holds the place of characters and bricks.
	Brick.h - Holds the details of a specific brick.
	King.h - The main character of the game, the game is done when he gets to the throne.
	Giant.h - Character that scares the midgets away to their home base.
	Mage.h - Character that turns off fire.
	Thief.h - Character that can open a gate if he has stolen key.
	Midget.h - Character that blocks the other characters.
	
	Source Files:
	Main.cpp
	Controller.cpp
	Board.cpp
	Utilities.cpp
	Brick.cpp
	King.cpp
	Giant.cpp
	Mage.cpp
	Thief.cpp
	Midget.cpp

	Text Files:
	README.txt- This file.
	opening.txt - The welcoming of the game.
	ending.txt - The Well Done message when the game is finished successfully.
	levels.txt - The text that holds the 3 boards.

7.Data structures:
	a.Board generates a vector of vectors of bricks.
	b.Every character holds his own place on board, and he knows his functionalities.
 
8.Algorithim's:

9.Bugs:

10.Notes:
	Go Have Fun!