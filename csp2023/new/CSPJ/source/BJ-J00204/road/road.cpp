#include <iostream>
using namespace std;
int n, d, nowoil;
int longg[100005];
int value[100005];
int minn = 100000000;
int dp[100005];//此站点加几升
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 2;  i <= n; i++) {
        cin >> longg[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> value[i];
        minn = min(minn, value[i]);
    }
    if(minn = value[1]) {
        if(n % minn == 0) {
            cout << n / minn << endl;
        }
        else {
            cout << n / minn + 1 << endl;
        }
    }
    return 0;
}
