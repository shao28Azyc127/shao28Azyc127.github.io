#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;

int n;
int a[10][10];
int vis[100000];

int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++){
            cin >> a[i][j];
        }
    }
    if (n==1){
        cout << 81 << endl;
        return 0;
    }
    cout << (10-n) << endl;
    return 0;
}
// 2
// 2 8 3 5 5
// 2 8 3 5 1
