#include <iostream>
#include <queue>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    int v[n + 1];
    for(int i = 0;i < n - 1;i++)
    {
        cin >> v[i];
    }
    int m[n + 1];
    for(int i = 0;i < n;i++)
    {
        cin >> m[i];
    }
    queue <long long> q;
    queue <long long> q1;
    int la = 0;
    q.push(m[la]);
    bool s = 0;
    while(1)
    {
        for(int i = la + 1;i < n - 1;i++)
        {
            if(m[la] > m[i])
            {
                q.push(m[i]);
                long long re = 0;
                for(int j = la;j < i;j++)
                {
                    re += v[j];
                }
                q1.push(re);
                s = 1;
                la = i;
                break;
            }
        }
        if(s == 0)
        {
            break;
        }
        s = 0;
    }
    int re = 0;
    for(int j = la;j < n - 1;j++)
    {
        re += v[j];
    }
    q1.push(re);
    long long money = 0;
    long long lali = 0;
    while(!q.empty())
    {
        int st = q.front();
        q.pop();
        int sy = q1.front();
        q1.pop();
        if(sy > lali)
        {
            int m1 = ((sy - lali) / d);
            int m2 = ((sy - lali) % d);
            if(m2 > 0)
            {
                m1++;
                lali = (d * m1) - (sy - lali);
            }
            money += m1 * st;
        }
    }
    cout << money;
    return 0;
}