#include <bits/stdc++.h>

using namespace std;

int n, ans1, ans2;
vector<int> v;

bool isEmpty() {
    for (int i = 0; i < n; i++)
        if (v[i] != -1)
            return false;
    return true;
}

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        v.push_back(i + 1);
    while (!isEmpty()) {
        ans1++;
        for (int i = 0, cnt = 0; i < n; i++) {
            if (v[i] == -1)
                continue;
            if (cnt != 0)
                continue;
            if (v[i] == n)
                ans2 = ans1;
            v[i] = -1;
            cnt++;
        }
    }
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
