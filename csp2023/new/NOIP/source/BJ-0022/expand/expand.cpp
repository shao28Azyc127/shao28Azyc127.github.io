#include <bits/stdc++.h>
using namespace std;
#define FILENAME "expand"
struct myin{
    static inline ifstream fin{FILENAME".in"};
    char buf[1<<20],*s,*p;
    myin(){ flush(); }
    void flush(){ *buf=0, fin.read(buf,sizeof(buf)), s=buf, p=s+fin.gcount(); }
    void prog(){ if(++s==p) flush(); }
    void skip(){ while(*s==' '||*s=='\r'||*s=='\n') prog(); }
    myin& operator>>(char& x){
        skip(), x=*s, prog();
        return *this;
    }
    myin& operator>>(auto& x){
        x=0;
        for(;!isdigit(*s);prog());
        for(; isdigit(*s);prog()) (x*=10)+=*s^'0';
        return *this;
    }
}fin;
struct myout{
    static inline ofstream fout{FILENAME".out"};
    char buf[1<<20],*s{buf};
    ~myout(){ flush(); }
    void flush(){ fout.write(buf,s-buf), s=buf; }
    void prog(){ if(++s==end(buf)) flush(); }
    myout& operator<<(char x){
        *s=x, prog();
        return *this;
    }
    myout& operator<<(auto x){
        char buf[20],*p{buf};
        do *(p++)=x%10^'0'; while(x/=10);
        while(p-->buf) *s=*p, prog();
        return *this;
    }
}fout;

enum{ N=500005 };
int n,m;
array<int,N> x,y;

bool work(){
    if(x[1]<y[1]) swap(x,y), swap(n,m);
    if(!(x[1]>y[1]&&x[n]>y[m])) return false;
    int p{1},q{1},i{2},j{2};
    while(1){
        bool flg{false};
        for(;i<=n&&x[i]>y[q];i++)
            if(x[i]>=x[p]) p=i, flg=true;
        for(;j<=m&&y[j]<x[p];j++)
            if(y[j]<=y[q]) q=j, flg=true;
        if(flg) continue;
        if(i<=n||j<=m) return false;
        break;
    }
    int s{n},t{m},k{n-1},l{m-1};
    while(1){
        bool flg{false};
        for(;k>=1&&x[k]>y[t];k--)
            if(x[k]>=x[s]) s=k, flg=true;
        for(;l>=1&&y[l]<x[s];l--)
            if(y[l]<=y[t]) t=l, flg=true;
        if(flg) continue;
        if(k>=1||l>=1) return false;
        break;
    }
    if(p>=s&&q>=t) return true;
    return true;
}
int main(){
    static array<int,N> x,y;
    int c,n,m,q; fin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) fin>>x[i];
    for(int j=1;j<=m;j++) fin>>y[j];
    ::x=x, ::y=y, ::n=n, ::m=m;
    fout<<work();
    while(q--){
        ::x=x, ::y=y, ::n=n, ::m=m;
        int qx,qy; fin>>qx>>qy;
        while(qx--){ int i,v; fin>>i>>v; ::x[i]=v; }
        while(qy--){ int i,v; fin>>i>>v; ::y[i]=v; }
        fout<<work();
    }
    fout<<'\n';
}