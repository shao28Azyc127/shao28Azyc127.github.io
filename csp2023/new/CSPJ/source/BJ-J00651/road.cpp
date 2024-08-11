#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
LL v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    LL n,d;
    cin >> n >> d;
    for (int i = 2;i <= n;i++)
    {
    	LL dt;
    	cin >> dt;
    	v[i] = v[i-1] + dt;
    }
    for (int i = 1;i <= n;i++)
    	cin >> a[i];
    a[n] = -1;
    LL dis = 0,ans = 0;
    double oil = 0;
    for (int i = 1;i <= n;i++)
    {
    	for (int j = i + 1;j <= n;j++)
            if (a[j] < a[i])
            {
            	double sum = 1.0 * (v[j] - v[i]) / d,t = sum;
                sum -= oil;
                sum = ceil(sum);
                ans += int(sum) * a[i];
                oil += sum;
                oil -= t;
                i = j - 1;
                break;
            }
    }
    cout << ans << endl;
	return 0;
}