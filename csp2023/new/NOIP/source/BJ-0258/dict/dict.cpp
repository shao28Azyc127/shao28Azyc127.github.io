//about 100pts
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
char a[3005][3005], b[3005][3005];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sort(a[i], a[i] + m);
        strcpy(b[i], a[i]);
        reverse(b[i], b[i] + m);
    }
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (strcmp(b[j], a[i]) < 0) {
                flag = false;
                break;
            }
        }
        cout << flag;
    }
    cout << '\n';
    return 0;
}
