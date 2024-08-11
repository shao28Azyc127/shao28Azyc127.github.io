#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;


int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int ans=0;
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n <= n){
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int len=2;len<=n;len+=2){
            for(int i=0;i+len-1<n;i++){
                if(len != 2){
                    if(dp[i+1][i+len-2]  &&  s[i] == s[i+len-1]){
                        dp[i][i+len-1] = true;
                        ans++;
                    }
                    else{
                        for(int j=i+2;j+2-1<=i+len-1;j+=2){
                            if(dp[i][j-1]  &&  dp[j][i+len-1]){
                                dp[i][i+len-1] = true;
                                ans++;
                                break;
                            }
                        }
                    }
                }
                else{
                    if(s[i] == s[i+len-1])
                        dp[i][i+len-1] = true,ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
