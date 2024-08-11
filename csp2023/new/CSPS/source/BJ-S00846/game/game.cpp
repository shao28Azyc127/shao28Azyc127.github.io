#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
const int N=8005;
int dp[N][N];
int n;
char s[N];
int fa[N];
bool havedog[N];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    if(n>8000) puts("0");
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<n;i++) 
        if(s[i]==s[i+1]) dp[i][i+1]=1;//fa[i+1]=i;
    for(int opop=1;opop<=2;opop++)
    {
        for(int l=4;l<=n;l+=2)
        for(int i=1;i<=n;i++)
        {
            int le=i,rt=i+l-1;
            if(s[le]==s[rt] && dp[le+1][rt-1])
            {
                dp[le][rt]=1;
            }
        }
    
        for(int l=4;l<=n;l++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+l-1;
                for(int k=i;k<=j;k++)
                {
                    if(dp[i][k] && dp[k+1][j]) dp[i][j]=1;
                }
            }
        }
        for(int l=4;l<=n;l+=2)
            for(int i=1;i<=n;i++)
            {
                int le=i,rt=i+l-1;
                if(s[le]==s[rt] && dp[le+1][rt-1])
                {
                    dp[le][rt]=1;
                }
            }
    }
    

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++) ans+=dp[i][j];
    }
    cout<<ans<<endl;
    return 0;
}