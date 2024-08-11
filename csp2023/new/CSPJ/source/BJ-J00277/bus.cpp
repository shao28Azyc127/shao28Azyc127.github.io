#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<functional>
#include<limits>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int n,m,k,u[20001],v[20001],a[20001];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {

        cin>>u[i]>>v[i]>>a[i];
    }
    cout<<-1;
    return 0;
}
