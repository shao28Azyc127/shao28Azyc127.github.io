#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define ll long long

const int N = 1e5+5;
int v[N], a[N], s[N];
int box[N];
int n, d;
ll sum = 0, ans = 1e8;

ll minL(ll a, ll b)
{
    return (a < b ? a : b);
}

void dfs(int m, double fuelDis)
{
    //printf("dfs %d\n", m);
	if (m+1 == n)
    {
        sum = 0;
        for (int i = 1; i <= n; i ++)
        {
            sum += box[i] * a[i];
            //printf("box[%d] * a[%d] = %d\n", i, i, box[i] * a[i]);
            //printf("sum = %lld\n", sum);
        }
        ans = minL(sum, ans);
        //printf("ans update to %lld\n", ans);

        return ;
    }

    for (int i = m+1; i < n; i ++)
    {
        box[i] = ceil(1.0*(s[i+1]-s[m+1]-fuelDis) / d);
        int t = fuelDis;
        if (box[i] < 0)
        {
            //printf("in if\n");
            box[i] = 0;
            fuelDis -= (s[i+1]-s[m+1]);
            //printf("box[%d] = %d, fuelDis = %f\n", i, box[i], fuelDis);
        }
        else
        {
            //printf("in else\n");
            fuelDis = fuelDis + box[i]*d - (s[i+1]-s[m+1]);
            //printf("box[%d] = %d, s[%d]-s[%d] = %d, fuelDis = %f\n", i, box[i], i+1, m+1, s[i+1]-s[m+1], fuelDis);
        }

        if (fuelDis < 0) continue;

        dfs(i, fuelDis);
        box[i] = 0;
        box[i-1] += ceil(v[i]/d - t);
        if (box[i-1] < 0)
        {
			box[i-1] = 0;
		}
        //printf("box[%d] = %d\n", i-1, box[i-1]);
        fuelDis = t + box[i-1]*d - v[i];
    }

    return ;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d", &n, &d);

    for (int i = 1; i < n; i ++)
    {
        scanf("%d", &v[i]);
        s[i+1] = s[i] + v[i];
        //printf("s[%d] = %d\n", i+1, s[i+1]);
    }

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
    }

    if (n <= 1000)
    {
        dfs(0, 0);
    }
    else
    {
        ll sum2 = 0;
        /*for (int i = 1; i <= n; i ++)
        {
            allDis += v[i];
        }*/
        sum2 = ceil(1.0*s[n]/d) * a[1];

/*        for (int i = 1; i <= n; i ++)
        {
            bool hadFind = false;
            for (int j = 1; j <= n; j ++)
            {
                if (a[j] < a[i])
                {
                    sum += (s[j]-s[i-1])/d * a[i];
                    i = j-1;
                    hadFind = true;
                    break;
                }
            }
            if (!hadFind)
            {
                sum += (s[n-1]-s[i-1])/d * a[i];
                break;
            }
        }*/

        ans = sum2;
    }

    printf("%lld", ans);

    return 0;
}
