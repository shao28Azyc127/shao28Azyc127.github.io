#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int a[10];
int b[10];
int ta[10];
int tb[10];
void solve()
{
    if(n==1&&m==1)
    {
        if(tb[1]!=ta[1])printf("1");
        else printf("0");
        return;
    }
    if(n==2&&n==2){
        if(tb[1]<ta[1]&&tb[2]<ta[2])printf("1");
        if(tb[1]>ta[1]&&tb[2]>ta[2])printf("1");
        else printf("0");
         return;
    }
    
}
int  main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        ta[i] = a[i];
    }
    for(int i = 1; i <= m; i++){
        cin>>b[i];
        tb[i] = b[i];
    }
    for(int i = 1; i <= q; i++){
        for(int i = 1; i <= n; i++){
            ta[i] = a[i];
        }
        for(int i = 1; i <= m; i++){
        tb[i] = b[i];
    }
        int x,y;cin>>x>>y;
        for(int j = 1; j <= x; j++){
            int p,v;cin>>p>>v;
            ta[p]=v;
        }
        for(int j = 1; j <= y; j++){
            int p,v;cin>>p>>v;
            tb[p]=v;
        }
        solve();
    }

    return 0;
}
