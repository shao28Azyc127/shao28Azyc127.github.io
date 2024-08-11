#include<bits/stdc++.h>
#define MaxN 100010
#define int long long
using namespace std;
/*
    dp[i][j] 表示用户在第i天已经跑了j天步
*/
long long dp[2][MaxN],c,t;
struct chall{
    int y,v;
};
vector<chall> num[MaxN];
void init(){
    memset(num,0,sizeof(num));
    memset(dp,0,sizeof(dp));
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >>c >>t;
    while(t--){
        init();
        int n,m,k,d;
        cin >> n >> m >>k>>d;
        for(int i = 0;i<m;i++){
            chall a;
            int x;
            cin >> x;
            cin >> a.y >> a.v;
            num[x].push_back(a);
        }
        dp[0][0] = 0;
        for(int i =1;i<=n;i++){
            int f = (i-1)&1,l = i&1;
            int mnum = 0;
            for(int j = 1;j<=k&&j<=i;j++){
                dp[l][j] = dp[f][j-1] - d;
                mnum = max(dp[f][j-1],mnum);
                for(int k = 0;k<num[i].size();k++){
                    if(num[i][k].y<=j){
                        dp[l][j] += num[i][k].v;
                    }
                }
            }
            mnum = max(dp[f][min(i,k)],mnum);
            dp[l][0] = mnum;
        }
        int r = n&1;
        int ans = 0;
        for(int i = 0;i<=k;i++){
            ans = max(ans,dp[r][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
