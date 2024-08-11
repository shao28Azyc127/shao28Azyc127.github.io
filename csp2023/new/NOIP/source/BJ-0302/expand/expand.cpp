#include<bits/stdc++.h>
using namespace std;
int s,n,m,q;
int a[500010],b[500010],c[500010],d[500010];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>s>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    if(a[1]<=b[1]&&a[n]>=b[m]||a[1]>=b[1]&&a[n]<=b[m])cout<<0;
    else cout<<1;
    for(int i=1;i<=q;i++){
        int x,y,r,f;
        for(int i=1;i<=n;i++)c[i]=a[i];
        for(int i=1;i<=m;i++)d[i]=b[i];
        cin>>x>>y;
        for(int i=1;i<=x;i++)cin>>r>>f,c[r]=f;
        for(int i=1;i<=y;i++)cin>>r>>f,d[r]=f;
        if(c[1]<=d[1]&&c[n]>=d[m]||c[1]>=d[1]&&c[n]<=d[m])cout<<0;
        else cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
