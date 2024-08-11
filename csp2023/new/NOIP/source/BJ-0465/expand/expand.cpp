#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int a[N],b[N],dp[N][N],n,m;
int aa[N],bb[N];
int qwq[2*N],cnt=0;
inline int read()
{
    int S=0,W=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') W=-1; ch=getchar();}
    while(ch>='0' && ch<='9') S=(S<<1)+(S<<3)+(ch^48),ch=getchar();
    return S*W;
}
bool dame() {return (a[1]>b[1])^(a[n]>b[m]);}
void cal()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++) dp[i][j]=0;
    dp[0][0]=1; bool tk=(a[1]>b[1]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((a[i]>b[j])==tk) dp[i][j]|=(dp[i][j-1]|dp[i-1][j-1]|dp[i-1][j]);
    printf("%d",(int)dp[n][m]);
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c=read(); n=read(),m=read();
    int q=read(),ka,kb,x,y;
    for(int i=1;i<=n;i++) a[i]=aa[i]=read(),qwq[++cnt]=a[i];
    for(int i=1;i<=m;i++) b[i]=bb[i]=read(),qwq[++cnt]=b[i];
    if(dame()) printf("0");
    else cal();
    while(q--)
    {
        for(int i=1;i<=n;i++) a[i]=aa[i];
        for(int i=1;i<=m;i++) b[i]=bb[i];
        ka=read(),kb=read();
        for(int i=1;i<=ka;i++)
        {
            x=read(),y=read();
            a[x]=y;
        }
        for(int i=1;i<=kb;i++)
        {
            x=read(),y=read();
            b[x]=y;
        }
        if(dame()) printf("0");
        else cal();
    }
    return 0;
}