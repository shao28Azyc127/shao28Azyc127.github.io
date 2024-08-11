#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    bool a[10000] = {0};
    cin >> n;
    int cnt = 0;
    int cntday = 0;
    int ansday = 1;
    while(true)
    {
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                cnt++;
            }
        }
        if (cnt == 0) break;
        else cntday++;
        for (int i = 0; i < cnt; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < cnt; i += 3)
        {
            if (a[i] == 0)
            {
                a[i] = 1;
            }
        }
    }
    if (n % 3 == 1) ansday = 1;
    else if (n % 3 == 0) ansday = cntday;
    cout << cntday << " " << ansday << endl;
    return 0;
}
