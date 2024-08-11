#include<bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace cszhpdx {
template<class T>
void read(T &x) {
    x=0;
    bool f=false;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'), c=getchar();
    while(isdigit(c))x=x*10+(c-'0'), c=getchar();
    if(f)x=-x;
}
const int NR=3010;
int n, m;
// string s[NR], mn;
char s[NR][NR];
int mnp, cmnp;
char ac[NR];
int main() {
    opf("dict");
    // ios::sync_with_stdio(false);
    // cin>>n>>m;
    // rps(i, 1, n) {
    //     cin>>s[i];
    //     sort(s[i].begin(), s[i].end(), greater<char>());
    //     if(i==1)mn=s[1], mnp=1;
    //     else if(s[i]<mn)mn=s[i], mnp=i;
    // }
    // mn="", cmnp=0;
    // rps(i, 1, n) {
    //     if(i==mnp)continue;
    //     if(cmnp==0 || s[i]<mn)mn=s[i], cmnp=i;
    // }
    // if(n==1) {
    //     cout<<"1"<<endl;
    //     return 0;
    // }
    // rps(i, 1, n) {
    //     mn=s[i];
    //     reverse(mn.begin(), mn.end());
    //     if(i!=mnp)ac[i]=(mn<s[mnp] ? '1' : '0');
    //     else ac[i]=(mn<s[cmnp] ? '1' : '0');
    // }
    // cout<<ac+1<<endl;
    // auto bgtick=clock();
    read(n), read(m);
    rps(i, 1, n) {
        scanf("%s", s[i]+1);
        sort(s[i]+1, s[i]+m+1, greater<char>());
        if(i==1 || strcmp(s[mnp]+1, s[i]+1)>0)mnp=i;
    }
    if(n==1) {
        puts("1");
        return 0;
    }
    rps(i, 1, n) {
        if(i==mnp)continue;
        if(cmnp==0 || strcmp(s[cmnp]+1, s[i]+1)>0)cmnp=i;
    }
    rps(i, 1, n) {
        reverse(s[i]+1, s[i]+m+1);
        if(i!=mnp)putchar((strcmp(s[i]+1, s[mnp]+1)<0) ? '1' : '0');
        else putchar((strcmp(s[i]+1, s[cmnp]+1)<0) ? '1' : '0');
        reverse(s[i]+1, s[i]+m+1);
    }
    puts("");
    // cerr<<1.0*(clock()-bgtick)/CLOCKS_PER_SEC<<endl;
    return 0;
}
}
int main() {
    return cszhpdx::main();
}