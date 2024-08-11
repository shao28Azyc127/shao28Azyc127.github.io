#include<bits/stdc++.h>
using namespace std;

int n;

string s;

bool ccheck(int l, int r)
{
	//cout << l << " " << r << endl << endl;
	string st = "";
	for(int i = l; i <= r; i++)
	{
		st += s[i];
	}
	//cout << st << endl;
	int len = r - l + 1;
	bool t = 1;
	while(len)
	{
		t = 1;
		for(int i = 0; i < len; i++)
		{
			if(st[i] == st[i + 1])
			{
				for(int j = i; j < len; j++)
				{
					st[j] = st[j + 2];
				}
				t = 0;
				len -= 2;
			}
			//cout << st << endl;
		}
		if(t) return 0;
	}
	return 1;
}

int main()
{
	freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
	cin >> n;
	cin >> s;
	s = " " + s;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			ans += ccheck(i, j);
			//if(ccheck(i, j)) cout << i << " " << j << endl;
		}
	}
	cout << ans;
	return 0;
}
