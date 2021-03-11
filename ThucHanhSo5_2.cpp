#include <iostream>
using namespace std;

int a[100];
int m, n, k;

int countNumber1(int a[], int k)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == 1)
            count++;
    }
    return count;
}

void printAns(int a[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

void datBang0(int a[], int k, int vt) // đặt các kí tự sau số 1 bằng số 0
{
    for (int i = vt; i < k; i++)
    {
        a[i] = 0;
    }
}


void generateBit(int a[], int k)
{
    int i = k - 1;
    while (i > 0)
    {
        if (a[i] == 1)
            i--; // duyệt từ cuối dãy
        if (a[i] == 0)
        {
            a[i] = 1;
            datBang0(a, k, i + 1); // đặt đặt số 0 bằng 1 và các số sau số đó bằng 0
            if (countNumber1(a, k) == n)
                printAns(a, k);
            i = k - 1; // reset giá trị để duyệt về cuối dãy
        }
    }
}

int main()
{
    cin >> m >> n;
    k = m + n;
    generateBit(a, k);
}
