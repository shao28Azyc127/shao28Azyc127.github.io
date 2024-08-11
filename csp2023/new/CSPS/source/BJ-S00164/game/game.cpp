#include<bits/stdc++.h>
using namespace std;
const int N=810;
char s[N]; bool dp[N][N];
inline int read()
{
    int ss=0,ww=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') ww=-1; ch=getchar();}
    while(ch>='0' && ch<='9') ss=(ss<<1)+(ss<<3)+(ch^48),ch=getchar();
    return ss*ww;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n=read(),ans=0;
    scanf("%s",s+1);
    for(int i=2;i<=n;i++)
        if(s[i-1]==s[i]) dp[i-1][i]=1,ans++;
    for(int i=2;i<=n;i++)
    {
        for(int l=1;l+i<=n;l++)
        {
            int r=l+i;
            for(int k=l+1;k<r-1;k++) dp[l][r]|=(dp[l][k]&dp[k+1][r]);
            dp[l][r]|=((s[l]==s[r])&dp[l+1][r-1]),ans+=dp[l][r];
        }
    }
    printf("%d",ans);
    return 0;
}