#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=5e5+9;
int a[N],b[N];
int cnt[30];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int o,q,n,m;
    cin>>o>>n>>m>>q;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    cout<<(a[1]!=b[1]);
    while(q--)
    {
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1; i<=kx; i++)
        {
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }
        for(int i=1; i<=ky; i++)
        {
            int x,y;
            cin>>x>>y;
            b[x]=y;
        }
        cout<<(a[1]!=b[1]);
    }
    return 0;
}
