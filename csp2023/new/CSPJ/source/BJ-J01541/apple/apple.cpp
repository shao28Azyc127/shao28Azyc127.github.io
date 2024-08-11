#include <bits/stdc++.h>

using namespace std;

long long n, a[100000000], day = 0, outDay;

bool cmp(int a, int b) {
    if(a < b) return true;
    else return false;
}

int main() {

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;

    memset(a, -1, sizeof(a));

    while(a[1] != 0) {
        for(int i = 1; i <= n; i += 3) {
            if(a[i] == a[n]) {
                outDay = day;
            }

            a[i] = 0;
        }
        sort(a+1, a+n+1, cmp);
        day++;
    }

    cout << day << " " << ++outDay;

    return 0;
}
