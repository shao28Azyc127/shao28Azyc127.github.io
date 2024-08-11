#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;

	int ans = 0;
	bool f;
	int ans2 = 0;
	cin >> n;
	int t = n;
	while(t != 0)
	{
		if(t % 3 == 1 && f == false) 
		{
			f = true;
		}

		ans++;
		t -= (t / 3) + (t % 3 != 0);
		if(f == false)ans2++;
	}
	cout << ans << " " << ans2+1;
	return 0;
}
