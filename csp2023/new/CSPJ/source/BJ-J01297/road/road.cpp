#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, d, cnt, ans;
long long v[N], a[N];
long long  f(long long  x, long long  y) {
    if(x % y == 0) return x / y;
    return x / y + 1;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 2;i <= n;i ++)
        {cin >> v[i]; v[i] += v[i - 1]; }
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    a[n] = -1;
    long long  i = 1;
    while(i != n) {
        long long  j = i;
        while(a[j] >= a[i]) j ++;
        long long  dis = v[j] - v[i];
        if(f((dis - cnt), d) < f(dis, d)) {
            long long k = cnt;
            while(f((dis - cnt), d) == f((dis - k), d)) k --;
            k ++;
            cnt -= k;
            dis -= k;
        }
        long long  x = f(dis, d);
        ans += x * a[i];
        cnt += x * d - dis;
        i = j;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
