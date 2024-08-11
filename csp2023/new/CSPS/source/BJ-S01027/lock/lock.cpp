#include <bits/stdc++.h>
using namespace std ;
int n , mp[200000] ;
int a[8] ;
int main() {
    freopen("lock.in" , "r" , stdin) ;
    freopen("lock.out" , "w" , stdout) ;
    scanf("%d" , &n) ;
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d%d%d%d%d" , &a[1] , &a[2] , &a[3] , &a[4] , &a[5]) ;
        for(int j = 1 ; j <= 5 ; j++) {
            for(int k = 0 ; k < 10 ; k++) {
                if(k == a[j]) continue ;
                int temp = a[j] ;
                a[j] = k ;
                mp[10000 * a[1] + 1000 * a[2] + 100 * a[3] + a[4] * 10 + a[5]]++ ;
                a[j] = temp ;
            }
        }
        for(int j = 1 ; j < 5 ; j++) {
            int k = j + 1 ;
            for(int fd = 1 ; fd < 10 ; fd++) {
                int pj = a[j] , pk = a[k] ;
                a[j] += fd ;
                if(a[j] > 9) a[j] -= 10 ;
                a[k] += fd ;
                if(a[k] > 9) a[k] -= 10 ;
                mp[10000 * a[1] + 1000 * a[2] + 100 * a[3] + 10 * a[4] + a[5]]++ ;
                a[j] = pj ;
                a[k] = pk ;
            }
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < 100000 ; i++) {
        if(mp[i] == n) ans++ ;
    }
    printf("%d" , ans) ;
    return 0 ;
}