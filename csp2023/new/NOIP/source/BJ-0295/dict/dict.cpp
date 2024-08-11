#include <iostream>
using namespace std;

const int maxn = 3000;
int n, m, i;

struct zfc
{
	string orgn;
	string minmm,maxmm;
}a[maxn + 5];

int cnt[27];

bool cmp(string a, string b)
{
	for(int i = 0; i < m; i ++)
	{
		if(a[i] > b[i])
		{
			return false;
		}
		if(a[i] < b[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(i = 1; i <= n; i ++)
	{
		a[i].orgn = "";
		a[i].minmm = "";
		a[i].maxmm = "";
		string k;
		cin >> k;
		a[i].orgn = k;
	}
	for(i = 1; i <= n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			int xd = a[i].orgn[j] - 'a' + 1;
			cnt[xd] ++;
		}
		for(int k = 1; k <= 26; k ++)
		{
			while(cnt[k] != 0)
			{
				char t = 'a' + k - 1;
				a[i].minmm.push_back(t);
				cnt[k] --;
			}
		}
	}
	for(i = 1; i <= n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			int xd = a[i].orgn[j] - 'a' + 1;
			cnt[xd] ++;
		}
		for(int k = 26; k >= 1; k --)
		{
			while(cnt[k] != 0)
			{
				char t = 'a' + k - 1;
				a[i].maxmm.push_back(t);
				cnt[k] --;
			}
		}
	}
	for(i = 1; i <= n; i ++)
	{
		bool flag = true;
		for(int j = 1; j <= n; j ++)
		{
			if(i != j)
			{
				string p = a[i].minmm;
				string q = a[j].maxmm;
				bool ans = cmp(p, q);
				if(!ans)
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	return 0;
}
