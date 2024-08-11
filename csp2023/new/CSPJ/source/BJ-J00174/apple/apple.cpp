#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
	ll ans1 = 0, ans2 = -1;
	ll k = n;
	while(k >= 4)
	{
		ans1 ++;
		k -= k / 4 + 1;
		if(k % 3 == 1)
		{
			ans2 = ans1;
		}
	}
	ans1 = ans1 + k;
	if(ans2 == -1)
	{
		ans2 = ans1;
	}
	cout << ans1 << " " << ans2 << endl;
    return 0;
}
