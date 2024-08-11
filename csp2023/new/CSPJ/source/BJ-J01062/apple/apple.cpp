#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;

    int ans1=0, tn=n;
    while (tn) {
        //cout << tmp << ' ' << tn << '\n';
        ans1++;
        tn-=(tn-1)/3+1;
    }

    cout << ans1 << ' ';

    int cnt=1;
    tn=n;
    while (tn) {
        if (tn%3 == 1) {
            cout << cnt << '\n';
            break;
        }
        //cout << tmp << ' ' << tn << '\n';
        cnt++;
        tn-=(tn-1)/3+1;
    }
    return 0;
}