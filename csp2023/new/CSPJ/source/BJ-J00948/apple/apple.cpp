#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("apple.in", "r",  stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int cnt = 0, d = 0;
    while (n > 0){
        cnt++;
        if (n % 3 == 1 && !d)
            d = cnt;
        int t = n / 3;
        if (n % 3) t++;
        n -= t;
    }
    printf("%d %d\n", cnt, d);
    return 0;
}
