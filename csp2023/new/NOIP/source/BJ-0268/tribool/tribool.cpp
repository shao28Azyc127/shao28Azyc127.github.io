#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int c,t,n,m;char a[N];int q[N],p[N];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
inline void solve1(){
    n=read();m=read();int ans=0;
    for(int i=1,x;i<=m;i++){
        char op;scanf(" %c",&op);
        if(op=='U') ans++;x=read();
    }
    printf("%d\n",ans);
}
inline void solve2(){
    n=read();m=read();int ans=0;
    for(int i=1;i<=n;i++) a[i]=' ';
    memset(p,0,sizeof p);memset(q,0,sizeof q);
    for(int i=1,x,y;i<=m;i++){
        char op;scanf(" %c",&op);p[i]=read();
        if(op=='U') a[p[i]]='U';
        if(op=='+') q[i]=read(),a[p[i]]=a[q[i]];
    }
    for(int k=1;k<=1000;k++)
        for(int i=1;i<=m;i++) 
            if(p[i]&&!q[i]) a[p[i]]='U';
            else if(p[i]&&q[i]) a[p[i]]=a[q[i]];
    for(int i=1;i<=n;i++) 
        if(a[i]=='U') ans++;
    printf("%d\n",ans);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    c=read();t=read();
    while(t--){
        if(c==3||c==4) solve1();
        if(c==5||c==6) solve2();
    }
    return 0;
}