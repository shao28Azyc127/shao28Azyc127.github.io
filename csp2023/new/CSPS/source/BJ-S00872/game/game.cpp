#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2e6 + 5;
char c[MAXN];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = true;
    cin >> c[1];
    for(int i = 2; i <= n; i++)
    {
        cin >> c[i];
        if(c[i] != c[i - 1])
        {
            flag = false;
        }
    }
    if(flag)
    {
        cout << n / 2;
    }
    return 0;
}
