#include <bits/stdc++.h>
using namespace std;

int search(int maze[15][20], int rows, int cols, int target)
{
    int row = 0, col = cols - 1;
    while (row < rows && col > -1)
    {
        if (maze[row][col] == target)
            return row * 20 + col;
        else if (maze[row][col] < target)
            row++;
        else
            col--;
    }
    return -1;
}

int main()
{
    int maze[15][20], count = 0;
    for (int row = 0; row < 15; row++)
        for (int col = 0; col < 20; col++)
            maze[row][col] = count++;
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 20; col++)
        {
            cout << maze[row][col] << " ";
        }
        cout << endl;
    }
    int target;
    cout << "Enter Target: ";
    cin >> target;
    int ans = search(maze, 15, 20, target);
    if (ans != -1)
        cout << "Index of target element as per Row Major Order: " << ans << endl;
    else
        cout << "Target element not present: " << ans << endl;
}
