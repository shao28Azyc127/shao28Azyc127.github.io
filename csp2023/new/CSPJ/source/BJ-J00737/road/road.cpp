#include<iostream>
#include<cmath>
using namespace std;
const int inf = 1e9;
const int maxn = 1e5 + 5;
int n, d, mn = inf, sum, last, ans, v[maxn], a[maxn];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; ++i) scanf("%d", &v[i]), sum += v[i];
    for(int i = 1; i < n; ++i) scanf("%d", &a[i]), mn = min(mn, a[i]);
    if(a[1] == mn) printf("%.0lf", ceil(sum / d) * a[1]);
    else {
        for(int i = 1; i <= n; ++i){
            if(i == 1) ans += v[1] / d * a[1], last = a[1];
            else if(last > a[i]) ans += v[i] / d * a[i], last = a[i];
            else ans += v[i] / d * last;
        }
        printf("%d", ans);
    }
    return 0;
}
