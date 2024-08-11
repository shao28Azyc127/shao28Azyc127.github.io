#include <iostream>
#include <queue>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin >> n;
	int sum = 3,cur = 0;
	if (n % 3 == 1) n--;
	int ans = 0,tmp = n - (n + 1) / 3;
	while (tmp > 0)
	{
		cur++;
		for (int i = sum - 1;i <= n;i += sum + cur + sum + cur + cur)
		{
			if (i <= n) tmp--;
			if (i + sum + cur <= n) tmp--;
			if (i == n || i + sum + 1 == n) ans = cur;
		}
		sum += cur;
	}
	if ((n + 1) % 3 == 1) cout << cur + 1 << " " << 1 << endl;
	else cout << cur + 1 << " " << ans + 1 << endl;
	return 0;
}
