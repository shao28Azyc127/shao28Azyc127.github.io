#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

queue<int> q;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    //part 1
    int cnt = 1;
    int last = 2;
    if(n <= 2)
    {
        cout << n << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        q.push(i);
    }
    for(int i = 3;i <= n;i++)
    {
        if(i - last == cnt)
        {
            last = i;
            cnt++;
        }
    }
    cout << cnt + 1 << " ";
    // part 2
    cnt = 0;
    while(true)
    {
        cnt++;
        last = 0;
        while(true)
        {
            if(q.front() <= last)break;
            if(q.front() == n)
            {
                cout << cnt << endl;
                return 0;
            }
            last = q.front();
            q.pop();
            if(q.front() <= last)break;
            q.push(q.front());
            last = q.front();
            q.pop();
            if(q.front() <= last)break;
            q.push(q.front());
            last = q.front();
            q.pop();
        }
    }
    return 0;
}
