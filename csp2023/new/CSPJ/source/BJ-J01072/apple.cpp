#include<bits/stdc++.h>
using namespace std;

long long n, cnt = 0, m, sum = 0;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    m = n;
    while(m >= 0) {
        if(m%3 == 1) sum = cnt + 1;
        if(m%3 != 0) m = m - m/3 - 1;
        else if(m%3 == 0) m = m - m/3;
        cnt++;
        if(m == 0) break;
    }
    if(n%3 == 1) cout << cnt <<' ' << 1;
    else cout << cnt << ' ' << sum;
    return 0;
}
