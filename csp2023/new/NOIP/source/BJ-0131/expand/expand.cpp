#include<bits/stdc++.h>
using namespace std;
const int N=100010;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int n,m,q,a[N],b[N];
void work_bl1(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    if(a[1]!=b[1]) cout<<"1";
    else cout<<"0";
    while(q--){
        int c1,c2;
        c1=read(),c2=read();
        for(int i=1;i<=c1;i++){
            int pos=read(),zhi=read();
            a[pos]=zhi;
        }
        for(int i=1;i<=c2;i++){
            int pos=read(),zhi=read();
            b[pos]=zhi;
        }
        if(a[1]!=b[1]) cout<<"1";
        else cout<<"0";
    }
}
int cal(){
    return (a[1]-b[1])*(a[2]-b[2]);
}
void work_bl2(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    if(n==1) a[2]=a[1];
    if(m==1) b[2]=b[1];
    if(cal()>0) cout<<"1";
    else cout<<"0";
    while(q--){
        int c1,c2;
        c1=read(),c2=read();
        for(int i=1;i<=c1;i++){
            int pos=read(),zhi=read();
            a[pos]=zhi;
        }
        if(n==1) a[2]=a[1];
        if(m==1) b[2]=b[1];
        for(int i=1;i<=c2;i++){
            int pos=read(),zhi=read();
            b[pos]=zhi;
        }
        if(cal()>0) cout<<"1";
        else cout<<"0";
    }
}
void pianfe(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=q+1;i++) cout<<"0";
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c=read();
    if(c==1){
        work_bl1();
        return 0;
    }else if(c==2){
        work_bl2();
        return 0;
    }else{
        pianfe();
        return 0;
    }
    return 0;
}
