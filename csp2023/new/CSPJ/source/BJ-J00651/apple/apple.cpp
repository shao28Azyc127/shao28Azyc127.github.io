#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    LL n;
    cin >> n;
    LL ans1 = 0,ans2 = 0,sum = n;
    bool flag = false;
    while (sum > 0)
    {
    	ans1++;
    	if (!flag) ans2++;
    	if ((sum-1) % 3 == 0) flag = true;
    	sum -= LL(ceil(1.0 * sum / 3));
    }
    cout << ans1 << " " << ans2 << endl;
	return 0;
}