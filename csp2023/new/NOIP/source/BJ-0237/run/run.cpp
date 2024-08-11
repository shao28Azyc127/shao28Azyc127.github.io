#include<bits/stdc++.h>
using namespace std;
#define $in 1<<20
#define getc() p1==p2&&(p1=buf)==(p2=buf+fread_unlocked(buf,1,$in,stdin))?-1:*p1++
#define putc(x) putchar_unlocked(x) 
char buf[$in],*p1(buf),*p2(buf);

template<class T>
inline void in(T& x){
    char y=getc();
    while(!isdigit(y))
    	y=getc();
    x=0;
    do x=10*x+(y^'0');
    while(isdigit(y=getc()));
}

template<class T>
inline void out(T x){
    if(x>9) out(x/10);
    putc(x%10^'0');
}
#define Nsiz 100001
unordered_map<int,array<int64_t,100001>>M;
basic_string<int> A;
struct T{
    int l,r,v;constexpr bool operator<(T& other)const{
        return r==other.r?l<other.l:r<other.r;
    }
};basic_string<T> B;

int main() {
    freopen("run.in","rb",stdin);
    freopen("run.out","wb",stdout);
    
    int c,t;
    in(c);in(t);
    while(t--){
        int n,m,K,d;
        in(n);in(m);in(K);in(d);
        M.clear();
        A.clear(); B.clear();
        for(int i=0,l,r,v;i<m;++i){
            in(r);in(l);in(v);
            B.push_back({l,r,v});
            A.push_back(r);
        }sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        B.push_back({0,int(1e9+13)});
        for(int i=0;i<=K;++i)
            M[0][i]=0;
        int lst=0,j=0,k=0;
        int64_t lstmx=0,totmx=0;
        for(int i:A){
            if(i==lst) continue;
            while(B[j].r<i) ++j;
            k=j;
            while(B[k].r<=i) ++k;
            int64_t mx=0,sm=0;
            for(int p=0;p<i-lst&&p<=K;++p){
                for(;B[j].l<=p&&j<k;++j){
                    sm+=B[j].v;
                }
                M[i][p]=lstmx-d*p+sm;
                mx=max(mx,M[i][p]);
                // cerr<<M[i][p]<<' ';
            }
            for(int p=i-lst;p<=K;++p){
                for(;B[j].l<=p&&j<k;++j){
                    sm+=B[j].v;
                }
                int64_t tmp=M[lst][p-(i-lst)]-d*(i-lst)+sm;
                mx=max(mx,tmp);
                M[i][p]=tmp;
                // cerr<<M[i][p]<<' ';
            }
            // cerr<<'\n';
            totmx=max(totmx,mx);
            lstmx=mx;
            lst=i;
            j=k;
        }
        out(totmx);
        putc('\n');
    }
}