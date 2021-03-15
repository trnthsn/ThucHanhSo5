#include <iostream>
#include <vector>
using namespace std;

vector <string> answer;
int m, n;
int maze[100][100];
bool ok[100][100];

void getMaze(int maze[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
}

void printMaze(int maze[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << '\n';
    }
}

void test (int i, int j, string s)
{
    if (maze[0][0] == 1 || maze[m - 1][n - 1] == 1)
        return;
    if (i == m - 1 && j == n - 1)
        answer.push_back(s);
    if (maze[i + 1][j] == 0 && i <= m - 2 && !ok[i + 1][j] )
    {
        ok[i][j] = true;
        test (i + 1, j, s + "D");
        ok[i][j] = false;
    }
    if (maze[i][j + 1] == 0 && j <= n - 2 && !ok[i][j + 1] )
    {
        ok[i][j] = true;
        test (i, j + 1, s + "R");
        ok[i][j] = false;
    }
    if (maze[i - 1][j] == 0 && i >= 1 && !ok[i - 1][j] )
    {
        ok[i][j] = true;
        test (i - 1, j, s + "U");
        ok[i][j] = false;
    }
    if (maze[i][j - 1] == 0 && j >= 1 && !ok[i][j - 1] )
    {
        ok[i][j] = true;
        test (i, j - 1, s + "L");
        ok[i][j] = false;
    }
}

void solve()
{
    answer.clear();
    getMaze(maze, m, n);
    test (0, 0, "");
    if (answer.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i];
        }
    // printMaze(maze, m, n);
}

int main()
{
    cin >> m >> n;
    solve();
    return 0;
}
