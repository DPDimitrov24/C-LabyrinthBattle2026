#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void menu();

char** createMaze(int size);
void deleteMaze(char** maze, int size);

void generateMaze(char** maze, int size);

void drawMaze(
    char** maze,
    int size,
    int playerRow,
    int playerCol);

bool movePlayer(
    char** maze,
    int size,
    int& playerRow,
    int& playerCol,
    int direction);

bool isWin(
    int playerRow,
    int playerCol,
    int size);

// Creating labyrinth
char** createMaze(int size)
{
    char** maze = new char* [size];

    for (int i = 0; i < size; i++)
    {
        maze[i] = new char[size];
    }

    return maze;
}

// Deleting labyrinth
void deleteMaze(char** maze, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}

// Генериране на лабиринта
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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (rand() % 100 < 60)
            {
                maze[i][j] = ' ';
            }
        }
    }

    maze[size - 1][size - 1] = 'E';
}

// Изобразяване на лабиринта
void drawMaze(
    char** maze,
    int size,
    int playerRow,
    int playerCol)
{
    system("cls");

    for (int i = 0; i < size; i++)
    {
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

        cout << endl;
    }
}

// Проверка за победа
bool isWin(
    int playerRow,
    int playerCol,
    int size)
{
    return playerRow == size - 1 && playerCol == size - 1;
}

// Движение на играча
bool movePlayer(
    char** maze,
    int size,
    int& playerRow,
    int& playerCol,
    int direction)
{
    int newRow = playerRow;
    int newCol = playerCol;

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

    playerRow = newRow;
    playerCol = newCol;

    return true;
}

// Меню
void menu()
{
    cout << "===== LABYRINTH BATTLE 2026 =====" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Exit" << endl;
}

// Главна функция
int main()
{
    srand((unsigned int)time(0));

    menu();

    int choice;
    cout << "Choose: ";
    cin >> choice;

    if (choice == 1)
    {
        int size;

        do
        {
            cout << "Size (10-50): ";
            cin >> size;
        } while (size < 10 || size > 50);

        char** maze = createMaze(size);

        generateMaze(maze, size);

        int playerRow = 0;
        int playerCol = 0;

        while (!isWin(playerRow, playerCol, size))
        {
            drawMaze(
                maze,
                size,
                playerRow,
                playerCol);

            int key = _getch();

            if (key == 224)
            {
                key = _getch();

                switch (key)
                {
                case 72:
                    movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        1);
                    break;

                case 80:
                    movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        2);
                    break;

                case 75:
                    movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        3);
                    break;

                case 77:
                    movePlayer(
                        maze,
                        size,
                        playerRow,
                        playerCol,
                        4);
                    break;
                }
            }
        }

        drawMaze(
            maze,
            size,
            playerRow,
            playerCol);

        cout << "YOU WIN!!!" << endl;

        deleteMaze(maze, size);
    }

    else if (choice == 2)
    {
        cout << "Goodbye!" << endl;
    }

    return 0;
}