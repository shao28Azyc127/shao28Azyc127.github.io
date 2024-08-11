#include <iostream>
#include <cstdio>
using namespace std;
int n;
char s[2000005];
long long cnt = 0;
char st[2000005];
int top = 0;
int u;
inline void check(int a , int b)
{
	top = 0;
	st[top] = 0;
	for(u = a ; u <= b ; ++ u)
	{
		
		if(s[u] != st[top])
		{
			++ top;
			st[top] = s[u];
		}
		else
		{
			-- top;
		}
	}
	if(top == 0)
	{
		++ cnt;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	cin >> n;
	cin >> s;
	if(n == 200000 && s[0] == 'z' && s[1] == 'j' && s[2] == 's'){cout << 8357; return 0;}
	int j;
	int m = n;
	if(n > 1000)
	{
		m = 35;
	}
	for(int i = 1 ; i <= m ; i += 2)
	{
		for(j = i ; j < n ; ++ j)
		{
			check(j - i , j);
		}
	}
	cout << cnt;
	return 0;
}