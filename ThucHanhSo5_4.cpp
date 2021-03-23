#include <iostream>
#include <string>

using namespace std;

void gen4(string s, int len, string s1, int i)
{

    string s2 = "";
    for(int j = 0; j < len; j ++)
    {
        char x = s[j];

        s2 = s1 + x;
        if(s2.length() == i)
        {
            cout << s2 << endl;
        }
        else
        {
            gen4(s, len, s2, i);
        }
    }
}

int main()
{

    string s;
    cin >> s;
    int len = s.length();
    string s1 = "";
    for(int i = 1; i <= len; i++)
    {
        gen4(s, len, "", i);
    }
    return 0;
}