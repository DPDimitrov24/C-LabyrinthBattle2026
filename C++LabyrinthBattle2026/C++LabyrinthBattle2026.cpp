#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

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

void generateMaze(char** maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j] = '#';
        }
    }

    for (int j = 0; j < size; j++)
    {
        maze[0][j] = ' ';
    }

    for (int i = 0; i < size; i++)
    {
        maze[i][size - 1] = ' ';
    }

    for (int i = 1; i < size - 1; i++)
    {
        for (int j = 1; j < size - 1; j++)
        {
            if (rand() % 100 < 60)
            {
                maze[i][j] = ' ';
            }
        }
    }

    maze[0][0] = ' ';
    maze[size - 1][size - 1] = 'E';
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
                cout << "P ";
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

void showOptions(int& controls)
{
    system("cls");

    cout << "===== OPTIONS =====" << endl;
    cout << endl;

    cout << "1. Arrow Keys" << endl;
    cout << "2. WASD" << endl;

    cout << endl;

    int choice;
    cin >> choice;

    while (choice < 1 || choice > 2)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    controls = choice;
}

void startGame(int controls)
{
    int size;

    cout << "Enter maze size (10-50): ";
    cin >> size;

    while (size < 10 || size > 50)
    {
        cout << "Invalid size. Enter again: ";
        cin >> size;
    }

    char** maze = createMaze(size);

    generateMaze(maze, size);

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
    int choice;

    do
    {
        showMenu();

        cin >> choice;

        while (choice < 1 || choice > 4)
        {
            cout << "Invalid choice. Try again: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            startGame(controls);
            break;

        case 2:
            showTips();
            break;

        case 3:
            showOptions(controls);
            break;
        }

    } while (choice != 4);

    return 0;
}