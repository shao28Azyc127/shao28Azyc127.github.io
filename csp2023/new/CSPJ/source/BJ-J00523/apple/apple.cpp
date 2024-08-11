#include<bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
bool a[N];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,x;
	cin >> n;
	x = n;
	int sum = 0,cnt = 0,ans = 0;
	while(n > 0)
	{
		cnt++;
		ans = 0;
		for(int i = 1;i <= x;i++)
		{
			if(a[i] == 0)
				ans++;
			if(ans == 1 && !a[i])
			{
				n--;
				a[i] = 1;
				if(i == x)
					sum = cnt;
			}
			if(ans == 3)
				ans = 0;
		}
	}
	cout << cnt << " " << sum;
	return 0;
}
