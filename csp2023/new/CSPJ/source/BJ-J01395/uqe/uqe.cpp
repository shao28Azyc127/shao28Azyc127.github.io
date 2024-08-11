#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%lld %lld", &t, &m);
    while (t--){
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        double x1 = 0, x2 = 0;
        double de = b * b - 4 * a * c;
        if (de < 0){
            printf("NO\n");
            continue;
        }
        int u = sqrt(d);
        if (de == 0){
            double f = -1 * b / a * 2;
            if (f == int(f)){
                cout << f << endl;
                continue;
            }
            else {
                cout << -1 * b << '/' << a * 2 << endl;
                continue;
            }
        }
        if (de > 0){
            double p = -1 * b + sqrt(de) / (a * 2);
            double q = -1 * b - sqrt(de) / (a * 2);
            double maxn = max(p, q);
            if (maxn = int(maxn)){
                cout << maxn << endl;
            }
            else {
                cout << b * -1 << "/" << (a * 2) << "+" << "sqrt(" << de << ")" << "/" << (2 * a) << endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
