#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n, a[N], c, u, s;
bool b[N][N], f[N];

/*void print(bool d[N][N])
{
	for(int i = 0; i <= 9; i++, cout << endl)
		for(int j = 1; j <= 5; j++)
			cout << d[j][i] << ' ';
	cout << endl;
}*/

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    memset(b, false, sizeof b), memset(f, false, sizeof f);
    while(n--)
    {
		for(int i = 1; i <= 5; i++)
		{
			cin >> a[i];
			b[i][a[i]] = true;
			for(int j = 0; j <= 9; j++)
			{
				if(j == a[i]) continue;
				if(b[i][j])
					if(f[i] == false) f[i] = true, c++;
			}
		}
		if(c > 1)
		{
			int x = 0, y = 0;
			for(int i = 1; i <= 5; i++)
			{
				if(f[i])
				{
					if(x) y = i;
					else x = i;
				}
			}
			u = abs(a[x] - a[y]);
		}
	}
	if(c == 0)
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 0; j <= 9; j++)
				if(b[i][j] == false) s++;
		}
	}
	else if(c == 1)
	{
		for(int i = 1; i <= 5; i++)
		{
			if(c > 0 && f[i] == false) continue;
			for(int j = 0; j <= 9; j++)
				if(b[i][j] == false) s++;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		if(c > 0 && f[i] == false) continue;
		for(int j = 0; j <= 9; j++)
			if(b[i][j] == false && b[i][(j - u < 0 ? 10 + j - u : j - u)] == false) s++;
	}
	//print(b);
	cout << s << endl;

    return 0;
}
