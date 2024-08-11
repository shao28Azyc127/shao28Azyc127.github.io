#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
typedef pair<int,int> PII;
vector<PII> graph[N];
vector<int> tt;
int n,m,k;

void add(int a,int b,int c)
{
    graph[a].push_back({b,c});
}

void dfs(int d,int t)
{
    if(d==n)
    {
        if(t%k==0) tt.push_back(t);
        return ;
    }

    for(int i=0;i<graph[d].size();i++)
    {
        int j=graph[d][i].first;
        int k=graph[d][i].second;
        if(t>=k)
        {
            dfs(j,t+1);
        }
        else{
            t++;
        }
    }

}


int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dfs(1,k);
    if(tt.empty())
    {
        cout<<-1;
    }
    else{
        sort(tt.begin(),tt.end());
        cout<<tt[0];
    }

    return 0;

}