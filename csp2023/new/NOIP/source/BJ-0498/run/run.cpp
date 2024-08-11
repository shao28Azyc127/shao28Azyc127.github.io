#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        int sum=0;
        for(int j=1;j<=m;j++)
        {
            int x,t,v;
            cin>>x>>y>>V;
            sum+=v;
        }
        cout<<n*d-sum;
    }

    return 0;
}
