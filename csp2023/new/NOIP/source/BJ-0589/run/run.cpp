#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100050;
typedef long long ll;
typedef unsigned long long ull;
int c, t, n, m, k, d;
struct mission{
    int x, y, v;    
    bool operator < (const mission& a) const{
        return y == a.y ? x < a.x : y < a.y;
    }
}mis[MAXN];
ll read()
{
    ll ans = 0;
    char inc = getchar();
    for(; inc < '0' || inc > '9'; ) inc = getchar();
    for(; inc >= '0' && inc <= '9'; ){
        ans = ans * 10 + inc - '0';
        inc = getchar();
    }
    return ans;
}
void work()
{
    ll ans = 0;
    n = read(), m = read(), k = read(), d = read();
    //fill(di, di + 1 + m, 0);
    for(int i = 1; i <= m; i++)     
        mis[i].x = read(), mis[i].y = read(), mis[i].v = read();
    for(int i = 1; i <= m; i++){
        if(mis[i].y - mis[i].x + 1 <= k)
            ans += mis[i].v - (mis[i].y - mis[i].x + 1) * d;
    }
    printf("%lld\n", ans);
}
int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    c = read(), t = read();
    while(t--){
        work();
    }
    return 0;
}