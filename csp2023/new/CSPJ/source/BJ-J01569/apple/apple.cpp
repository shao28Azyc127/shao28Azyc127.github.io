#include <bits/stdc++.h>
using namespace std;
int n, k, day, ans;
vector <bool> a;
bool flag, fans = true;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        a.push_back(false);
    flag = true;
    while (flag) {
        flag = false;
        if (k > n)
            k = 0;
        while (a[k] == true) k++;
        if (k >= n) break;
        day++;
        int cnt = 0;
        a[k] = true;
        for (int i = k + 1; i <= n; i++) {
            flag = true;
            cnt++;
            if (a[i] == true) cnt--;
            if (a[n-1] == true && fans) {
                fans = false;
                ans = day;
            }
            if (cnt == 3) {
                cnt = 0;
                a[i] = true;
            }
            //cout << cnt << endl;
        }
        /*for (int i = 0; i < n; i++) {cout << a[i] << " ";}
        cout << endl;
        cout << day << " " << ans <<endl;*/
    }
    cout << day << " " << ans;
    return 0;
}