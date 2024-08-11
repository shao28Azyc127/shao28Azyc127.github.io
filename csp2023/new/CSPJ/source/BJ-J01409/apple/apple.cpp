#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 1, d = -1;
    while (n != 1){
        if (n % 3 == 1 && d == -1) d = cnt;
        n = n - ceil(n / 3.0);
        cnt++;
    }
    if (n % 3 == 1 && d == -1) d = cnt;
    cout << cnt << " " << d;
    return 0;
}
