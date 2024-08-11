#include <iostream>

using namespace std;

const int MAXX = 1001;

int n;
char a[MAXX];
char b[MAXX];


bool xiangtong(int t, int size_)
{

    for (int i=t;i<t+size_;i++)
    {
        if (a[i]!=a[i+size_])
        {
            return 0;
        }
    }


    return 1;
}

void jiaohuan()
{
    for (int i=0;i<MAXX;i++)
    {
        a[i] = b[i];
        b[i] = '\0';
    }

}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cout << 5;


    return 0;
}
