#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[15][15], s[15];
int main()
{
	freopen("lock.in", "r". stdin);
	freopen("lock.out", "w". stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			cin >> a[i][j];
			s[j] = a[1][j];
		}
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			if(s[j] != a[i][j])
			{
				s[j] = -1;
			}
		} 
	}
	ll cnt = 0;
	bool fl = 0;
	for(int i = 1; i <= 5; i++)
	{
		if(s[i] == -1)
		{
			cnt++;
		}
		if(s[i + 1] == -1)
		{
			fl = 1;
		}
	}
	if(cnt >= 3)
	{
		cout << "0" << endl;
	}
	if(cnt == 2 && fl)
	{
		cout << "4" << endl;
	}
	if(cnt == 2 && !fl)
	{
		cout << "2" << endl;
	}
	if(cnt == 1)
	{
		cout << "10" << endl;
	}
	if(!cnt)
	{
		cout << "81" << endl;
	}
	return 0;
}
