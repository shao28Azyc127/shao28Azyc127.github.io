#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int t,n,m,q,a[N],b[N],c[N],d[N],ans[N];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    t=read();n=read();m=read();q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    for(int i=0,kx,ky;i<=q;i++){
        for(int j=1;j<=n;j++) c[j]=a[j];for(int j=1;j<=m;j++) d[j]=b[j];
        if(i){
            kx=read();ky=read();
            for(int j=1,px,v;j<=kx;j++) px=read(),v=read(),c[px]=v;
            for(int j=1,py,v;j<=ky;j++) py=read(),v=read(),d[py]=v;
        }
        int flag=0,now=1,last=0,jr=0;
        if(c[1]==d[1]) continue;
        for(int j=1;j<=n;j++){
            for(int k=now;k<=m;k++){
                if(c[j]<=d[k]){
                    if(j==n) {flag=1;break;}
                    if(k==now){
                        while((--now)>=last-1) 
                            if(c[j]>d[now]) break;
                        if(now<last) {flag=1;break;}
                        else{last=now;break;}
                    }
                    else {last=now;now=k-1;break;}
                } 
                if(k==m&&c[j]>d[k]) jr=1; 
            }
            if(jr&&now!=m) last=now,now=m;
            if(flag) break;   
        }
        if(!flag) ans[i]=1;
        flag=0,now=1;last=0;jr=0;
        for(int j=1;j<=m;j++){
            for(int k=now;k<=n;k++){
                if(d[j]<=c[k]){
                    if(j==m) {flag=1;break;}
                    if(k==now){
                        while((--now)>=last-1) 
                            if(d[j]>c[now]) break;
                        if(now<last) {flag=1;break;}
                        else{last=now;now++;break;}
                    }
                    else {last=now;now=k-1;break;}
                } 
                if(k==n&&d[j]>c[k]) jr=1; 
            }
            if(jr&&now!=n) last=now,now=n;
            if(flag) break;   
        }
        if(!flag) ans[i]=1;
    }
    for(int i=0;i<=q;i++) printf("%d",ans[i]);puts("");
    return 0;
}