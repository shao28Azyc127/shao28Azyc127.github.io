#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std ;
const int inf = (int)1e18 ;
int n , a[N] , b[N] , c[N] , d[N] ;
void solve() {
    int l = n , r = inf , best = -1 ;
    while(l <= r) {
        int mid = (l + r) / 2 ;
        bool flag = true ;
        for(int i = 1 ; i <= n ; i++) {
            int tim = mid - i + 1 ;
            if(c[i] >= 0) {
                if((int)ceil(1.0 * a[i] / b[i]) <= tim) {
                    continue ;
                }
                int now = tim * b[i] ;
                int lft = a[i] - now ;
                if(!c[i]) {
                    flag = false ;
                    break ;
                }
                int qwq = (int)ceil(1.0 * lft / c[i]) ;
                int qwq1 = (int)ceil(1.0 * qwq / tim) ;
                if(tim + 1 < qwq1) {
                    flag = false ;
                    break ;
                }
            }
            else {
                int to = (int)ceil(1.0 * b[i] / (-c[i])) ;
                if(tim >= to) {
                    int xiangshu = to - 1 ;
                    int shoujiamo = (int)ceil(2 * a[i] / xiangshu) ;
                    int moxiang = b[i] + c[i] * (to - 1) ;
                    if(moxiang + b[i] + c[i] < shoujiamo) {
                        flag = false ;
                        break ;
                    }
                }
                else {
                    int xiangshu = to - 1 ;
                    int shoujiamo = (int)ceil(2 * a[i] / xiangshu) ;
                    int moxiang = b[i] + c[i] * (to - 1) ;
                    if(to == 1) {
                        if(tim < a[i]) {
                            flag = false ;
                            break ;
                        }
                        continue ;
                    }
                    if(moxiang + b[i] + c[i] >= shoujiamo) {
                        continue ;
                    }
                    int lbb = (moxiang + b[i] + c[i]) * xiangshu / 2 ;
                    int lft = a[i] - lbb ;
                    if(tim - to < lft) {
                        flag = false ;
                        break ;
                    }
                }
            }
        }
        if(flag) {
            best = mid ;
            r = mid - 1 ;
        }
        else {
            l = mid + 1 ;
        }
    }
    printf("%lld" , best) ;
}
signed main() {
    freopen("tree.in" , "r" , stdin) ;
    freopen("tree.out" , "w" , stdout) ;
    scanf("%lld" , &n) ;
    for(int i = 1 ; i <= n ; i++) {
        scanf("%lld%lld%lld" , &a[i] , &b[i] , &c[i]) ;
    }
    for(int i = 1 ; i < n ; i++) {
        int u , v ;
        scanf("%lld%lld" , &u , &v) ;
        d[u] = v ;
    }
    bool f = true ;
    for(int i = 1 ; i < n ; i++) {
        if(d[i] != i + 1) {
            f = false ;
            break ;
        }
    }
    if(f) {
        solve() ;
        return 0 ;
    }
    
    return 0 ;
}