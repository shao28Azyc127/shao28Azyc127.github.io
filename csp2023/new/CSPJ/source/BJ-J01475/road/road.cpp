#include <bits/stdc++.h>
using namespace std;
int n,d,v[100010],a[100010],jinwei[100010];
long long sumlu;
int now = 1,nxt,luc;
long long ans;
bool A = 1;
int findlow(int price,int id)
{
    for (int i = id;i < n;i++)
    {
        if (a[i] < price)
        {
            return i;
        }
    }
    return n;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for (int i = 1;i < n;i++)
    {
        scanf("%d",&v[i]);
        sumlu += v[i];
        if ((v[i] - jinwei[i]) % d)
        {
            jinwei[i+1] = d - (v[i] - jinwei[i]) % d;
            v[i] = (v[i] - jinwei[i]) / d + 1;
        }
        else
        {
            v[i] = (v[i] - jinwei[i]) / d;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if (i - 1)
        {
            if (a[1] >= a[i])
            {
                A = 0;
            }
        }
    }
    if (A)
    {
        long long sum = 0,you = 0;
        while (sum < sumlu)
        {
            sum += d;
            you++;
        }
        cout<<you * a[1];
        return 0;
    }
    while (now != n)
    {
        nxt = findlow(a[now],now);
        luc = 0;
        for (int i = now;i < nxt;i++)
        {
            luc += v[i];
        }
        ans += luc * a[now];
        now = nxt;
    }
    cout<<ans;
}