#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int u;
    int v;
    int a;
};

bool cmp(Node x,Node y)
{
    return x.u > y.u;
    return x.a > y.a;
    return x.v > y.v;
}

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    int time = 0;
    int flag = 0;
    cin >> n >> m >> k;
    Node a[m];
    for (int i = 1;i<=m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].a;
    }
    if (flag == 0)
    {
        cout << -1;
    } else {
        cout << time;
    }
}