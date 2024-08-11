#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
int a[11][6];
int now[6];
int n;
bool check()
{
    for(int i=1;i<=n;i++)
    {
        int sl=0,xb1=0,xb2=0;
        for(int j=1;j<=5;j++)
        {
            if(now[j]!=a[i][j])
            {
                sl++;
                if(sl==1)xb1=j;
                else xb2=j;
            }
        }
        if(sl>2||sl==0)return false;
        if(sl==1)continue;
        if(sl==2)
        {
            if(xb1!=xb2+1&&xb2!=xb1+1)return false;
            if((a[i][xb1]-now[xb1]+10)%10!=(a[i][xb2]-now[xb2]+10)%10)return false;
        }
    }
    return true;
}
int ans;
void dfs(int x)
{
    if(x==6)
    {
        if(check())ans++;
        return;
    }
    for(int i=0;i<=9;i++)
    {
        now[x]=i;
        dfs(x+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)a[i][j]=read();
    }
    dfs(1);
    printf("%d\n",ans);
}