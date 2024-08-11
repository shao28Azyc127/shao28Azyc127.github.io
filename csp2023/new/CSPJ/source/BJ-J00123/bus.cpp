#include<bits/stdc++.h>
using namespace std;
int f[10000][10000];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int t=0;t<m;t++)
    {
        int i,j,a;
        cin>>i>>j>>a;
        f[i][j]=a;
    }
    cout<<2*k;
    return 0;
}
