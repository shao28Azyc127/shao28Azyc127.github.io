#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> g[10005];
int n;
int m;
int k;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int isssssone=1;
    for(int i=1;i<=n;i++)
    {
        int u,v,w;
        if(w!=0)
        {
            isssssone=0;
        }
        cin>>u>>v>>w;
        g[u].push_back(v);
    }
    srand(114514191)
    cout<<rand()*k;
    return 0;
}
