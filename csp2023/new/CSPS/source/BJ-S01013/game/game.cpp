#include <bits/stdc++.h>
using namespace std;
const int N = 2000000;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    char a[N];
    int n;
    int m = 0;
    int sum = 0;
    cin >> n;
    char b[n][n*n];
    int c[n*n] = {0};
    stack <char>q[n*n];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i+1;j++){
            m++;
            for(int k = 0;k <= i-1;k++){
                b[m][k+1] = a[j+k];
                c[m]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= c[i];j++){
            if(q[i].size() == 0)
                q[i].push(b[i][j]);
            else if(q[i].top() == b[i][j]){
                q[i].pop();
            }
            else
                q[i].push(b[i][j]);
        }
        if(q[i].size() == 0)
            sum++;
    }
    cout << sum ;
    return 0;
}
