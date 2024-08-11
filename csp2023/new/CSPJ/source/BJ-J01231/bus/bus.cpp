#include <bits/stdc++.h>
using namespace std;
vector <int> a[20005];
int main()
{
    freopen ("bus.in","r",stdin);
    freopen ("bus.out","w",stdout);
    int n,m,k;
    cin >>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int u,v,t;
        cin >>u>>v>>t;
        a[v].push_back(u);
        a[u].push_back(v);
    }


    return 0;
}
