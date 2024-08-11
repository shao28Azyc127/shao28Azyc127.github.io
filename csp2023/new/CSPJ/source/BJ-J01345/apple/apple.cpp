#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, cnt, L[1000005], R[100005], i;
int max(int x, int y) {return x > y ? x : y;}
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n; int t = n;
    while (t >= 1) {
        ++cnt;
        t = t - max(1, ceil(t / 3.0));
    } cout << cnt << ' ';
    if (n % 3 == 1) {
         cout << "1\n";
         return 0;
    }
    if (n % 3 == 2) {
        cout << cnt << endl;
        return 0;
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) L[i] = i - 1, R[i] = i + 1;
    R[0] = 1; L[n + 1] = n, R[n + 1] = n + 1;
    i = 1;
    while (cnt < n) {
        int num = 0;
        int now = 0;
        while (now != n + 1) {
            if (num % 3 == 1) {
                if (now == n) {
                    cout << i << endl;
                    return 0;
                }
                L[R[now]] = L[now];
                R[L[now]] = R[now], ++cnt;
            } now = R[now];
            ++num;
        } ++i;
    }
    return 0;
}
/*
% 3 == 1 : 1
% 3 == 2 : last
3/ 5 8 9/ 12 14 17/ 18 21 23/ 26 27
1 : % 3 = 1
2 : % 9 = 2/6
3 :
*/
