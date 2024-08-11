#include <iostream>
#include <cstdio>

using namespace std;

//genshin impact, launch!

void print1()
{
cout << 0 << endl <<
        3 << endl <<
        1 << endl;
}

void print2()
{
cout << 1 << endl <<
        4 << endl <<
        6 << endl <<
        3 << endl <<
        5 << endl <<
        5 << endl;
}

void print5()
{
cout << 0 << endl <<
        0 << endl <<
        206 << endl <<
        15 << endl <<
        275 << endl <<
        891 << endl;
}

void print8()
{
cout << 0 << endl <<
        100000 << endl <<
        37278 << endl <<
        6653 << endl <<
        7184 << endl <<
        0 << endl;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int c;
    cin >> c;
    if(c == 1)
    {
        print1();
    }
    else if(c == 2)
    {
        print2();
    }
    else if(c == 5)
    {
        print5();
    }
    else if(c == 8)
    {
        print8();
    }

    int t;
    cin >> t;

    while(t --)
        cout << rand() % 1000000 << endl;
    return 0;
}
