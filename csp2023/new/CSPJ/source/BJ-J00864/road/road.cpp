#include <bits/stdc++.h>
using namespace std;

int n, d, v[100010], a[100010], s[100010], oil, x;

int main()
{
    cin >> n >> d;
    for(int i = 2;i <= n; i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    int i = 1;
    while(i <= n)
    {
        int tmp = i, minn = 1e9;
        for(int j = i + 1;j <= n; j++)
            if(a[j] < a[i])
            {
                minn = min(minn, int(ceil(1.0 * (s[j] - s[i - 1]) / d) - oil) * a[i]);
                tmp = j;
            }
        x += minn;
        oil = 0;
        i = tmp;
    }
    cout <<x << endl;
    return 0;
}
