#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int cnt = 0;
    int res = 0;
    bool flag = 0;
    while (!q.empty())
    {
        cnt++;
        int p = 1;
        int u = 0;
        while (p <= n)
        {
            //cout << q.front() << " ";
            if (p % 3 == 1)
            {
                q.pop();
                u++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            if (p == n && flag == 0)
            {
                res = cnt;
                flag = 1;
            }
            p++;
        }
        //cout << p << endl;
        n -= u;
    }
    cout << cnt << " " << res << endl;
    return 0;
}