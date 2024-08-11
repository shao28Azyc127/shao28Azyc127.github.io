#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

string s[3010];
string sgr[3010], sle[3010];

bool lessc(char x, char y)
{
	return x>y;
}

int main()
{
	ios::sync_with_stdio(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	for (int i=1;i<=n;i++)
	{
		sgr[i]=sle[i]=s[i];
		sort(sgr[i].begin(), sgr[i].end());
		sort(sle[i].begin(), sle[i].end(), lessc);
	}
	for (int i=1;i<=n;i++)
	{
		bool flag=1;
		for (int j=1;j<=n;j++)
		{
			if (i==j)
				continue;
			if (sgr[i]>=sle[j])
			{
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}