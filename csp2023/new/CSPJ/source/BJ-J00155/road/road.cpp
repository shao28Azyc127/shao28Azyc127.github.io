#include<bits/stdc++.h>
using namespace std;
long long dp[100000];
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    long long n , d;
    long long a[100000] , v[100000];
    cin >> n >> d;
    for(int i = 1;i <= n-1;i++)scanf("%lld" , &a[i]);
    for(int i = 1;i <= n;i++)scanf("%lld" , &v[i]);
    for(int i = 2;i <= n;i++){
        long long mi = INT_MAX;
        for(int j = 1;j < i;j++){
            int tsum = 0;
            for(int k = j+1;k <=i;k++){
                tsum += a[k];
            }
            int tv = 0;
            if(tsum % d == 0)tv = tsum / d;
            else tv = tsum / d +1;
            mi = min(mi , a[j]*tv+dp[j]);
        }
        dp[i] = mi;
    }
    cout << dp[n]-1;
    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/
