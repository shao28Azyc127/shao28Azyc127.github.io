#include<bits/stdc++.h>
using namespace std;
int n,dp[200010];
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i < n;i++){
        stack<int> sta;
        sta.push(-1);
        for(int j = i;j >= 0;j--){
            if(s[j] != sta.top()){
                sta.push(s[j]);
            }
            else{
                sta.pop();
                if(sta.size() == 1){
                    dp[i]++;
                }
            }
        }
        dp[i] += dp[i - 1];
    }
    cout << dp[n - 1] << endl;
    return 0;
}
