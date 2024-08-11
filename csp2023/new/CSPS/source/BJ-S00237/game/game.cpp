#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#define maxn 10005
using namespace std;
int n;
char s[maxn];
int dp[maxn][maxn];//i->j
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int j=1;j<=n;j++){
        for(int i=j-1;i>=1;i--){
            if(s[i]==s[j]&&j-i==1) {
                dp[i][j]++;
                continue;
            }

            for(int p=i+1;p<=j-1;p++)
                dp[i][j]=max(dp[i][j],dp[i][p]+dp[p][j]);
            //dp[i][j]+=max(dp[i+1][j],dp[i][j-1]);
            //dp[i][j];
            //if(i==1&&j==8) cout<<dp[i][j];
            if(s[i]==s[j]&&(j-i)%2==1&&dp[i+1][j-1]*2==(j-i-1)) dp[i][j]++;
            else if(dp[i][j]*2==j-i+1) dp[i][j]++;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>j) cout<<"  ";
            else cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }*/
    printf("%d",dp[1][n]);
    return 0;
}
