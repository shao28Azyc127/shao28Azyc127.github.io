#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int n, ans;
int a[N][6], b[6];
int is1[N], is2[N];
void ch1(int now)
{
	for(int i = 5; i >= 1; i --)
	{
		b[i] = now % 10;
		now /= 10;
	}
	for(int i = 1; i <= n; i ++)
	{
		int sing = 0;
		for(int j = 1; j <= 5; j ++)
		{
			if(a[i][j] == b[j]) continue;
			sing ++;	
		}
		if(sing == 1) is1[i] = 1;

	}
}

void ch2(int now)
{
        for(int i = 5; i >= 1; i --)
        {
                b[i] = now % 10;
                now /= 10;
        }
	for(int i = 1; i <= n; i ++)
	{
		int num = 0;
		for(int j = 1; j <= 5; j ++)
		{
			if(b[j] == a[i][j]) continue;
			num ++;
			if((a[i][j] + b[j + 1]) % 10 != (a[i][j + 1] + b[j]) % 10 || j == 5) break;
			num ++;
			j ++;
		}
		if(num != 2) continue;
		else is2[i] = 1;
	}
}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	int t = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= 5; j ++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= 99999; i ++)
	{
		memset(is1, 0, sizeof(is1));
		memset(is2, 0, sizeof(is2));
		ch1(i);
		ch2(i);
		int add = 1;
		for(int j = 1; j <= n; j ++) if(is1[j] + is2[j] == 0) add = 0;
		ans += add;
	}



	cout << ans << endl;
	return 0;
}