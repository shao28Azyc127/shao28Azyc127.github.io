#include <iostream>
using namespace std;
#define maxn 500005
int c,n,m,q,ra[maxn],rb[maxn],a[maxn],b[maxn];
int dfs(int x,int y){
    if(a[1]==b[1]){
        return 0;
    }
    if(x==n){
        for(int i=y;i<=m;i++){
            if((a[1]>b[1])!=(a[x]>b[i])){
                return 0;
            }
        }
        return 1;
    }
    if(y==m){
        for(int i=x;i<=n;i++){
            if((a[1]>b[1])!=(a[i]>b[y])){
                return 0;
            }
        }
        return 1;
    }
    if((a[1]>b[1])==(a[x]>b[y])){
        if(dfs(x+1,y)){
            return 1;
        }
    }
    for(int i=y+1;i<=m&&((a[1]>b[1])==(a[x]>b[i]));i++){
        if(dfs(x+1,i)){
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>ra[i];
        a[i]=ra[i];
    }
    for(int i=1;i<=m;i++){
        cin>>rb[i];
        b[i]=rb[i];
    }
    cout<<dfs(1,1);
    for(int i=1;i<=q;i++){
        int kx,ky;
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++){
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }
        for(int j=1;j<=ky;j++){
            int p,v;
            cin>>p>>v;
            b[p]=v;
        }
        cout<<dfs(1,1);
        for(int i=1;i<=n;i++){
            a[i]=ra[i];
        }
        for(int i=1;i<=n;i++){
            b[i]=rb[i];
        }
    }
    return 0;
}
