#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,ans=0;
string s;
bool dp[10005][10005];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int j=2;j<=n;j+=2){
        for(int i=0;i<=n-j;i++){
            if(j==2){
                if(s[i]==s[i+1]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
            else{
                if(s[i]==s[i+j-1]){
                    dp[i][j]=dp[i+1][j-2];
                }
                for(int k=i+2;k<i+j-1;k+=2){
                    dp[i][j]|=dp[i][k-i]&dp[k][j-k+i];
                }
            }
            if(dp[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
