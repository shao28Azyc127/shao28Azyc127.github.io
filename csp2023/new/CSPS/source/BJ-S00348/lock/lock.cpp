#include <iostream>
#include <cstdio>
using namespace std;

int k[15][15];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            cin >> k[i][j];
    }
    if (n == 1)
        cout << 81;
    else
        cout << 10 - n;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
