#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <conio.h>
#include <windows.h>
#include <limits>

using namespace std;

// ==========================================
// ENTERING NUMBERS
// ==========================================

int readIntInRange(const char* prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << prompt;

        if (cin >> value)
        {
            if (value >= minValue && value <= maxValue)
            {
                return value;
            }

            cout << "Invalid choice. Try again." << endl;
        }
        else
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            cout << "Please enter a valid number." << endl;
        }
    }
}

// ==========================================
// COLORS
// ==========================================

void setColor(int color)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color);
}

// ==========================================
// CREATING THE MAZE
// ==========================================

char** createMaze(int size)
{
    char** maze = new char* [size];

    for (int i = 0; i < size; i++)
    {
        maze[i] = new char[size];
    }

    return maze;
}

// ==========================================
// DELETING THE MAZE
// ==========================================

void deleteMaze(char** maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}

// ==========================================
// GENERATING THE MAZE
// ==========================================

void generateMaze(char** maze, int size, int difficulty)
{
    int wallChance = 40;

    switch (difficulty)
    {
    case 1:
        wallChance = 20;
        break;

    case 2:
        wallChance = 40;
        break;

    case 3:
        wallChance = 60;
        break;
    }

    // Filling with walls

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Open first line

    for (int j = 0; j < size; j++)
    {
        maze[0][j] = ' ';
    }

    // Open last collum

    for (int i = 0; i < size; i++)
    {
        maze[i][size - 1] = ' ';
    }

    // Random generating the inside cells

    for (int i = 1; i < size - 1; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            if (rand() % 100 >= wallChance)
            {
                maze[i][j] = ' ';
            }
        }
    }

    maze[0][0] = ' ';
    maze[size - 1][size - 1] = 'E';
}

// ==========================================
// IMAGING THE GAME
// ==========================================

void drawGame(char** maze, int size, int playerRow, int playerCol)
{
    system("cls");

    // Up border

    for (int i = 0; i < size + 2; i++)
    {
        cout << "# ";
    }

    cout << endl;

    // Maze

    for (int i = 0; i < size; i++)
    {
        cout << "# ";

        for (int j = 0; j < size; j++)
        {
            if (i == playerRow && j == playerCol)
            {
                setColor(10);
                cout << "P ";
                setColor(7);
            }
            else if (maze[i][j] == 'E')
            {
                setColor(12);
                cout << "E ";
                setColor(7);
            }
            else
            {
                cout << maze[i][j] << ' ';
            }
        }

        cout << "#" << endl;
    }

    // Down border

    for (int i = 0; i < size + 2; i++)
    {
        cout << "# ";
    }

    cout << endl;
}

// ==========================================
// PLAYER MOTION
// ==========================================

bool movePlayer(
    char** maze,
    int size,
    int& row,
    int& col,
    int direction)
{
    int newRow = row;
    int newCol = col;

    switch (direction)
    {
    case 1:
        newRow--;
        break;

    case 2:
        newRow++;
        break;

    case 3:
        newCol--;
        break;

    case 4:
        newCol++;
        break;

    default:
        return false;
    }

    if (newRow < 0 ||
        newCol < 0 ||
        newRow >= size ||
        newCol >= size)
    {
        return false;
    }

    if (maze[newRow][newCol] == '#')
    {
        return false;
    }

    row = newRow;
    col = newCol;

    return true;
}

// ==========================================
// CHECK FOR VICTORY
// ==========================================

bool isWin(int row, int col, int size)
{
    return row == size - 1 &&
        col == size - 1;
}

// ==========================================
// TIPS
// ==========================================

void showTips()
{
    system("cls");

    cout << "===== TIPS =====" << endl;
    cout << endl;

    cout << "P = Player" << endl;
    cout << "# = Wall" << endl;
    cout << "E = Exit" << endl;

    cout << endl;

    cout << "Reach the exit in the lower right corner." << endl;
    cout << "You cannot move through walls." << endl;

    cout << endl;

    cout << "Press any key...";

    _getch();
}

// ==========================================
// MAIN MENU
// ==========================================

void showMenu()
{
    system("cls");

    cout << "===== ABERMaze =====" << endl;
    cout << endl;

    cout << "1. New Game" << endl;
    cout << "2. Tips" << endl;
    cout << "3. Options" << endl;
    cout << "4. Exit" << endl;

    cout << endl;
}

// ==========================================
// SETTINGS
// ==========================================

void showOptions(int& controls, int& difficulty)
{
    system("cls");

    cout << "===== OPTIONS =====" << endl;
    cout << endl;

    // Selecting controls

    cout << "===== CONTROLS =====" << endl;

    cout << "1. Arrow Keys" << endl;
    cout << "2. WASD" << endl;

    cout << endl;

    controls = readIntInRange(
        "Choose controls (1-2): ",
        1,
        2);

    // Selecting difficulty

    cout << endl;
    cout << "===== DIFFICULTY =====" << endl;

    cout << "1. Easy" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Hard" << endl;

    cout << endl;

    difficulty = readIntInRange(
        "Choose difficulty (1-3): ",
        1,
        3);

    // Approving

    system("cls");

    cout << "===== SETTINGS SAVED =====" << endl;
    cout << endl;

    cout << "Controls: ";

    if (controls == 1)
        cout << "Arrow Keys" << endl;
    else
        cout << "WASD" << endl;

    cout << "Difficulty: ";

    if (difficulty == 1)
        cout << "Easy" << endl;
    else if (difficulty == 2)
        cout << "Normal" << endl;
    else
        cout << "Hard" << endl;

    cout << endl;
    cout << "Press any key to continue...";

    _getch();
}

// ==========================================
// GAME STARTING
// ==========================================

void startGame(int controls, int difficulty)
{
    system("cls");

    cout << "===== NEW GAME =====" << endl;
    cout << endl;

    int size = readIntInRange(
        "Enter maze size (10-50): ",
        10,
        50);

    char** maze = createMaze(size);

    generateMaze(maze, size, difficulty);

    int playerRow = 0;
    int playerCol = 0;
    int steps = 0;

    // Main game (while)

    while (!isWin(playerRow, playerCol, size))
    {
        drawGame(
            maze,
            size,
            playerRow,
            playerCol);

        cout << "Steps: " << steps << endl;

        int direction = 0;

        // Arrow keys controls

        if (controls == 1)
        {
            int key = _getch();

            if (key == 0 || key == 224)
            {
                key = _getch();

                switch (key)
                {
                case 72:
                    direction = 1;
                    break;

                case 80:
                    direction = 2;
                    break;

                case 75:
                    direction = 3;
                    break;

                case 77:
                    direction = 4;
                    break;
                }
            }
        }

        // WASD controls

        else
        {
            int key = tolower(
                static_cast<unsigned char>(_getch()));

            switch (key)
            {
            case 'w':
                direction = 1;
                break;

            case 's':
                direction = 2;
                break;

            case 'a':
                direction = 3;
                break;

            case 'd':
                direction = 4;
                break;
            }
        }

        // Motion performance

        if (direction != 0)
        {
            if (movePlayer(
                maze,
                size,
                playerRow,
                playerCol,
                direction))
            {
                steps++;
            }
        }
    }

    // Victory

    drawGame(
        maze,
        size,
        playerRow,
        playerCol);

    cout << endl;
    cout << "YOU WIN!" << endl;
    cout << "Steps: " << steps << endl;

    cout << endl;
    cout << "Press any key...";

    _getch();

    deleteMaze(maze, size);
}

// ==========================================
// MAIN
// ==========================================

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int controls = 1;
    int difficulty = 2;
    int choice;

    do
    {
        showMenu();

        // Showing current settings

        cout << "Current controls: ";

        if (controls == 1)
            cout << "Arrow Keys";
        else
            cout << "WASD";

        cout << endl;

        cout << "Current difficulty: ";

        if (difficulty == 1)
            cout << "Easy";
        else if (difficulty == 2)
            cout << "Normal";
        else
            cout << "Hard";

        cout << endl << endl;

        choice = readIntInRange(
            "Choice: ",
            1,
            4);

        switch (choice)
        {
        case 1:
            startGame(controls, difficulty);
            break;

        case 2:
            showTips();
            break;

        case 3:
            showOptions(controls, difficulty);
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}
