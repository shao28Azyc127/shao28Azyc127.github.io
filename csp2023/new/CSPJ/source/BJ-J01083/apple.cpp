#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, a[1000000002] = {}, i = 0, ans = 0, cnt = 0, day = 1, quzou = 0;
    scanf("%d", &n);
    if (n <= 3){
        printf("%d %d", n, n);
        return 0;
    }
    while (quzou < n){
        if (cnt % 3 == 0 && a[i] == 0){
            a[i]++;
            quzou++;
            fd--;
            if (i == n){
                ans = day;
            }
        } else if (a[i] == 0){
            cnt++;
        }
        i++;
        if (i > n){
            i -= n;
            day++;
        }
    }
    printf("%d %d", day, ans);
}