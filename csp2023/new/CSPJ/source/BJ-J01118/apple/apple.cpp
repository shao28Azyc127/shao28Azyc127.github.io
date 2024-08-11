#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin >> n;
    while(n > 0)
    {
        cnt++;
        if(n % 3 == 0)
            n -= n / 3;
        else if(n % 3 == 1)
        {
            if(ans == 0)
                ans = cnt;
            n -= n / 3 + 1;
        }
        else
            n -= n / 3 + 1;
    }

    cout << cnt << " " << ans << endl;

    return 0;
}