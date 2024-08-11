#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
struct sss{
    ll v,tim;
};

struct ttt{
    ll v,tim,latim;
};

vector<sss>mp[10005];
queue<ttt> q;
ll n,m,k;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        ll u,v,t;
        scanf("%lld%lld%lld",&u,&v,&t);
        mp[u].push_back({v,t});
    }
    q.push({1,0,0});
    while(!q.empty())
    {
        ttt u=q.front();
        q.pop();
        if(u.v==n && u.tim%k==0)
        {
            printf("%lld",(u.latim%k==0?u.latim:(u.latim/k+1)*k)+u.tim);
            return 0;
        }
        for(int i=0;i<mp[u.v].size();i++)
        {
            sss vv=mp[u.v][i];
            q.push({vv.v,u.tim+1,max(u.latim,vv.tim-u.tim)});
        }
    }
    printf("-1");
    return 0;
}
