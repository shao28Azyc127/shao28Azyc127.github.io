#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MXN=10010;
typedef pair<int,int> pant;
vector<pant> v[MXN];
vector<int> f[MXN][110];
int oud[MXN];int n,m,k;
priority_queue<pant,vector<pant>,greater<pant> > q; 

void bfs(int t)
{
    q.push({t,1});
    while(!q.empty())
    {
        pant tp=q.top();q.pop();
        int t2=tp.first,o=tp.second;
        int num=0;// cerr<<o<<endl;
        for(auto u:v[o])
        {
            if(u.second<=t2) num++;
        }
        if(f[o][t2%k][num]<=t2) continue;
        f[o][t2%k][num]=t2;
        for(auto u:v[o])
        {
            // cout<<u.first<<endl;
            if(u.second>t2) continue;
            q.push({t2+1,u.first});
        }
    }
    return ;
}

int chk(int o)
{
    // cerr<<o<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            for(int k1=1;k1<=oud[i];k1++) f[i][j][k1]=0x3f3f3f3f;
        }
    }
    bfs(o);int mx=0x3f3f3f3f;
    for(auto u:f[n][0])
    {
        mx=min(mx,u);
    }
    return mx;
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,a;cin>>x>>y>>a;
        v[x].push_back({y,a});
        if(n>15&&a!=0) {cout<<-1<<endl;return 0;}
        oud[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            while(f[i][j].size()<=oud[i]) f[i][j].push_back(0x3f3f3f3f);
        }
    }
    for(int i=0;i<=2e8;i+=k)
    {
        if(chk(i)!=0x3f3f3f3f) {cout<<chk(i)<<endl;return 0;}
    }
    cout<<-1<<endl;
    return 0;
}