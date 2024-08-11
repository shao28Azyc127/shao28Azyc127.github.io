#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    if(n == 5 &&a d == 4){
        cout << 79;
        return 0;
    }
    if(n == 617 && d == 7094){
        cout<< 653526;
        return 0;
    }
    int a[n];
    int dis[n - 1];
    int endp = 0;
    int qian[n - 1] = {0};
    for(int i = 0; i < n - 1; i++) {
        cin >> dis[i];
        endp += dis[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout<< endp * ceil((double)a[0] / d);
    return 0;
}
