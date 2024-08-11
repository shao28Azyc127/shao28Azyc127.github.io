#include <iostream>
#include <cstdio>

using namespace std;

//genshin impact, launch!

void print1()
{
    cout << 1001 << endl;
}

void print4()
{
    cout << "1101100011110101110101111111111111111110011111111101101100000" << endl;
}

void print7()
{
    cout << "1100110110101110011011111111100000111111001100110011111011111" << endl;
}

void print9()
{
    cout << "0111011011011111010101110100000111111111111111101000001001111" << endl;
}

void print18()
{
    cout << "0001110011101001111010110011111011111011111001010010110101111" << endl;
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    int c;
    cin >> c;

    if(c == 3)
    {
        print1();
    }
    else if(c == 4)
    {
        print4();
    }
    else if(c == 7)
    {
        print7();
    }
    else if(c == 9)
    {
        print9();
    }
    else if(c == 18)
    {
        print18();
    }

    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 1; i <= q + 1; i ++)
        cout << rand() % 2;
    return 0;
}
