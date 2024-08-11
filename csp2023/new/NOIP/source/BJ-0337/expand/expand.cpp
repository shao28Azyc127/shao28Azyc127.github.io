#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int c,n,m,q;
int a[N],b[N];
int la[N],lb[N],ca=0,cb=0;
bool flag=false;
bool check(int kind,int lena,int lenb){
    for(int i=1;i<=min(lena,lenb);i++){
        if(a[i]<=b[i]) return false;
    }
    return true;
}
void dfs1(int x,int y){
    //cout<<a[x]<<" "<<b[y]<<" "<<x<<" "<<y<<endl;
    if(x==n&&y==m){
       flag=true;
       return ;
    }
    if(a[x]>b[y+1]&&y<m) dfs1(x,y+1);
    if(a[x+1]>b[y]&&x<n) dfs1(x+1,y);
    if(a[x+1]>b[y+1]&&x<n&&y<m) dfs1(x+1,y);
    return ;
}
void dfs2(int x,int y){
    //cout<<a[x]<<" "<<b[y]<<" "<<x<<" "<<y<<endl;
    if(x==n&&y==m){
       flag=true;
       return ;
    }
    if(a[x]<b[y+1]&&y<m) dfs2(x,y+1);
    if(a[x+1]<b[y]&&x<n) dfs2(x+1,y);
    if(a[x+1]<b[y+1]&&x<n&&y<m) dfs2(x+1,y);
    return ;
}
void work(){
    flag=false;
    if(a[1]>b[1]) dfs1(1,1);
    if(a[1]==b[1]){
        cout<<0;
        return ;
    } 
    if(a[1]<b[1]) dfs2(1,1);
    cout<<flag;
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) la[i]=a[i];
    for(int i=1;i<=m;i++) lb[i]=b[i];
    work();
    for(int i=1;i<=q;i++){
        int kx,ky;
        scanf("%lld%lld",&kx,&ky);
        for(int j=1;j<=kx;j++){
            int qx,qv;
            scanf("%lld%lld",&qx,&qv);
            a[qx]=qv;
        }
        for(int j=1;j<=ky;j++){
            int qx,qv;
            scanf("%lld%lld",&qx,&qv);
            b[qx]=qv;
        }
        work();
        for(int j=1;j<=n;j++) a[j]=la[j];
        for(int j=1;j<=m;j++) b[j]=lb[j];
    }
    return 0;
}
/*
4 6 6 60
195982977 303897138 437154869 81559605 365511323 302808478
342942401 297976421 445071632 83871721 304067809 427239638
*/