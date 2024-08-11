#include <iostream>
#include <cstdio>
using namespace std;

int v[100005],a[100005];
int ceil(double x)
{
    if (x > int(x)) return int(x) + 1;
    else return int(x);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >>d;
    for (int i = 2; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0,now = 0;
    int i = 1;
    while (i <= n - 1)
    {
        int x = i + 1,sum = 0;
        while (x <= n)
        {
            sum += v[x];
            if (a[i] <= a[x]) x++;
            else break;
        }
        if (now < sum)
        {
            ans += ceil((sum - now) *1.0 / d) * a[i];
            now += ceil((sum - now) *1.0 / d) * d;
        }
        i = x;
        now -= sum;
    }
    cout << ans <<endl;
    return 0;
}