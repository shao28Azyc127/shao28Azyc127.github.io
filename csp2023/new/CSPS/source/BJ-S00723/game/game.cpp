#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,ans;
char c[N];
bool dp[N][N];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>c[i];
    for(int i=1;i<n;i++)
        if(c[i]==c[i+1])    dp[i][i+1]=1;
    for(int l=4;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int j=i+l-1;
            if(c[i]==c[j])  dp[i][j]=dp[i+1][j-1];
            for(int k=i+1;k<=j-2;k++){
                if(dp[i][k]&&dp[k+1][j])
                    dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)   ans+=dp[i][j];
    cout<<ans;
    return 0;
}
