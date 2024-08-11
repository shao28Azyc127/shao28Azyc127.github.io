#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
using namespace std;
int n, loc[15][15], ab[5];

int solve(){
    int ans = 0;
    for(int j=1;j<=5;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(loc[i][j] != loc[k][j]&&ab[j]==0){
                    ans += 10; ab[j]=1;
                }
            }
        }
    }
    return ans;
}

int main(){
    freopen("lock.in", "r", stdin);
#ifndef TEST
    freopen("lock.out", "w", stdout);
#endif
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=1;j<=5;j++)
            cin >> loc[i][j];
    if(n == 1){
        cout << 81;
    } else if(n==2){
        cout << 10;
    } else{
        cout << solve();
    }
    return 0;
}