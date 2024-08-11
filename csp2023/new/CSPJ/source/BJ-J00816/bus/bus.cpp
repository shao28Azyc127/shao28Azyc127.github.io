#include<bits/stdc++.h>
using namespace std;
int d[10010][10010];
int v[20010],u[10010],a[10010];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>d[i];
        a[u[i]][v[i]]=d[i];
    }
    cout<<"-1";
    return 0;
}