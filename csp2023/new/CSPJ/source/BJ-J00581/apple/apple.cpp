#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i ++)
    {
        q.push(i);
    }
    int i = 0;
    int last = 1;
    while(!q.empty())
    {
        if(q.front() <= last)
        {
            i = 0;
            ans1++;
        }
        i++;
        if(i == 4)i -= 3;
        if(i == 1)
        {
            if(q.front() == n)ans2 = ans1;
            last = q.front();
            q.pop();
            continue;
        }
        last = q.front();
        q.pop();
        q.push(last);
    }
    cout << ans1 << " " << ans2;
    return 0;
}