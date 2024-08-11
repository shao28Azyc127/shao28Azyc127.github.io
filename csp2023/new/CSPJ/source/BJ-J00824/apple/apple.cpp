#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;

    int ans1 = 1, r1 = 0, r2 = 1;
    for (ans1 = 1; ans1 <= n; ans1++){
        long long fr = r1 + r2; r1 = r2; r2 = fr;
        if (fr >= n){
            break;
        }
    }

    cout << ans1 << " ";

    int ans2, lft = 3, rgt = 3; r1 = 0, r2 = 1;
    for (ans2 = 1; ans2 <= ans1; ans2++){
        int fr = r1 + r2; r1 = r2; r2 = fr;
        if ((n - fr) % (lft + rgt) == 0 || (n - fr) % (lft + rgt) == lft){
            break;
        }
        lft += ans2; rgt += ans2+1;
    }
    cout << ans2 << endl;

    return 0;
}
