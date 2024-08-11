#include <bits/stdc++.h>
using namespace std;

const int N = 800;
int n, ans, cnt;
string s;

map <int, int> mem;

bool check(int st, int e)
{
	int l = st, r = e;
	while(l < r)
	{
		if(s[l] != s[r]) return 0;
		l++, r--;
	}
	mem[e] = st;
	return 1;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if((j - i - 1) & 1) continue;
			if(check(i, j))
			{
				//printf("sucessed on i = %d, j = %d\n", i, j);
				ans++;
				int tot = 1;
				for(int k = j - 1; k >= 0; )
				{
					if(mem.find(k) != mem.end())
					{
						tot++;
						k = mem[k] - 1;
					}
					else break;
				}
				ans += tot - 1;
			}
			//else printf("failed on i = %d, j = %d\n", i, j);
		}
	}
	cout << ans << endl;
	return 0;
}
