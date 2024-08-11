#include<bits/stdc++.h>
using namespace std;
const int MXN=1e4+10;
int n;
bool dp[MXN][MXN];
char s[MXN];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    //cout<<"$";
    cin>>s+1;
    //cout<<s<<'\n';
    int ans=0;
    for(int i=2;i<=n;i+=2){
        for(int j=1;j+i-1<=n;j++){
            dp[i][j]=(s[j]==s[j+i-1])&&(dp[i-2][j+1]||i==2);
            for(int k=1;k<i;k++){
                dp[i][j]=dp[i][j]||(dp[k][j]&&dp[i-k][j+k]);
            }
            ans+=dp[i][j];
        }
    }
    cout<<ans<<'\n';
    return 0;
}
