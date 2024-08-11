#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+10;
char s[maxn];
bool dp[5010][5010];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);

    if (n<=1000){
        for (int i=1;i<=n;i++){
            if (s[i]==s[i+1]) dp[i][i+1]=1;
        }

        for (int len=4;len<=n;len+=2){
            for (int l=1;l+len-1<=n;l++){
                int r=l+len-1;

                if (s[l]==s[r]){
                    if (dp[l+1][r-1]==1) dp[l][r]=1;
                }

                for (int mid=l+1;mid<r-1;mid+=2){
                    if (dp[l][mid]==1&&dp[mid+1][r]==1){
                        dp[l][r]=1; break;
                    }
                }
            }
        }

        long long ans=0;
        for (int l=1;l<=n;l++){
            for (int r=l+1;r<=n;r+=2){
                if (dp[l][r]) ans++;
            }
        }
        printf("%lld\n",ans);
        return 0;
    }

    printf("0\n");
    return 0;
}