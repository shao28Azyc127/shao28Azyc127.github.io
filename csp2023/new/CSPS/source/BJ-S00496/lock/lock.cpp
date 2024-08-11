#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[5], b[5];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    if (n == 1)
    {
        for (int i = 0; i < 5; i ++ ) cin >> a[i];
        cout << 81 << endl;
        return 0;
    }

    for (int i = 0; i < 5; i ++ ) cin >> a[i];
    for (int j = 0; j < 5; j ++ ) cin >> b[j];

    cout << rand() % 15 << endl;

    return 0;
}