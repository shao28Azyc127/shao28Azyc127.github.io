#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cnt;
int dp[2000007];
char a[2000007];
stack<char> stk;
signed main(){
    freopen("game2.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    char t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=0;
    int cnt1=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            cnt1++;
            if(cnt1%2)dp[i]++;
        }
        else{
            cnt1=1;
        }
        if(stk.empty()){
            dp[i]+=(dp[i-1]);
            stk.push(a[i]);
        }
        else{
            if(a[i]==stk.top()){
                stk.pop();
                dp[i]+=(dp[i-1]+1);
                if(stk.empty()){
                    dp[i]+=cnt;
                    cnt++;
                }
            }
            else{
                dp[i]+=dp[i-1];
                stk.push(a[i]);
            }
        }
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
zyctc AK IOI
*/

