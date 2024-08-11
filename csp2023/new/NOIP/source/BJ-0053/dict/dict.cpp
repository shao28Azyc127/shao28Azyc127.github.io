#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
#define TIME (clock()*1000/CLOCKS_PER_SEC)
#define debug cerr<<'['<<__LINE<<']'
const int N=3010,sig=26;
int trie[N*N][sig],ver;
int siz[N*N];
inline int id(const char&c){return c-'a';}
inline int insert(const char s[],const int n){
    int nd=0;
    for(int i=1;i<=n;i++){
        if(!trie[nd][id(s[i])])trie[nd][id(s[i])]=++ver;
        nd=trie[nd][id(s[i])];
    }
    return nd;
}
void dfs(int nd){
    for(int i=0;i<sig;i++)if(trie[nd][i])dfs(trie[nd][i]),siz[nd]+=siz[trie[nd][i]];
}
inline bool check(const char s[],const int n){
    int nd=0;
    for(int i=1;i<=n;i++){
        int t=id(s[i]);
        for(int j=0;j<t;j++)if(trie[nd][j]&&siz[trie[nd][j]])return false;
        nd=trie[nd][t];
        if(!nd)return true;
    }
    return true;
}
int n,m;
char s[N][N];
inline bool cmp1(const char&A,const char&B){return A<B;};
inline bool cmp2(const char&A,const char&B){return A>B;};
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        sort(s[i]+1,s[i]+m+1,cmp2);
        siz[insert(s[i],m)]++;
        sort(s[i]+1,s[i]+m+1,cmp1);
    }
    dfs(0);
}
int main(){
    // freopen("dict/dict4.in","r",stdin);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    init();
    for(int i=1;i<=n;i++){
        if(check(s[i],m))printf("1");
        else printf("0");
    }
    // cerr<<TIME<<endl;
    return 0;
}