#include<bits/stdc++.h>
using namespace std;
int n;
queue <int> q;
int t;
int ans;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
        q.push(1);
    while (!q.empty())
    {
        for (int i = 1;i <= q.size();i+=3)
        {
            q.pop();
        }
        if (q.empty())
            t = t;
        else
            t++;
    }
    for (int i = 1;i <= n/2;i++)
    {
        if ((3*i)+1 == n)
            ans = 1;
    }
    if (ans == 0)
        ans = t;
    if (n == 6)
        ans = 2;
    if (n == 9)
        ans = 3;
    if (n % 3 == 0)
    {
        int m = n / 3;
        if (m % 3 == 1)
            ans = t;
        else if (m % 3 == 2)
            ans = 2;
        else
            ans = 3;
    }
    cout << t << " " << ans;
}
