#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, d, v[N], a[N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    long long sum = 0, minn = LONG_LONG_MAX;
    for (int i = 1;i < n;i++){
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for (int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        if (a[i] < minn) minn = a[i];
    }
    if (minn == a[1]){
        cout << minn * sum;
        return 0;
    }
    if (d >= sum){
        cout << a[1];
        return 0;
    }
    int mo = 0, v2;
    a[n] = -1;
    for (int i = 1;i < n;i++){
        v2 = 0;
        for (int j = i + 1;j <= n;j++){
            v2 += v[j - 1];
            if (a[j] < a[i]){
                mo = mo + ceil(v2 * 1.0 / d) * a[i];
                i = j;
                break;
            }
        }
    }
    cout << mo;
    return 0;
}
