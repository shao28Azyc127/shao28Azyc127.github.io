#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2e3+5;
int x[MAXN],y[MAXN];
int nx[MAXN],ny[MAXN];
bool dp[MAXN][MAXN];
string res;
void f(int n,int m,int a[],int b[])
{
    /*
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
    for(int i=1;i<=m;i++) cout<<b[i]<<' ';
    cout<<endl;
    */
    memset(dp,false,sizeof(dp));
    dp[1][1]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]>b[j]&&(dp[i][j-1]||dp[i-1][j]))
            {
                dp[i][j]=true;
            }
            //cout<<(a[i]>b[j])<<' ';
        }
        //cout<<endl;
    }
/*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<dp[i][j]<<' ';
        cout<<endl;
    }
*/
    printf("%d",dp[n][m]);
    res+=(dp[n][m]+'0');
    //cout<<endl;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    /*
    if((x[1]-y[1])*(x[n]-y[m])<=0)
    {
        printf("0");
        res+='0';
        cout<<endl;
    }
    else */if(x[1]-y[1]<0) f(m,n,y,x);
    else f(n,m,x,y);
    for(int i=1;i<=q;i++)
    {
        //cout<<i+1<<endl;
        for(int i=1;i<=n;i++) nx[i]=x[i];
        for(int i=1;i<=m;i++) ny[i]=y[i];
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            nx[p]=v;
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            scanf("%d%d",&p,&v);
            ny[p]=v;
        }
        if(nx[1]-ny[1]==0)
        {
            printf("0");
            //res+='0';
            //cout<<endl;
        }
        else if(nx[1]-ny[1]<0) f(m,n,ny,nx);
        else f(n,m,nx,ny);
    }
    //cout<<res<<endl;
    return 0;
}
