#include <bits/stdc++.h>

using namespace std;

int n, ans, cnt, tmpn;
    vector<int> vt;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);
    tmpn = n;

    vt.push_back(0);
    for (int i = 1; i <= n; i++) {vt.push_back(i);}

    while (n > 0) {
        cnt++;
        for (int i = 1; i <= n; i += 3) {
            if (vt[i] == tmpn) ans = cnt;
            vt.erase(vt.begin() + i);
            i--;
            n--;
        }

        //for (int i = 1; i <= n; i++) {
        //    printf("%d ", vt[i]);
        //}
        //cout << endl;
        //cnt++;
    }

    printf("%d %d", cnt, ans);


    return 0;
}
