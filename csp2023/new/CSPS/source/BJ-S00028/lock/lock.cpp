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
const int NR=1e5+10;
bitset<NR>ans;
int a[10], n;
inline int hsh(int *a) {
    // rps(i, 1, 5)printf("%d ", a[i]);puts("a");
    int res=0;
    rps(i, 1, 5)res=res*10+a[i];
    return res;
}
int main() {
    opf("lock");
    ans.set();
    read(n);
    while(n--) {
        bitset<NR>yq;
        rps(i, 1, 5)read(a[i]);
        rps(i, 1, 5) {
            int tp=a[i];
            rps(j, 0, 9)if(j!=tp) {
                a[i]=j;
                yq[hsh(a)]=true;
            }
            // puts("");
            a[i]=tp;
        }
        rps(i, 1, 4) {
            int tp1=a[i], tp2=a[i+1];
            rps(j, 1, 9) {
                a[i]=(tp1+j)%10;
                a[i+1]=(tp2+j)%10;
                yq[hsh(a)]=true;
            }
            // puts("");
            a[i]=tp1, a[i+1]=tp2;
        }
        ans&=yq;
    }
    printf("%d\n", (int)ans.count());
    return 0;
}
}
int main() {
    return cszhpdx::main();
}