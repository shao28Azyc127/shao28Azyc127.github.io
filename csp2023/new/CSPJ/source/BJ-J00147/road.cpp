#include<bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i < n; i++)
        cin >> a[i];
    long long l = 0, you, s = 0, ans = 0;
    cin >> you;
    for(int i = 1; i < n; i++)
    {
        cin >> b[i];
        l += a[i];
        if(b[i] <= you || i == n)
        {
            long long ln = l;
            l -= s;
            l = (l - 1) / d + 1;
            ans += l * you;
            you = b[i];
            s = l * d - ln + s;
            l = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
