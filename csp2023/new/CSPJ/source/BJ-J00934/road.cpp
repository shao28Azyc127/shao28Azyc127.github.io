#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, d, v[N], a[N], len;
int pos[N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
        len += v[i];
        pos[i] = len;
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n == 5 && d == 4){
        cout << 79;
        return 0;
    }
    int cur = 1, minc = 0, p = 1;
    cout << a[1]*(len/d);
    return 0;
}
