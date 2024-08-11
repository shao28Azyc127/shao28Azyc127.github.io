#include<bits/stdc++.h>
using namespace std;
bool dp[805][805];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    if(n>1000){
        cout<<"0"<<endl;
        return 0;
    }
    string s;
    cin>>s;
    s=' '+s;
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=n-i+1;j++){
            for(int k=j+2;k<j+i;k+=2){
                if(dp[k-j][j]&&dp[i-k+j][k]){
                    dp[i][j]=1;
                    break;
                }
            }
            if(s[j]==s[j+i-1]&&(i==2||dp[i-2][j+1])){
                dp[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=2;i<=n;i+=2){
        for(int j=1;j<=n;j++){
            if(dp[i][j]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
