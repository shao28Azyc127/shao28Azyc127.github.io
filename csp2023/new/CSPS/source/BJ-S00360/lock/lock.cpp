#include <iostream>
#define N 9
using namespace std;
int a[6][N];
int main()
{
freopen("lock.in", "r", stdin);
freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin >> a[1][i] >> a[2][i] >> a[3][i] >> a[4][i] >> a[5][i];
    }/*
    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j <= )
    }*/
    return 0;
}
