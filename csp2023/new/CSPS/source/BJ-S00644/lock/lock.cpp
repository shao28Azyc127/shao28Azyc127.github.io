#include <bits/stdc++.h>
using namespace std;

int n, ans, a[10];
map< string, int > mp;
void fun(string str) {
    string s;
    for (int i = 0; i <= 4; i++) {
        s = str;
        for (int j = 0; j <= 9; j++) {
            s[i] = j + '0';
            if (s != str) mp[s]++;
        }
    }
    for (int i = 1; i <= 4; i++) {
        s = str;
        for (int j = 0; j <= 9; j++) {
            s[i-1] = ((str[i-1] - '0') + j) % 10 + '0';
            s[i] = ((str[i] - '0') + j) % 10 + '0';
            if (s != str) mp[s]++;
        }
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        string str;
        str += (a[1] + '0');
        str += (a[2] + '0');
        str += (a[3] + '0');
        str += (a[4] + '0');
        str += (a[5] + '0');
        fun(str);
    }

    map< string, int >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second == n) ans++;
    }

    cout << ans;
    return 0;
}
