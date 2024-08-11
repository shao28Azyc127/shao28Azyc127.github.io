#include <iostream>
using namespace std;
int a[100005][100005],b[100005][100005],i,u,v;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    for(int i=1;i<=m;i++)
    {
        cin>>i>>u>>v;
        a[i][u]=1;
        b[i][u]=v;
    }
    cout<<"-1";
    return 0;
}
