#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 50;

int a[N][50];

LL ans = 0;
LL b[50];

int n;

bool getres(int xx,int yy,int ii,int jj)
{
	int yyxx = yy - xx;
	if(yyxx < 0)
		yyxx += 10;
	int jjii = jj - ii;
	if(jjii < 0)
		jjii += 10;
	return yyxx == jjii;
	
}

bool check()
{
	for(int i = 1;i <= n;i++)
	{
		int cntd = 0;
		int idx1 = 7,idx2 =17 ;
		for(int j = 1;j <= 5;j++)
		{
			if(a[i][j] != b[j])
			{
				if(idx1 == 7)
				{
					idx1 = j;
				}
				else
				{
					idx2 = j;
				}
				cntd++;
			}
		}
		if(cntd >= 3)
			return false;
		else if(cntd == 0)
			return false;
		else if(cntd == 2)
		{
			if(!getres(a[i][idx1],b[idx1],a[i][idx2],b[idx2]) || abs(idx2-idx1) != 1)
				return false;
		}
		//~ else if(cntd == 1)
		//pos
	}
	return true;
}

LL cnt;

void dfs(int p)
{
	if(p >= 6)
	{
		//~ if(check())
		//~ {
			//~ for(int j = 1;j <= 5;j++)
			//~ cout << b[j] << " ";
			//~ cout << "  " << check() << "\n";
			//~ cout << "\n";
		//~ }
		ans += check();
		//~ cnt ++;
		return;
	}
	for(int i = 0;i <= 9;i++)
	{
		b[p] = i;
		dfs(p+1);
	}
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 5;j++)
		{
			cin >> a[i][j];
		}
	}
	dfs(1);
	cout << ans << "\n";
	//~ cout << cnt << "\n";
	return 0;
}
