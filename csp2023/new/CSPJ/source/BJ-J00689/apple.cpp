#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef long long LL;

int main() {
    FILE *fpi, *fpo;
    fpi = freopen("apple.in", "r", stdin);
    fpo = freopen("apple.out", "w+", stdout);

    LL n, ans = 0, ret = 1;
    scanf("%lld", &n);
    LL *flags = new LL[n];
    for(LL i = 0; i < n; flags[i] = 1, i++);//init arr
    flags[n - 1] = -1;
    while(n > 0) {
        LL tempn = n;
        for(LL i = 1; i <= n; i += 3) {
            if(flags[i - 1] == -1)
                ret = ans;
            tempn--;
            flags[i - 1] = 0;
        }
        n = tempn;
        LL *tmpf = new LL[tempn];
        for(LL i = 0, j = 0; i < n; i++) {
            if(flags[i] != 0) {
                tmpf[j] = flags[i];
                j++;
            }
        }
        delete[] flags;
        flags = tmpf;
        ans++;
    }
    delete[] flags;
    printf("%lld 1", ans);
    fclose(fpi);
    fclose(fpo);
    return 0;
}