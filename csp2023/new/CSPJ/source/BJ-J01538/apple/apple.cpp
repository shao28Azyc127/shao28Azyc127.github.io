#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, i = 1, txt = 0;
    int vis[199999999]
    cin >> n;
    while(true) {
        if(i > n) {
            for(int i = 1; i <= n; i++) {
                if(!vis[i]) {
                    txt = 1;
                }
            }
            if(!txt) {
                break;
            }
            j++;
            i = 0;
        }
        if(!vis[i]) {
            vis[i] = j;
        }
        i += 2;
    }
    cout << j << " " << vis[n] << endl;
    return 0;
}