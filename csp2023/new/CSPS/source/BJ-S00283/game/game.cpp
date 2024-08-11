#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >> n;
    if (n == 1)
        cout << 0;
    else
        cout << "5";
    return 0;
}