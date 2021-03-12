#include <iostream>
using namespace std;

int a[100];
int n;

void printAns(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void datBang0(int a[], int n, int vt) // đặt các kí tự sau số 1 bằng số 0
{
    for (int i = vt; i < n; i++)
    {
        a[i] = 0;
    }
}

void generateBit(int a[], int n)
{
    printAns(a, n);
    int i = n - 1;
    while (i > 0)
    {
        if (a[i] == 1)
            i--; // duyệt từ cuối dãy
        if (a[i] == 0)
        {
            a[i] = 1;
            datBang0(a, n, i + 1); // đặt đặt số 0 bằng 1 và các số sau số đó bằng 0
            printAns(a, n);
            i = n - 1; // reset giá trị để duyệt về cuối dãy
        }
    }
}

int main()
{
    cin >> n;
    generateBit(a, n);
}
