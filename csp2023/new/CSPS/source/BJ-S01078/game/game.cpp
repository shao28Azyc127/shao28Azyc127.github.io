#include <bits/stdc++.h>
using namespace std;

const int NR=2e6+100;
char s[NR];
int f[NR][30],fa[NR];
int dp[NR];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    s[0]=s[n+1]='z'+1;
    for(int i=2;i<=n;i++)
    {
        int pos=-1;
        if(s[i]==s[i-1]) f[i][s[i-2]-'a']=i-1,pos=i-2;
        int num=s[i]-'a';
        //printf("chk %d %d %d\n",i,s[i]-'a',f[i-1][num]);
        if(pos==-1&&f[i-1][num]!=0) pos=f[i-1][num]-2;
        if(pos!=-1)
        {
            f[i][s[pos]-'a']=max(f[i][s[pos]-'a'],pos+1);
            for(int j=0;j<27;j++) f[i][j]=max(f[pos][j],f[i][j]);
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<27;j++) fa[i]=max(fa[i],f[i][j]);
    for(int i=1;i<=n;i++) if(fa[i]!=0) dp[i]=dp[fa[i]-1]+1;
    //for(int i=1;i<=n;i++) printf("%d ",fa[i]);
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=dp[i];
    printf("%lld",ans);
    return 0;
}
