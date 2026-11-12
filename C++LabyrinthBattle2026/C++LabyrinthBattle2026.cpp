#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void setColor(int color)
{
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color);
}

char** createMaze(int size)
{
    char** maze = new char* [size];

    for (int i = 0; i < size; i++)
    {
        maze[i] = new char[size];
    }

    return maze;
}

void deleteMaze(char** maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}

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

void drawGame(char** maze, int size, int playerRow, int playerCol)
{
    system("cls");

    for (int i = 0; i < size + 2; i++)
    {
        cout << "# ";
    }

    cout << endl;

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

        cout << "#";
        cout << endl;
    }

    for (int i = 0; i < size + 2; i++)
    {
        cout << "# ";
    }

    cout << endl;
}

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

bool isWin(int row, int col, int size)
{
    return row == size - 1 &&
        col == size - 1;
}

void showTips()
{
    system("cls");

    cout << "===== TIPS =====" << endl;
    cout << endl;

    cout << "P = Player" << endl;
    cout << "# = Wall" << endl;
    cout << "E = Exit" << endl;

    cout << endl;

    cout << "Reach the exit in the lower right corner."
        << endl;

    cout << "You cannot move through walls."
        << endl;

    cout << endl;

    cout << "Press any key...";
    _getch();
}

void showMenu()
{
    system("cls");

    cout << "===== LABYRINTH GAME =====" << endl;
    cout << endl;

    cout << "1. New Game" << endl;
    cout << "2. Tips" << endl;
    cout << "3. Options" << endl;
    cout << "4. Exit" << endl;

    cout << endl;
    cout << "Choice: ";
}

void showOptions(int& controls, int& difficulty)
{
    system("cls");

    cout << "===== OPTIONS =====" << endl;
    cout << endl;

    // Selecting controls
    cout << "===== CONTROLS =====" << endl;
    cout << "1. Arrow Keys (Up, Down, Left, Right)" << endl;
    cout << "2. WASD (W, A, S, D)" << endl;

    cout << endl;
    cout << "Choose your controls (1-2): ";

    int choice;
    cin >> choice;

    while (choice < 1 || choice > 2)
    {
        cout << "Invalid choice. Choose 1 or 2: ";
        cin >> choice;
    }

    controls = choice;

    // Selecting difficulty
    cout << endl;
    cout << "===== DIFFICULTY =====" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Normal" << endl;
    cout << "3. Hard" << endl;

    cout << endl;
    cout << "Choose difficulty (1-3): ";

    cin >> choice;

    while (choice < 1 || choice > 3)
    {
        cout << "Invalid choice. Choose 1, 2 or 3: ";
        cin >> choice;
    }

    difficulty = choice;

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

void startGame(int controls, int difficulty)
{
    system("cls");

    cout << "===== NEW GAME ====="
        << endl << endl;

    int size;

    cout << "Enter maze size (10-50): ";
    cin >> size;

    while (size < 10 || size > 50)
    {
        cout << "Invalid size. Enter again: ";
        cin >> size;
    }

    char** maze = createMaze(size);

    generateMaze(maze, size, difficulty);

    int playerRow = 0;
    int playerCol = 0;
    int steps = 0;

    while (!isWin(playerRow, playerCol, size))
    {
        drawGame(
            maze,
            size,
            playerRow,
            playerCol);

        cout << "Steps: " << steps << endl;

        if (controls == 1)
        {
            int key = _getch();

            if (key == 224)
            {
                key = _getch();

                switch (key)
                {
                case 72:
                    if (movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        1))
                    {
                        steps++;
                    }
                    break;

                case 80:
                    if (movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        2))
                    {
                        steps++;
                    }
                    break;

                case 75:
                    if (movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        3))
                    {
                        steps++;
                    }
                    break;

                case 77:
                    if (movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        4))
                    {
                        steps++;
                    }
                    break;
                }
            }
        }
        else
        {
            char key = tolower(_getch());

            switch (key)
            {
            case 'w':
                if (movePlayer(
                    maze,
                    size,
                    playerRow,
                    playerCol,
                    1))
                {
                    steps++;
                }
                break;

            case 's':
                if (movePlayer(
                    maze,
                    size,
                    playerRow,
                    playerCol,
                    2))
                {
                    steps++;
                }
                break;

            case 'a':
                if (movePlayer(
                    maze,
                    size,
                    playerRow,
                    playerCol,
                    3))
                {
                    steps++;
                }
                break;

            case 'd':
                if (movePlayer(
                    maze,
                    size,
                    playerRow,
                    playerCol,
                    4))
                {
                    steps++;
                }
                break;
            }
        }
    }

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

int main()
{
    srand((unsigned)time(0));

    int controls = 1;
    int difficulty = 2;
    int choice;

    do
    {
        showMenu();
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
}