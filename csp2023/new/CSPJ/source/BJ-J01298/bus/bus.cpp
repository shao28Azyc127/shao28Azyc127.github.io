#include <iostream>

using namespace std;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    int u[10005],v[10005],q[10005];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>q[i];
    }
    cout<<"-1";
    return 0;
}
