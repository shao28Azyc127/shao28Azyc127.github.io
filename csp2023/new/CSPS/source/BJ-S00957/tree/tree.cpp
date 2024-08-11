#include<bits/stdc++.h>
#define int long long
using namespace std;
long long ans,mx,tag,n,a[100010],b[100010],c[100010],t[100010],in[100010];
vector<long long> g[100010];
struct point{
    long long id,zhi;
    bool operator <(const point &a) const
    {
        return a.zhi>zhi;
    }
};
priority_queue<point> q;
void dfs()
{
    int cnt=0;
    while(q.empty()!=true)
    {
        point u=q.top();q.pop();
        //cout<<u.id<<" ";
        mx=max(mx,cnt+u.zhi);
        for(int i=0;i<g[u.id].size();i++)
        {
            int v=g[u.id][i];
            if(in[v]==0)
            {
                in[v]=1;
                //cout<<v<<"\n";
                int x=(a[v]-1)/b[v]+1;
                q.push({v,x});
            }
        }
        cnt++;
    }
}
bool check(long long x)
{
    for(int i=1;i<=n;i++)
    {
        int num=(x-i+1)*b[i]+(i+i+x)*(x-1)/2*c[i];
        if(num>0)
        {
            if(num<a[i]) return false;
        }
        else
        {
            int li=(b[i]-1)/(0-c[i]);
            num=x-li+(i+li)*(li-i+1)/2*c[i]+(li-i+1)*b[i];
            //cout<<(i+li)*(li-i+1)/2<<"\n";
            if(num<a[i]) return false;
        }
    }
    return true;
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        //cout<<u<<" "<<v<<"\n";
        if(v-u!=1) tag=1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(tag==1)
    {
        int x=(a[1]-1)/b[1]+1;
        in[1]=1;
        q.push({1,x});
        dfs();
        cout<<mx<<endl;
        return 0;
    }
    else
    {
        int l=n,r=1e9+10;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid)==true)
            {
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        //cout<<check(24)<<"\n";
        cout<<ans<<endl;
    }

    return 0;
}
