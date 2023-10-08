#include <iostream>

using namespace std;

// Size all the mazes
const int ROWS = 5;
const int COLS = 5;

// Recursive function to find the path to the exit
bool FindPath(int x, int y, char maze[ROWS][COLS])
{
    // Check if the current position is out of bounds or a wall
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 'X')
    {
        return false;
    }

    // Exit is found when the current position is 'E'
    if (maze[x][y] == 'E')
    {
        return true;
    }
    // Checking if the current position has already been visited
    if (maze[x][y] == 'V')
    {
        return false;
    }
    // Mark the current position as visited
    if (maze[x][y] == ' ')
    {
        maze[x][y] = 'V';
    }

    // Recursively checking all four directions
    if (FindPath(x + 1, y, maze) || FindPath(x - 1, y, maze) || FindPath(x, y + 1, maze) || FindPath(x, y - 1, maze))
    {
        return true;
    }

    return false;
}
// Function to solve the maze and give an output
void SolveMaze(char maze[ROWS][COLS], const string &MazeName)
{
    // Help For testing
    cout << "This is " << MazeName << endl;

    // Gives the starting position in the maze, and prints an messege if true or false.
    if (FindPath(1, 1, maze))
    {
        // True
        cout << "Path to exit found, thus True" << endl;
    }
    else
    {
        // False
        cout << "No path to exit, thus False" << endl;
    }
}

int main()
{
    char maze1[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'E', 'X', 'X', 'X'}};

    char maze2[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'X', 'X', 'E', 'X'}};

    char maze3[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'X', 'X', 'X', 'X'}};

    char maze4[ROWS][COLS] = {
        {'X', 'X', 'X', 'E', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'X', 'X', 'X', 'X'}};

    char maze5[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'X', 'E', 'X', 'X'}};

    SolveMaze(maze1, "Maze 1"); // True
    SolveMaze(maze2, "Maze 2"); // True
    SolveMaze(maze3, "Maze 3"); // False
    SolveMaze(maze4, "Maze 4"); // True
    SolveMaze(maze5, "Maze 5"); // False - can't see the E in conners.

    return 0;
}
