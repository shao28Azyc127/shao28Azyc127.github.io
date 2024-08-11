#include <iostream>
using namespace std;

const int N = 200000;
int s[N], v[N];
int n, d, minn = 0;
long long sum = 0ll;

void jisuan(int su, int p) {
    while (su > 0) {
        if (p > n) break;
        int sheng = su;
        su -= s[p];
        s[p] -= sheng;
        if (s[p] < 0) s[p] = 0;
        p++;
    }
}

int main () {
    cin >> n >> d;
    for (int i = 2; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    minn = v[1];
    for (int i = 1; i < n; i++) {
        minn = min(minn, v[i]);
        int k = s[i+1] / d;
        if (k*d == s[i+1]) ;
        else k++;
        sum+= minn*k;
        jisuan(d*k, i+1);
    }
    cout << sum;
    return 0;
}
