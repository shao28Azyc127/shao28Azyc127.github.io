#include<bits/stdc++.h>
using namespace std;

const int N = 13;

int n;

struct Status
{
    int a[5];
} sta[N];

int inline dis(int ta, int ts)
{
    int d = ts - ta;
    return d > 0 ? d : d + 10;
}

bool check1(Status& ans, Status& sta)
{
    int diff = 0;
    for(int i = 0; i < 5; i++)
    {
        int ta = ans.a[i];
        int ts = sta.a[i];
        if(ta != ts)
        {
            diff++;
            if(diff == 2)
                return false;
            if(i+1 < 5 && ans.a[i+1] != sta.a[i+1])
            {
                int baq = dis(ta, ts);
                int baq2 = dis(ans.a[i+1], sta.a[i+1]);
                if(baq2 != baq)
                {
                    return false;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    return diff == 1;
}

bool inline check2(Status& ans)
{
    for(int i = 2; i <= n; i++)
    {
        if(!check1(ans, sta[i]))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> sta[i].a[0] >> sta[i].a[1] >> sta[i].a[2] >> sta[i].a[3] >> sta[i].a[4];
    }
    if(n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    Status& ori = sta[1];
    int cnt = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            ori.a[i] = ori.a[i] + j < 10 ? ori.a[i] + j : ori.a[i] + j - 10;
            cnt += check2(ori);
            if(i < 4)
            {
                ori.a[i+1] = ori.a[i+1] + j < 10 ? ori.a[i+1] + j : ori.a[i+1] + j - 10;
                cnt += check2(ori);
                ori.a[i+1] = ori.a[i+1] - j > 0 ? ori.a[i+1] - j : ori.a[i+1] - j + 10;
            }
            ori.a[i] = ori.a[i] - j > 0 ? ori.a[i] - j : ori.a[i] - j + 10;
        }
    }
    cout << cnt << endl;
    return 0;
}