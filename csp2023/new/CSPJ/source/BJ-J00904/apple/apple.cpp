#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 5;
ll n;
ll a[maxn];
ll cnt = 1;
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	a[cnt] = 1;
	while(a[cnt] <= n)
	{
		cnt ++;
		a[cnt] = (a[cnt - 1] * 3 + 1) / 2;
	}
	while(a[cnt] > n)
	{
		cnt --;
	}
	cout << cnt << " ";
	cnt = 1;
	while(n % 3 != 1)
	{
		ll t = n * 2;
		ll p = t / 3;
		n = p;
		cnt ++;
	}
	cout << cnt;
	return 0;
}
