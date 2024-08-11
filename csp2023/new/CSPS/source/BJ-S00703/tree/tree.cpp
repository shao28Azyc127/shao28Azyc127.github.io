#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int a[maxn], b[maxn], c[maxn];
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        long long tmp;
        if (c[i] == 0){
            tmp = ceil(1.0 * a[i] / b[i]);
        }
        if (c[i] > 0){
            double A = c[i], B = 2 * b[i] + 2 * c[i] * i - c[i], C = -2 * a[i];
            double res = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
            tmp = ceil(res);
        }
        if (c[i] < 0){
            int D = floor(1.0 * (b[i] - 1) / -c[i]);
            if (D < i){
                tmp = a[i];
            }else{
                if ((D - i + 1) * b[i] + (D - i + 1) * (D + i) * c[i] / 2.0 >= a[i]){
                    double A = c[i], B = c[i] + 2 * b[i], C = c[i] * (i - i * i) - 2 * i * b[i] - 2 * a[i];
                    double res = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
                    tmp = ceil(res);
                }else{
                    int B = 1, C = a[i] - (D - i + 1) * b[i] - (D - i + 1) * (D + i) * c[i] / 2.0 + i - 1;
                    double res = 1.0 * C / B;
                    tmp = ceil(res);
                }
            }
        }
        ans = max(ans, tmp + i - 1);
    }
    cout << ans;
    return 0; 
}