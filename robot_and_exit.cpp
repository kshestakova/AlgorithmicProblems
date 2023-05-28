/*
Imagine you have a field of cells and a robot on it. 
Robot stands on coordinates (1, 1) and can only move up and right.
It also can't cross the field borders.

Somewhere at the field there is a door.
You should count the number of ways by which robot can reach this door.   
*/

#include <iostream>
#include <vector>

// field size
const int HEIGHT = 5, WIDTH = 6;
// door coordinates - upper right corner (width-1, height-1)
const int A = 4, B = 5;
// it is guaranteed that the door is inside the field

int helper(int x, int y, std::vector<std::vector<int>>& ways)
{
    // number of ways for robot's initial place
    if(x == 0 && y == 0) return 1;
    // if the cell is out of the field, there is no way to reach it
    // look only to the right and bottom edges
    // because we go from the door to the robot
    if(x < 0 || y < 0) return 0;
    // return the value calculated previously
    if(ways[x][y] != 0) return ways[x][y];
    // else calculate value, add it to array and return it
    ways[x][y] = helper(x-1, y, ways) + helper (x, y-1, ways);
    return ways[x][y];
}

int main()
{
    // create matix to calculate values for every potential cell 
    // to avoid multiple calculations inside the recurrent function
    std::vector<std::vector<int>> nWays (HEIGHT, std::vector<int>(WIDTH, 0));

    int result = helper(A, B, nWays);

    std::cout << result << std::endl;

    // let's show the matrix woth number of ways
    for(int i = HEIGHT - 1; i >= 0; --i)
    {
        for(int j = 0; j < WIDTH; ++j)
        {
            std::cout << nWays[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}