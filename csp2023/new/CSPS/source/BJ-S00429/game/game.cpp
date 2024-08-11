#include<bits/stdc++.h>
using namespace std;
const int Max=2e6+5;
char c[Max];
int dp[Max];
int main() {
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    scanf("%s",c+1);
    long long ans=0;
    for (int i=1;i<=n-1;i++) {
        if (c[i]==c[i+1]) {
            dp[i+1]++;
            ans+=dp[i-1]+1;
            int j=1;
            while (c[i-j]==c[i+j+1]) {
                dp[i+j+1]++;
                ans+=dp[i-j-1]+1;
                j++;
            }
        }
    }
    //for (int i=1;i<=n;i++) cout<<dp[i]<<' ';
    printf("%lld",ans);
    return 0;
}
