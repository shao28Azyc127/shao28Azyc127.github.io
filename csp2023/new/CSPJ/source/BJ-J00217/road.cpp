#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int v[100005] = {0,0},a[100005];
bool flag[100005] = {1,1};
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,cnt = 0,lon = 0,mo;
    double vy;
    cin >> n >> d;
    for(int i = 1;i <= n - 1;i++) cin >> v[i];
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int j = 2;j <= n - 1;j++)
        {
            if (a[j] >= a[1]) cnt++;
            else break;
        }
    for (int j = 1;j <= cnt + 1;j++)
        {
            lon += v[j];
            flag[j] = 1;
        }
    mo = ceil((1.0 * lon)/ d) * a[1];
    vy = ceil((1.0 * lon)/ d);
    for(int i = 2;i <= n;i++)
    {
        vy -= 1.0 * v[i - 1] / d;
        if(flag[i]) continue;
        int cnt = 0,lon = 0;
        for(int j = i + 1;j <= n - 1;j++)
        {
            if (a[j] >= a[i]) cnt++;
            else break;
        }
        for (int j = i;j <= i + cnt;j++)
        {
            lon += v[j];
            flag[j] = 1;
        }
        if (lon != 0)
        {
            mo += ceil((1.0 * lon - vy * d)/ d) * a[i];
            vy += ceil((1.0 * lon - vy * d)/ d);
        }
        else
        {
            mo += ceil((1.0 * v[i] - vy * d) / d) * a[i];
            vy += ceil(1.0 * v[i] - vy * d) / d;
        }
    }
    cout << mo;
    return 0;