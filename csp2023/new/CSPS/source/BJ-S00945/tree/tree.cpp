#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
    long long n=0,f=1,ch=getchar();
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
long long a[200005];
int b[200005],c[200005];
vector<int>v[200005];
int sj[200005];
void dfs(int x,int f)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==f)continue;
        dfs(v[x][i],x);
        sj[x]=min(sj[x],sj[v[x][i]]-1);
    }
}
int n;
int findsj(long long a,int b,int c,int x)
{
    if(c<0&&b+1LL*x*c<=0)
    {
        int wz=(b-1)/(-c);
        if(a<=x-wz)return x-a+1;
        a-=(x-wz);
        x=wz;
    }
    int l=1,r=min(n+1,x),mid;
    while(l<=r)
    {
        mid=((l+r)>>1);
        if(((__int128)(2*b+1LL*(mid+x)*c))*(x-mid+1)/2>=a)l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int x,y;
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        b[i]=read();
        c[i]=read();
    }
    for(int i=1;i<=n-1;i++)
    {
        x=read();
        y=read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int l=1,r=1000000000,mid;
    while(l<=r)
    {
        mid=((l+r)>>1);
        for(int i=1;i<=n;i++)
        {
            sj[i]=findsj(a[i],b[i],c[i],mid);
        }
        dfs(1,0);
        sort(sj+1,sj+n+1);
        bool flag=true;
        for(int i=1;i<=n;i++)if(sj[i]<i)
        {
            flag=false;
            break;
        }
        if(flag==true)r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}