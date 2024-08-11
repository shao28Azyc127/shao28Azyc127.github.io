#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int days() {
    int t = n, d = 0;
    while(t) {
        t -= ceil(t / 3.0);
        d++;
    }
    return d;
} 
int getn() {
    int t = n, d = 1;
    while(t % 3 != 1 && t) {
        t -= ceil(t / 3.0);
        d++;
    }
    return d;
}
signed main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cout<<days()<<" "<<getn()<<endl;
    return 0;
}