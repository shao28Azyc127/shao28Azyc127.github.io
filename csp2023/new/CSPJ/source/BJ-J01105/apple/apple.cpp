#include <iostream>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int ceildiv(int a, int b) {
    if (a % b == 0) return a / b;
    return a / b + 1;
}

int main() {

freopen("apple.in","r",stdin);freopen("apple.out","w",stdout);

    int n;
    cin >> n;

    int cnt = n, ans = 0, day = -1;
    while (cnt) {
        ans++;
        if (cnt % 3 == 1 && day == -1) {
            day = ans;
        }
        cnt = cnt - ceildiv(cnt, 3);
    }

    cout << ans << ' ' << day;

    return 0;
}
