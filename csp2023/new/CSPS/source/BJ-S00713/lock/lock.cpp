#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
using namespace std;
int a[10][10];
int pow10[10] = {0, 1, 10, 100, 1000, 10000};
int num[10];
long long ans;
set<int> st, st1, st2;
const int M = 100000;
int n;
void init() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 9; j++)
            st1.insert(pow10[i] * j);
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j <= 9; j++)
            st2.insert((pow10[i] + pow10[i + 1]) * j);
    }
    return;
}
bool check1(int x) {
    int cnt = 0;
    int tmp1[10];
    for (int i = 1; i <= n; i++) {
        int t = x;
        for (int j = 5; j >= 1; j--) {
            tmp1[j] = t % 10;
            t /= 10;
        }
        for (int j = 5; j >= 1; j--) {
            tmp1[j] = a[i][j] - tmp1[j];
            tmp1[j] += 10;
            tmp1[j] %= 10;
        }
        int sum = 0;
        for (int j = 1; j <= 5; j++) {
            sum *= 10;
            sum += tmp1[j];
        }
        if (st1.count(sum) || st2.count(sum)) cnt++;
    }
    if (cnt >= n) return true;
    return false;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            t += a[i][j] * pow10[6 - j];
        }
        num[i] = t;
        st.insert(t);
    }
    for (int i = 0; i < 100000; i++) {
        if (st.count(i)) continue;
        if (check1(i)) {
            //cout << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
