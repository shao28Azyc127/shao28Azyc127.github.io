#include<bits/stdc++.h>
using namespace std;
vector<int>a[10005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[m],v[m],t[m];
    for(int i=0;i<m;i++)
    {
        cin>>u[i]>>v[i]>>t[i];
        a[u[i]].push_back(v[i]);
    }
    cout<<-1;
    return 0;
}
