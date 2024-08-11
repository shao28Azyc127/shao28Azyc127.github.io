#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int v[100005], a[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    int sum = 0;
    int miner = 1000000000;
    for(int i = 1;i < n;i ++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        scanf("%d", &a[i]);
        miner = min(miner, a[i]);
    }
    // A
    if(miner == a[1])
    {
        int cc = sum / d + (bool)(sum % d);
        printf("%d\n", a[1] * cc);
        return 0;
    }
    return 0;
}
