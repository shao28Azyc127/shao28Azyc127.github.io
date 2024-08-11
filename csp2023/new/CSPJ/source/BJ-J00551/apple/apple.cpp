#include <iostream>

using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;

    int ans = -1;
    int cnt = 0;
    while (n != 0){
        cnt++;
        if (n % 3 == 1 && ans == -1) ans = cnt;
        n -= n / 3 + bool(n % 3);
    }
    cout << cnt << " " << ans;
    return 0;
}
