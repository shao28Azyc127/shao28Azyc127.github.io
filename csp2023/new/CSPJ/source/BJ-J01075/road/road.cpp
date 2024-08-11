#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int money;
    int index;
}sta[100020];
bool cmp(node a,node b)
{
    if (a.money != b.money)
    {
        return a.money < b.money;
    }
    else
    {
        return a.index < b.index;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,s[100020] = {};
    cin >> n >> d;
    for (int i = 1 ; i <= n - 1 ; i++)
    {
        cin >> s[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> sta[i].money;
        sta[i].index = i;
    }
    sort(sta + 1,sta + n + 1,cmp);
    int ans = 0,temp = n;
    for (int i = 1 ; i <= n ; i++)
    {
        int dis = 0;
        if (sta[i].index >= temp) continue;
        else
        {
            for (int j = sta[i].index ; j <= temp - 1 ; j++)
            {
                dis += s[j];
            }
            ans = ans + ceil(dis * 1.0 / d) * sta[i].money;
            temp = sta[i].index;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}