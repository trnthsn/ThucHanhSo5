#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void print(char a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    char a[20];
    cin >> a;
    int len;
    len = strlen(a);

    do
    {
        print(a, len);
    }
    while ( next_permutation(a, a + len) );
    return 0;
}