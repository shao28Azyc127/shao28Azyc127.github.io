#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int T=300001,F=300004,U=300007;
struct ___
{
    int id;//a:a=T a+n:a=F a+2n:a=U
    int endid;//3e5+1:T 3e5+2:F 3e5+3:U
} a[100005];
int n,m;
int cnt;
int ucnt[300010];
int f[300010];
int opposent(int id)
{
    if(id<=100000) return id+100000;
    if(id<=200000) return id-100000;
    if(id<=300000) return id;
    if(id==T) return F;
    if(id==F) return T;
    if(id==U) return U;
}
inline bool isu(int x){return (x>200000&&x<=300000)||x==U||x==U+1||x==U+2;}
bool vis[300010];
int _find(int x)
{
    if(f[x]!=x) return f[x]=_find(f[x]);
    return x;
}
void _merge(int x,int y)
{
    //cout<<"MERGE "<<x<<' '<<y<<'\n';
    if(abs(_find(x)-_find(y))==100000)
    {
        ucnt[_find(x)]=ucnt[_find(y)]=1e9;
    }
    if(_find(x)==_find(y)) return;
    //cout<<"ucnt["<<x<<"]:"<<ucnt[_find(x)]<<" ,ucnt["<<y<<"]:"<<ucnt[_find(y)]<<'\n';
    ucnt[_find(y)]+=ucnt[_find(x)];
    f[_find(x)]=_find(y);
}
void Main()
{
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        a[i].endid=i;
    }
    for(int i=1;i<=300009;i++){f[i]=i;ucnt[i]=isu(i);}
    for(int i=1;i<=m;i++)
    {
        char c;
        int u,v;
        cin>>c>>u;
        if(c=='T'){a[u].endid=T;}
        if(c=='F'){a[u].endid=F;}
        if(c=='U'){a[u].endid=U;}
        if(c=='+')
        {
            cin>>v;
            a[u].endid=a[v].endid;
        }
        if(c=='-')
        {
            cin>>v;
            a[u].endid=opposent(a[v].endid);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].endid>100000&&a[i].endid<=300000)
        {
            int u=a[i].id,v=a[i].endid-100000;
            _merge(u,v+100000);
            _merge(u+100000,v);
            _merge(u+200000,v+200000);
        }
        else if(a[i].endid<=300000)
        {
            int u=a[i].id,v=a[i].endid;
            _merge(u,v);
            _merge(u+100000,v+100000);
            _merge(u+200000,v+200000);
        }
        else{
            int u=a[i].id,v=a[i].endid;
            _merge(u,v);
            _merge(u+100000,v+1);
            _merge(u+200000,v+2);
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++)
        if(!vis[_find(i)])
        {
            //cout<<"count "<<i<<":"<<ucnt[_find(i)]<<' '<<ucnt[_find(i+100000)]<<' '<<ucnt[_find(i+200000)]<<'\n';
            vis[_find(i)]=vis[_find(i+100000)]=vis[_find(i+200000)]=1;
            cnt+=min(min(ucnt[_find(i)],ucnt[_find(i+100000)]),ucnt[_find(i+200000)]);
        }
    cout<<cnt<<endl;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
        Main();
    return 0;
}
