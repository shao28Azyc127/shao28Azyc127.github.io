#include <iostream>
#include<algorithm>
using namespace std;

struct sss{
    long long x,y,v;
}ch[100005];

bool cmp(sss x,sss y)
{
    return x.v*y.y>y.v*x.y;
}
bool vis[100005];

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t,n,m,k,d;
    long long ans=0;
    cin>>c>>t>>n>>m>>k>>d;
    for(int i=1;i<=m;i++)
    {
        cin>>ch[i].x>>ch[i].y>>ch[i].v;
    }
    sort(ch+1,ch+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(ch[i].v-d*ch[i].y>0 && !vis[ch[i].x+1] && (ch[i].x-ch[i].y<0 || !vis[ch[i].x-ch[i].y]) && ch[i].y<=k)
        {
            ans+=ch[i].v-d*ch[i].y;
            vis[ch[i].x]=vis[ch[i].x-ch[i].y+1]=1;
        }
    }
    cout<<ans;
    return 0;
}
