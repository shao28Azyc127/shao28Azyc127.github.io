#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long n, ans1, cnt = 0;
bool f = true;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n > 0)
    {
        cnt++;
        if(n % 3 == 1 && f == true)ans1 = cnt, f = false;
        n -= ceil(n / 3.0);
    }
    cout << cnt << " " << ans1 << "\n";
    return 0;
}
