#include <bits/stdc++.h>
#define int long long
using namespace std ;
string t , t1 , m , m1 ;
string dy[1010] ;
map<string , int>mp ;
struct node {
    string s ;
    int x ;
};
map<int , node>stu ;
map<string , int>dq ;
int num ;
signed main() {
    freopen("struct.in" , "r" , stdin) ;
    freopen("struct.out" , "w" , stdout) ;
    int n , adr = -1 ;
    scanf("%lld\n" , &n) ;
    while(n--) {
        int op ;
        scanf("%lld " , &op) ;
        if(op == 1) {
            int x , ans = 1 , yuan = adr ;
            cin >> t ;
            scanf("%lld" , &x) ;
            getchar() ;
            for(int step = 1 ; step <= x ; step++) {
                int yuan = adr ;
                cin >> t1 >> m ;
                int len ;
                if(t1 == "byte") {
                    len = 1 ;
                }
                else if(t1 == "short") {
                    len = 2 ;
                }
                else if(t1 == "int") {
                    len = 4 ;
                }
                else {
                    len = 8 ;
                }
                ans = max(ans , len) ;
                adr++ ;
                int qwq = (adr % len == 0 ? len : adr % len) ;
                int add = len - qwq ;
                adr += add ;
                adr-- ;
                int now = adr + 1 ;
                string rcc = "." ;
                rcc += m ;
                stu[step] = (node){rcc , len} ;
                for(int i = 1 ; i <= len ; i++) {
                    adr++ ;
                }
            }
            printf("%lld %lld\n" , adr - yuan , ans) ;
            dq[t] = ans ;
            num = x ;
            adr = yuan ;
        }
        else if(op == 2) {
            cin >> t >> m ;
            if(t != "byte" && t != "short" && t != "int" && t != "long") {
                for(int st = 1 ; st <= num ; st++) {
                    int len = stu[st].x ;
                    m1 = m ;
                    m1 += stu[st].s ;
                    adr++ ;
                    int qwq = (adr % len == 0 ? len : adr % len) ;
                    int add = len - qwq ;
                    adr += add ;
                    adr-- ;
                    int now = adr + 1 ;
                    if(st < 2) printf("%lld\n" , now) ;
                    for(int i = 1 ; i <= len ; i++) {
                        dy[++adr] = m1 ;
                    }
                    mp[m1] = now + 1 ;
                }
                continue ;
            }
            int len ;
            if(t == "byte") len = 1 ;
            else if(t == "short") len = 2 ;
            else if(t == "int") len = 4 ;
            else len = 8 ;
            adr++ ;
            int qwq = (adr % len == 0 ? len : adr % len) ;
            int add = len - qwq ;
            adr += add ;
            adr-- ;
            int now = adr + 1 ;
            for(int i = 1 ; i <= len ; i++) {
                dy[++adr] = m ;
            }
            mp[m] = now + 1 ;
            printf("%lld\n" , now) ;
        }
        else if(op == 3) {
            cin >> m ;
            if(mp[m]) printf("%lld\n" , mp[m] - 1) ;
            else printf("ERR\n") ;
        }
        else {
            int x ;
            scanf("%lld" , &x) ;
            getchar() ;
            if(dy[x] == "") printf("ERR\n") ;
            else cout << dy[x] << endl ;
        }
    }
    return 0 ;
}