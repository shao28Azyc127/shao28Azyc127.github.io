#include <iostream>

using namespace std;
int n, cnt = 0, ans, x;
bool a[1000000005];
bool abc(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == false) return false;
    }
    return true;
}
bool bcd;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(abc(n) == false)
    {
        ans++;
        cnt = 2;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == true) continue;
            cnt++;
            if(cnt == 3)
            {
                a[i] = true;
                cnt = 0;
            }
            if(a[n] == true && bcd == false)
            {
                x = ans;
                bcd = true;
            }
        }
    }
    cout << ans << " " << x << endl;

    return 0;
}
