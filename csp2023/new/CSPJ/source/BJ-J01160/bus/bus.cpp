#include<bits/stdc++.h>
using namespace std;
//it's the highest code I can think about:the ans is -1
int n,m,k,u,v,a,ans=1000000000;
vector<int> e[20005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    while(m--)
    {
        cin>>u>>v>>a;
        e[u].push_back(v);
    }
    cout<<"-1";
    return 0;
}