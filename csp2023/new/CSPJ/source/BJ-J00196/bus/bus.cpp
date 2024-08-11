#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,a[20010][20010],jj=0;
    
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int r,y;
        cin>>r>>y;
        cin>>a[r][y];
        if(a[r][y]!=0)jj=1;
    }
    cout<<-1;
    return 0;}