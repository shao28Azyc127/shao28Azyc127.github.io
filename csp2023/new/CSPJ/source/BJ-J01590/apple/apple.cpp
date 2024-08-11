#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dp[1000005];
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    //solve1(n);
    //if(n>1000000) cout<<
    //else{
    dp[1]=1,dp[2]=2,dp[3]=3;
    for(int i=4;i<=n;++i){
        dp[i]=dp[(int)(i-ceil((double)i/3.0))]+1;
    }
    cout<<dp[n]<<' ';
    memset(dp,0,sizeof dp);
    dp[1]=1,dp[2]=2,dp[3]=3;
    for(int i=4;i<=n;++i){
        if(i%3==1) dp[i]=1;
        else dp[i]=dp[(int)(i-ceil((double)i/3.0))]+1;
    }
    cout<<dp[n]<<' ';
    //}
    return 0;
}
/*

*/

/*
7 1
8 5
9 3
10 1
11 2
12 6
13 1
14 4
15 2
16 1
17 3
18 7
19 1
20 2
21 5
22 1
23 3
24 2
25 1
26 4
27 8
*/
