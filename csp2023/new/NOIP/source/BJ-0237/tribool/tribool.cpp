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

#define N 100001
list<int> T[N*2];
list<int> lst[N];
int nm[N*2],cnt,k;
int for_K[N*2];
int lK[N];
bitset<N> B;
int main() {
    freopen("tribool.in","rb",stdin);
    freopen("tribool.out","wb",stdout);
    
    int c,t;
    in(c);in(t);
    while(t--){
        int n,m;
        in(n);in(m);
        for(int i=1;i<=n;++i)
            lst[i]=T[i]={i+1};
        iota(nm+1,nm+n+1,2);
        iota(lK+1,lK+n+1,1);
        k=cnt=n+1;
        for(int i=1,p,q;i<=m;++i){
            char t=getc();
            switch(t){
                case '+':in(p);in(q);
                    lst[p].push_back(cnt);
                    nm[cnt]=nm[lst[q].back()];
                    T[lK[q]].push_back(p);
                    lK[p]=lK[q];
                    ++cnt;
                    continue;
                case '-':in(p);in(q);
                    lst[p].push_back(cnt);
                    nm[cnt]=-nm[lst[q].back()];
                    T[lK[q]].push_back(p);
                    lK[p]=lK[q];
                    ++cnt;continue;
                case 'T':
                    in(p);
                    lst[p].push_back(cnt);
                    nm[cnt]=1;++cnt;
                    lK[p]=k;
                    T[k].push_back(p);
                    for_K[k]=1;
                    ++k;
                    continue;
                case 'F':in(p);
                    lst[p].push_back(cnt);
                    nm[cnt]=-1;++cnt;
                    lK[p]=k;
                    T[k].push_back(p);
                    for_K[k]=1;
                    ++k;
                    continue;
                case 'U':in(p);
                    lst[p].push_back(cnt);
                    nm[cnt]=0;++cnt;
                    lK[p]=k;
                    T[k].push_back(p);
                    for_K[k]=1;
                    ++k;
            }
        }
        B.set();
        int cnt=0,lstcnt=0;
        for(int i=1;i<=n;++i){
        if(nm[lst[i].back()]==1){
            nm[i]=1;for_K[i]=1;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==-1){
            nm[i]=-1;for_K[i]=-1;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==0){
            nm[i]=0;for_K[i]=0;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==-nm[i]){
            nm[i]=0;for_K[i]=0;for_K[lK[i]]=0;B[i]=0;++cnt;}
        }
        do{
        lstcnt=cnt;
        for(int i=B._Find_next(0);i<=n;i=B._Find_next(i)){
            if(lK[i]<=n&&(for_K[lK[i]]==1||for_K[lK[i]]==0||for_K[lK[i]]==-1))
                if(nm[lst[i].back()]<0){
                B[i]=0;nm[i]=nm[lst[i].back()]=-for_K[lK[i]];++cnt;}
                else{
                B[i]=0;nm[i]=nm[lst[i].back()]=for_K[lK[i]];++cnt;
                }
        }
        for(int i=B._Find_next(0);i<=n;i=B._Find_next(i)){
        if(nm[lst[i].back()]==1){
            nm[i]=1;for_K[i]=1;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==-1){
            nm[i]=-1;for_K[i]=-1;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==0){
            nm[i]=0;for_K[i]=0;B[i]=0;++cnt;}
        if(nm[lst[i].back()]==-nm[i]){
            nm[i]=0;for_K[i]=0;for_K[lK[i]]=0;B[i]=0;++cnt;}
        }
        }while(cnt!=lstcnt);
        int res=0;
        
        for(int i=0;i<n;++i){
            if(!nm[i]) ++res;
        }
        out(res);putc('\n');
    }
    
}