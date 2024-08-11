#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[10][10];
int ans[10][100005] = {0};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin>>a[i][j];
            a[i][0] = a[i][1] + a[i][2] * 10 + a[i][3] * 100 + a[i][4] * 1000 + a[i][5] * 10000;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 9;j++){
            ans[i][((a[i][1] + j) % 10) + a[i][2] * 10 + a[i][3] * 100 + a[i][4] * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + ((a[i][2] + j) % 10) * 10 + a[i][3] * 100 + a[i][4] * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + a[i][2] * 10 + ((a[i][3] + j) % 10) * 100 + a[i][4] * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + a[i][2] * 10 + a[i][3] * 100 + ((a[i][4] + j) % 10) * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + a[i][2] * 10 + a[i][3] * 100 + a[i][4] * 1000 + ((a[i][5] + j) % 10) * 10000] = 1;
        }
        for(int j = 1;j <= 9;j++){
            ans[i][((a[i][1] + j) % 10) + ((a[i][2] + j) % 10) * 10 + a[i][3] * 100 + a[i][4] * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + ((a[i][2] + j) % 10) * 10 + ((a[i][3] + j) % 10) * 100 + a[i][4] * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + a[i][2] * 10 + ((a[i][3] + j) % 10) * 100 + ((a[i][4] + j) % 10) * 1000 + a[i][5] * 10000] = 1;
            ans[i][a[i][1] + a[i][2] * 10 + a[i][3] * 100 + ((a[i][4] + j) % 10) * 1000 + ((a[i][5] + j) % 10) * 10000] = 1;
        }
    }
    for(int j = 0;j < 1e5;j++){
        int flag = 1;
        for(int i = 1;i <= n;i++){
            if(!ans[i][j])
                flag = 0;
        }
        //if(flag)
            //cout<<j<<endl;
        ans[0][0] += flag;
    }
    cout<<ans[0][0];
    return 0;
}


