#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, cnt[N], a[6], ans;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5]);
        int num = 10000*a[1]+1000*a[2]+100*a[3]+10*a[4]+a[5];
        for(int j = 1; j <= 4; j++){
            int k = j+1, b[6];
            b[1] = a[1], b[2] = a[2], b[3] = a[3], b[4] = a[4], b[5] = a[5];
            for(int l = 1; l <= 9; l++){
                b[j]++, b[k]++;
                b[j] %= 10, b[k] %= 10;
                cnt[10000*b[1]+1000*b[2]+100*b[3]+10*b[4]+b[5]]++;
            }
        }
        for(int j = 1; j <= 5; j++){
            int b[6];
            b[1] = a[1], b[2] = a[2], b[3] = a[3], b[4] = a[4], b[5] = a[5];
            for(int l = 1; l <= 9; l++){
                b[j]++, b[j] %= 10;
                cnt[10000*b[1]+1000*b[2]+100*b[3]+10*b[4]+b[5]]++;
            }
        }
    }
    for(int i = 0; i < 100000; i++)
        if(cnt[i] == n) ans++;
    printf("%d", ans);
    return 0;
}
