#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define int long long
const int N=1e4+5;
int n,m,k;
vector< pair<int,int> > vec[N];
int dis[N][100+5];
void spfa()
{
    int i,j;
    queue< pair<int,int> > q;
    for(i=1; i<=n; i++)
        for(j=0; j<k; j++)
            dis[i][j]=1e18;
    dis[1][0]=0;
    q.push(make_pair(1,0));
    while(!q.empty())
    {
        int temp=q.front().first;
        int tt=q.front().second;
        q.pop();
        for(i=0; i<vec[temp].size(); i++)
        {
            if(dis[vec[temp][i].first][(tt+1)%k]>dis[temp][tt]+(tt+1)/k)
            {
                dis[vec[temp][i].first][(tt+1)%k]=max(dis[temp][tt]+(tt+1)/k,vec[temp][i].second/k+((tt+1)%k<vec[temp][i].second%k));
                q.push(make_pair(vec[temp][i].first,(tt+1)%k));
            }
        }
    }
    return;
}
signed main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int i,j;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        vec[u].push_back(make_pair(v,w));
    }
    spfa();
    if(dis[n][0]>1e15)
        printf("-1");
    else
        printf("%lld",dis[n][0]*k);
    return 0;
}

