#include<bits/stdc++.h>
using namespace std;
bool dp[8005][8005];
int n,ans;
char a[8005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%c",&a[i]);
    }
    getchar();
    a[0]='Y';
    for(int i=0;i<n;i++){
        dp[i+1][i+1]=0;
        if(a[i]==a[i+1]){
            dp[i][i+1]=1;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=1;i<=n-k+1;i++){
            int j=i+k-1;
            if(a[i]==a[j]&&dp[i+1][j-1]==1){
                dp[i][j]=1;
            }
            for(int t=i+1;t<=j-1;t++){
                if(dp[i][t]&&dp[t+1][j]){
                    dp[i][j]=1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ans+=dp[j][i];
        }
    }
    printf("%d",ans);
    return 0;
}
