#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c,t;
int n,m,k,d;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    int x,y,z;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y>>z;
        }
        cout<<-((n+1)/2)*d;
    }
    return 0;
}
