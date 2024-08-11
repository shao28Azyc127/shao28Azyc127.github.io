#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0, x;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    x = n;
    while(x > 1) {
        cnt ++;
        x -= (int)ceil(x / 3.0);
    }
    printf("%d ", cnt + 1);
    x = n;
    cnt = 0;
    while(x > 0) {
        cnt ++;
        if(x % 3 == 1) {
            printf("%d\n", cnt);
            return 0;
        }
        x -= (int)ceil(x / 3.0);
    }
    return 0;
}
