#include <iostream>
#include <vector>
using namespace std;

vector<string> answer;
int m, n;
int maze[100][100];
bool ok[100][100];
string s;

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

void test(int i, int j, string s)
{
    if (maze[0][0] == 1 || maze[m - 1][n - 1] == 1)
        return;
    if (i == m - 1 && j == n - 1)
        answer.push_back(s);
    if (maze[i + 1][j] == 0 && i <= m - 2 && !ok[i + 1][j])
    {
        ok[i][j] = true;
        test(i + 1, j, s + "D");
        ok[i][j] = false;
    }
    if (maze[i][j + 1] == 0 && j <= n - 2 && !ok[i][j + 1])
    {
        ok[i][j] = true;
        test(i, j + 1, s + "R");
        ok[i][j] = false;
    }
    if (maze[i - 1][j] == 0 && i >= 1 && !ok[i - 1][j])
    {
        ok[i][j] = true;
        test(i - 1, j, s + "U");
        ok[i][j] = false;
    }
    if (maze[i][j - 1] == 0 && j >= 1 && !ok[i][j - 1])
    {
        ok[i][j] = true;
        test(i, j - 1, s + "L");
        ok[i][j] = false;
    }
}
void setMap(int maze[100][100])
{
    maze[m - 1][n - 1] = 2;
    int i = 0, j = 0, count = 0;
    while (true)
    {
        if (count >= s.size())
            return;
        else
        {
            maze[i][j] = 2;
            if (s[count] == 'D')
                i += 1;
            if (s[count] == 'U')
                i -= 1;
            if (s[count] == 'R')
                j += 1;
            if (s[count] == 'L')
                j -= 1;
            count++;
        }
    }
}

void solve()
{
    answer.clear();
    getMaze(maze, m, n);
    test(0, 0, "");
    s = answer[0];
    if (answer.size() == 0)
        cout << -1;
    else
        setMap(maze);
    printMaze(maze, m, n);
}

int main()
{
    cin >> m >> n;
    solve();
    return 0;
}