#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    int ans = 1;
    bool b = true;
    int cur = n;
    while ( cur) {
        if ( cur % 3 == 1 && b == true) {
            b = false;
        }
        else if ( b == true) {
            ans++;
        }
        cur -= (cur + 2) / 3;
        sum++;
    }
    cout << sum << " " << ans << endl;
    return 0;
}