#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int x[N],y[N],flag,xx[N],yy[N];
void dfs1(int n,int k,int pos)
{
    if(k==1)
    {
        int tmp=pos;
        if(pos!=1)  tmp=pos-1;
        for(int i=tmp;i>=1;i--)  if(y[i]<=x[1])  return ;
        flag=1;
        return ;
    }
    if(k==1&&pos==1||k==n||y[pos]>x[k])
    {
        for(int i=pos;i>=1;i--)
        {
            if(y[i]>x[k])  dfs1(n,k-1,i);
            else  break;
        }
    }
    else
    {
        for(int i=pos-1;i>=1;i--)
        {
            if(y[i]>x[k])  dfs1(n,k-1,i);
            else  break;
        }
    }
}
void dfs(int m,int k,int pos)
{
    if(k==1)
    {
        int tmp=pos;
        if(pos!=1)  tmp=pos-1;
        for(int i=tmp;i>=1;i--)  if(x[i]<=y[1])  return ;
        flag=1;
        return ;
    }
    if(k==1&&pos==1||k==m||x[pos]>y[k])
    {
        for(int i=pos;i>=1;i--)
        {
            if(x[i]>y[k])  dfs(m,k-1,i);
            else  break;
        }
    }
    else
    {
        for(int i=pos-1;i>=1;i--)
        {
            if(x[i]>y[k])  dfs(m,k-1,i);
            else  break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)  cin>>xx[i],x[i]=xx[i];
    for(int i=1;i<=m;i++)  cin>>yy[i],y[i]=yy[i];
    do
    {
        flag=0;
        dfs(m,m,n);
        if(flag==0)  dfs1(n,n,m);
        if(flag==1)  cout<<1;
        else  cout<<0;
        for(int i=1;i<=n;i++)  x[i]=xx[i];
        for(int i=1;i<=m;i++)  y[i]=yy[i];
        if(q>0)
        {
            int k1,k2,p,v;
            cin>>k1>>k2;
            for(int i=1;i<=k1;i++)  cin>>p>>v,x[p]=v;
            for(int i=1;i<=k2;i++)  cin>>p>>v,y[p]=v;
            //cout<<"q "<<q<<endl;
        }
    }while(q--);
    return 0;
}