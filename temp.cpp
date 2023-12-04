#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int minPath(vector<vector<int>>& grid, int x, int y)
{
    int n = grid.size(), m = grid[0].size(), s = grid[y][x];
    
    if(y == n-1) 
    {
        for(int i = x+1; i < m; ++i) s += grid[y][i];
    }
    else if(x == m-1)
    {
        for(int i = y+1; i < n; ++i) s += grid[i][x];
    }
    else
    {
        int down = minPath(grid, x, y+1);
        int right = minPath(grid, x+1, y);
        s += down < right ? down : right;
    }
    cout << "x = " << x << " y = " << y << " S = " << s << endl;
    return s;
}

int main()
{
    int m = 5, n = 1;
    vector<vector<int>> grid(m);
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            grid[i].emplace_back(rand()%10);
        }
    }
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << minPath(grid, 0, 0);
}