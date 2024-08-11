#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


int n;
int a[8][5];
int d = 0;
bool s = false;
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
        cin >> a[i][j];
    if (n == 1)
        cout << 81 << endl;
    return 0;
}
