#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct E{
    int to;//dao na li qu
    int ope;//kai fang shi jian
    int nex;//zhi xiang xia yi ge ben jie dian ke yi qu de jie dian
    //int node;
};
E e[20005];
int hed[20005];
int e_min_time[20005];
int cnt;
int main()
{
    freopen("bus1.in","r",stdin);
    freopen("bus1.out","w",stdout);
    cin >> n >> m >> k;
    int i;
    for (i = 1; i <= n; ++i) e_min_time[i] = 1e+9;
    for (i = 0; i < m; ++i)
    {
        int u,v,a;
        cin >> u >> v >> a;
        ++cnt;
        e[cnt].nex = hed[u];
        hed[u] = cnt;
        e[cnt].ope = a;
        e[cnt].to = v;
    }
    cout << -1;
    return 0;
}