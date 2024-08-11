#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10;
ll n,m,k;
ll dis[N];
vector<pair<ll,ll>> a[N];
ll bfs()
{
    queue<ll> q;
    dis[1]=1;
    q.push(1);
    while(!q.empty())
    {
        ll c=q.front();
        q.pop();
        if(c==n)
            return dis[n]-1;
        for(ll i=0;i<a[c].size();i++)
        {
            ll t=a[c][i].first;
            if(!dis[t])
            {
                dis[t]=dis[c]+1;
                q.push(t);
            }
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++)
    {
        ll u,v,x;
        cin>>u>>v>>x;
        a[u].push_back({v,x});
    }
    if(k==1)
    {

            cout<<bfs()<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}
