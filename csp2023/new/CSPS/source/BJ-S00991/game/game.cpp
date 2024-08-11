#include<iostream>
#include<string>
using namespace std;

const int maxn=8000+10;
int dp[maxn][maxn],n,ans;
string s;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s; s=" "+s;
    for(int i=1;i<=n;i++)dp[0][i]=1;
    for(int len=2;len<=n;len+=2){
        for(int l=1;l+len-1<=n;l++){
            if(s[l]==s[l+len-1])dp[len][l]|=dp[len-2][l+1];
            for(int k=0;k<=len;k++)dp[len][l]|=(dp[k][l]&dp[len-k][l+k]);
            ans+=dp[len][l];
        }
    }
    cout<<ans<<endl;
}