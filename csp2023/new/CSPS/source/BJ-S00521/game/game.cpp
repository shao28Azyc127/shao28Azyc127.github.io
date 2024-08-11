#include<bits/stdc++.h>
#define MaxN 2000010
using namespace std;
int dp[MaxN][30],n;
long long cnt[MaxN],ans[MaxN];
char nums[MaxN];
/*
dp[i] 表示第i个可以消除到dp[i]
cnt[i] 表示到第i个有cnt[i]个连续数列可以消除
ans[i] 表示到第i个总共有ans[i]个数列可以消除
*/
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> nums[i];
    }
    for(int i = 2;i<=n;i++){
        if(nums[i-1]==nums[i]){
            //cout << 1 << ' ';
            for(int j = 0;j<=26;j++){
                dp[i][j] = dp[i-2][j];
            }
            dp[i][nums[i-2]-'a'] = i-2;
            cnt[i] = cnt[i-2]+1;
            ans[i] = ans[i-1] + cnt[i];
        }else if(nums[i]==nums[dp[i-1][nums[i]-'a']]){
            int t = dp[i-1][nums[i]-'a'];
            //cout << 2 << ' ';
            for(int j = 0;j<=26;j++){
                dp[i][j] = dp[t-1][j];
            }
            dp[i][nums[t-1]-'a'] = t-1;
            cnt[i] = cnt[t-1] + 1;
            ans[i] = ans[i-1] + cnt[i];
        }else{
            //cout << 3 << ' ';
            for(int j = 0;j<=26;j++){
                dp[i][j] = i;
            }
            cnt[i] = 0;
            ans[i] = ans[i-1];
        }
    }
    /*
    for(int i = 1;i<=n;i++){
        cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2]<<' ' <<dp[i][3]<< ' '<<ans[i]<<' '<<cnt[i] << endl;
    }
    */
    cout << ans[n];
    return 0;
}
