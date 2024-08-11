#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 1,don,st,cnt1 = 0;
    queue<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push(i);
    }
    while(!a.empty())
    {
        cnt1 = (cnt1 + 1) % 3;
        st = a.front();
        a.pop();
        if(cnt1 != 1)
        {
            a.push(st);
        }
        else
        {
            if(st == n)
            {
                don = cnt;
            }
        }
        if(st >= a.front())
        {
            cnt++;
            cnt1 = 0;
        }
    }
    cout << cnt - 1<< " " << don;
    return 0;
}
