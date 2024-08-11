#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int c, t, n, m, x, y, s, b[N];
bool a[N];
char v;
//string str;

void c34()
{
	for(int i = 0; i < t; i++)
	{
		cin >> n >> m;
		s = 0;
		for(int j = 0; j < m; j++)
		{
			//scanf("%c%d\n", &v, &x);
			cin >> v >> x;
			if(v == 'U')
			{
				a[x] = 1;
			}
			else
			{
				a[x] = 0;
			}
		}
		for(int j = 0; j < n; j++)
		{
			if(a[j])
			{
				a[j] = 0;
				s++;
			}
		}
		cout << s << endl;
	}
	return ;
}

int f56(int x)
{
	if(b[x] == 0)
	{
		return 0;
	}
	if(b[x] == N)
	{
		return N;
	}
	return b[x] = f56(b[x]);
}

void c56()
{
	for(int i = 0; i < t; i++)
	{
		//cout << 5;
		cin >> n >> m;
		//scanf("%d%d", &n, &m);
		s = 0;
		//cout << 3;
		for(int j = 0; j < m; j++)
		{
			//scanf("\n%c", &v);
			//cin >> v;
			v = getchar();
			v = getchar();
			//getline(cin, str);
			//sscanf(str.c_str(), "%c%d%d", &v, &x, &y);
			if(v == '+')
			{
				//cout << 2;
				scanf("%d%d", &x, &y);
				//cin >> x >> y;
				b[x] = y;
			}
			else
			{
				scanf("%d", &x);
				b[x] = N;
			}
			//cout << v << x;
		}
		for(int j = 1; j <= n; j++)
		{
			b[j] = f56(j);
		}
		for(int j = 1; j <= n; j++)
		{
			if(b[j] == N)
			{
				//cout << j;
				s++;
			}
			b[j] = 0;
		}
		cout << s << endl;
	}
	return ;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> t;
	//printf("1");
	//scanf("%d%d", &c, &t);
	if(c == 3 || c == 4)
	{
		c34();
	}
	if(c == 5 || c == 6)
	{
		//cout << 4;
		c56();
	}
	
	return 0;
}