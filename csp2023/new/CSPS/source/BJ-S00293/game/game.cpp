#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n;
bool dp[8005][8005];
int sum[8005];
char a[8005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>(a+1);
    for(int i=1;i<=n;i++){
        dp[i][i-1]=1;
    }
    int ans=0;
    for(int len=2;len<=n;len+=2){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(a[i]==a[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans++;
            }else{
                for(int k=i+2;k<j;k+=2){
                    if(dp[i][k-1]==1&&dp[k][j]==1){
                        dp[i][j]=1;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
