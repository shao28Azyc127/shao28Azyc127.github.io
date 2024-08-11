#include<bits/stdc++.h>
using namespace std;

int n, ans = 0;
int pick = 0;
int main()
{
    ios::sync_with_stdio(false);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    //freopen
    //freopen
    cin >> n;
    while(n)
    {
        ans++;
        if(n % 3 == 1 && !pick) pick = ans;
        n -= n / 3 + (n % 3 != 0);
    }
    cout << ans << " " << pick;
    return 0;
}
