#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int res = 0;
    int tmp = 0;
    while(n) {
        res++;
        if(n % 3 == 1 && tmp == 0) {
            tmp = res;
        }
        n -= (n - 1) / 3 + 1;
    }
    cout << res << " " << tmp << endl;
    return 0;
}
