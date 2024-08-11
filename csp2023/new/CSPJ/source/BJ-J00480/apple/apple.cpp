#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    if (n==1) {
        cout << "1 1" << endl;
        return 0;
    }
    int i = n;
    int cnt = 0;
    bool flag = true;
    int sec;
    while (i > 0) {
        if (i % 3 == 1 && flag) {
            sec = cnt+1;
            flag = false;
        }
        i -= ceil(i/3.0);
        cnt++;
    }
    cout << cnt << ' ' << sec << endl;
    return 0;
}