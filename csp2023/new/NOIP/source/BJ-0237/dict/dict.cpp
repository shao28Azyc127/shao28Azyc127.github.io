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

char L[3001],R[3001];
char A[3001];
int B[27];
int main() {
    freopen("dict.in","rb",stdin);
    freopen("dict.out","wb",stdout);

    int n,m;
    in(n);in(m);
    for(int i=0;i<n;++i){
        bzero(B,sizeof B);
        for(int j=0;j<m;++j){
            char c=getc();
            ++B[c^'a'-1];
        }
        for(int j=0;j<27;++j)
            if(B[j]){
                L[i]=j;
                break;
            }
        for(int j=26;~j;--j)
            if(B[j]){
                R[i]=j;
                break;
            }
        cerr<<char(L[i]^'a'-1)<<' '<<char(R[i]+'a'-1)<<'\n';
        getc();
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j) continue;
            if(L[i]>=R[j])
                goto bad;
        }putc('1');
        if(0) bad:putc('0');
    }
}
