#include<bits/stdc++.h>
#define mem(a, x) memset(a, x, sizeof(a))
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
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
const int NR=2e6+10;
typedef long long LL;
LL n, f[NR], g[NR], stk[NR], top;
char s[NR];
namespace baoli {
    char stk[NR];
    void solve() {
        LL ans=0;
        rps(l, 1, n) {
            top=0;
            rps(r, l, n) {
                if(top>0 && stk[top]==s[r])top--;
                else stk[++top]=s[r];
                if(top==0)ans++;
            }
        }
        printf("%lld\n", ans);
    }
}
int main() {
    opf("game");
    read(n);
    scanf("%s", s+1);
    if(n<=8000) {
        baoli::solve();
        return 0;
    }
    puts("0");
    return 0;
}
}
int main() {
    return cszhpdx::main();
}