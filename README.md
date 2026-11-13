🏰 ABERMaze

A console-based maze game developed in C++ using dynamic memory allocation, functions, and procedural programming principles.

The player must navigate through a randomly generated maze and reach the exit while avoiding walls and dead ends.

📖 About the Project

ABERMaze is a school project designed to demonstrate:

Dynamic memory allocation
Two-dimensional dynamic arrays
Function decomposition
Input validation
Menu-driven applications
Game logic implementation
Console graphics
Player movement and collision detection

The maze is generated every time the game starts, ensuring a different experience for each playthrough.

✨ Features

✅ Randomly generated maze

✅ User-selected maze size (10x10 to 50x50)

✅ Dynamic memory allocation (char**)

✅ Main menu system

✅ Tips / Help menu

✅ Options menu

✅ Multiple control schemes:

Arrow Keys
WASD

✅ Difficulty settings:

Easy
Normal
Hard

✅ Step counter

✅ Colored player and exit

✅ Input validation

✅ Wall collision detection

✅ Win condition checking

✅ Automatic memory cleanup

🎮 Controls
Arrow Keys Mode
Key	Action
↑	Move Up
↓	Move Down
←	Move Left
→	Move Right
WASD Mode
Key	Action
W	Move Up
S	Move Down
A	Move Left
D	Move Right
🗺️ Maze Rules
The player starts in the upper-left corner (0,0).
The exit is located in the lower-right corner.
Walls cannot be crossed.
The player wins after reaching the exit.
Every generated maze contains a valid path to the exit.
🛠️ Technologies Used
C++
Visual Studio
Windows Console
Dynamic Arrays
Random Number Generation
Keyboard Input Handling
Required Libraries
C++
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
📂 Project Structure
Function	Description
createMaze()	Allocates the maze dynamically
deleteMaze()	Frees allocated memory
generateMaze()	Generates the maze layout
drawGame()	Draws the maze and player
movePlayer()	Handles player movement
isWin()	Checks if the player reached the exit
showMenu()	Displays the main menu
showTips()	Displays game instructions
showOptions()	Displays settings
startGame()	Runs the gameplay loop
main()	Controls program execution
💾 Memory Management

The maze is stored in dynamically allocated memory:

C++
char** maze;

Using dynamic allocation allows the maze size to be determined during program execution rather than compile time.

Memory is released after each game using:

C++
delete[];

to prevent memory leaks.

🏆 Win Condition

The player wins when their position matches the exit coordinates:

C++
(size - 1, size - 1)

The game then displays a victory message along with the total number of steps taken.

🚀 How to Run
Open the project in Visual Studio.
Build the solution.
Run the program.
Select a maze size.
Choose your preferred controls.
Reach the exit and win the game.

👨‍💻 Author

With lots of love ❤️ Dimitar Petrov Dimitrov

ABERMaze - C++ Maze Project
