#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n, d;
int v[100010];
int a[100010];
int vv[100010];
double petrol = 0;
long long moneyy = 0;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    for(int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    vv[1] = v[1];
    for(int i = 2; i <= n - 1; i++)
    {
        vv[i] = vv[i - 1] + v[i];
    }

    for(int i = 1; i < n; i++)
    {
        int minn = 200005;
        int ii = -1;
        bool f = false;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                minn = a[j];
                ii = j;
                f = true;
                break;
            }
        }
        if(!f)
        {
            ii = n;
            double t1 = vv[ii - 1] - vv[i - 1];
            int t2 = ceil((t1 - petrol) / (double)d);
            petrol += t2 * d - t1;
            moneyy += t2 * a[i];
            i = ii - 1;
            break;
        }
        if(minn != 200005)
        {
            double t1 = vv[ii - 1] - vv[i - 1];
            int t2 = ceil((t1 - petrol) / (double)d);
            petrol += t2 * d - t1;
            moneyy += t2 * a[i];
            i = ii - 1;
        }
    }
    cout<<moneyy<<endl;
    return 0;
}
