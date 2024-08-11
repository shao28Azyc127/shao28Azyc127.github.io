#include <bits/stdc++.h>
#define int long long
#define N 8010
using namespace std ;
char a[N] ;
bool dp[N][N] ;
signed main() {
    freopen("game.in" , "r" , stdin) ;
    freopen("game.out" , "w" , stdout) ;
    int n ;
    scanf("%lld\n" , &n) ;
    for(int i = 1 ; i <= n ; i++) {
        scanf("%c" , &a[i]) ;
    }
    scanf("\n") ;
    for(int i = 1 ; i < n ; i++) {
        if(a[i] == a[i + 1]) dp[i][i + 1] = true ;
    }
    for(int len = 4 ; len <= n ; len += 2) {
        for(int i = 1 ; i + len - 1 <= n ; i++) {
            int j = i + len - 1 ;
            if(a[i] == a[j]) dp[i][j] |= dp[i + 1][j - 1] ;
            for(int k = i ; k < j ; k++) {
                dp[i][j] |= (dp[i][k] & dp[k + 1][j]) ;
            }
        }
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = i ; j <= n ; j++) {
            ans += dp[i][j] ;
        }
    }
    printf("%lld" , ans) ;
    return 0 ;
}