#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000010;
bool used[MAXN];
int ans;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; /*j += 3*/){
            while (used[j] == 1 && j <= n){
                j ++;
            }
            if (j == n){
                ans = i;
            }
            if (j > n){
                cout << i-1 << " " << ans << endl;
                return 0;
            }

            for (int k = 0; k < 3; k ++){
                j ++;
                while (used[j] == 1 && j <= n){
                    j ++;
                }
            }
        }

    }

    return 0;
}
