#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int ans;
struct opt
{
	int tp, a, b;
}op[N];
int ct;
void work(int *x)
{
	for(int i = 1; i <= ct; i ++)
	{
		if(op[i].tp == 0) x[op[i].a] = x[op[i].b];
		else 
		{	if(op[i].tp == 1)
			{
				if(x[op[i].b] == 1) x[op[i].a] = 1;
				if(x[op[i].b] == 2) x[op[i].a] = 3;
				if(x[op[i].b] == 3) x[op[i].a] = 2;
			}else x[op[i].b] = op[i].a;
		}
	}
}
int d[N], k[N];
int now;
bool is()
{
	for(int i = 1; i <= n; i ++) k[i] = d[i];
	work(k);
	for(int i = 1; i <= n; i ++) if(k[i] != d[i]) return 0;
	return 1;
}
void dfs(int u)
{
//	++ cnt;
//	for(int i = 1; i <= n; i ++) cout << d[i] << " ";
//	cout << endl;
//	if(cnt > 15) exit(0);

	if(u > n)
	{
	int iss = 0;
	       	if(is())
		{
			ans = min(ans, now);
			cout << "Yes: ";
			for(int i = 1; i <= n; i ++) cout << d[i] << " ";
			cout << endl;
		}
       		return;
	}
	for(int i = 1; i <= 3; i ++)
	{
		d[u] = i;
		if(i == 1) now ++;
		dfs(u + 1);
		if(i == 1) now --;
	}
}
int c, t;
int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> t;
	while(t --)
	{
		now = ct = 0;
		ans = 0x3f3f3f3f;
		memset(d, 0, sizeof(d));
		cin >> n >> m;
		if(n <= 10 && m <= 10)
		{
			for(int i = 1; i <= m; i ++)
			{
				char v;
				cin >> v;
				if(v == 'U' || v == 'T' || v == 'F') 
				{
					int k;
					cin >> k;
					op[++ ct] = (opt){2, ((v == 'U') ? 1 : ((v == 'F') ? 2 : 3)), k};
				}
				if(v == '+')
				{
					int a, b;
					cin >> a >> b;
					op[++ ct] = (opt){0, a, b};
				}
				if(v == '-')
				{
					int a, b;
					cin >> a >> b;
					op[++ ct] = (opt){1, a, b};
				}
			}
			dfs(1);
			cout << ans << endl;
		}
		else
		{

			if(c== 3 || c == 4)
			{
	
				for(int i = 1; i <= m; i ++)
				{
					char v;
					cin >> v;
					if(v == 'U')
					{
						int k;
						cin >> k;
						d[k] = 1;
						ans ++;
					}
				}
				cout << ans << endl;
			}
			if(c == 5 || c == 6)
			{
				for(int i = 1; i <= m; i ++)
                                {
                                        char v;
                                        cin >> v;
                                        if(v == 'U')
                                        {
                                                int k;
                                                cin >> k;
                                                d[k] = 1;
                                                ans ++;
                                        }
					if(v == '+')
					{
						int k, kt;
						cin >> k >> kt;
						d[k] = d[kt];
						if(d[kt]) ans ++;
					}
                                }
				cout << ans << endl;
			}
			if(c == 7 || c == 8)
			{
				cout << m << endl;
				

			}
		}		
	
	}

	return 0;
}