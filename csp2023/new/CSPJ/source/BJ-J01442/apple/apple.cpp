//By Pr_159
//100 pts
#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 5;
int n, ans, cnt, tot;
bool a[N];
int main()
{
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		if(!a[i])
		{
			tot++;
			int flag = 0;
			a[i] = 1;
			if(i == n && !ans) ans = tot;
			cnt++;
			for(int j = i; j <= n; j++)
			{
				if(!a[j])
				{
					flag = (flag + 1) % 3;
					if(flag == 0)
					{
						if(j == n && !ans) ans = tot;
						a[j] = 1;
						//printf("a[%d]=%d ", j, a[j]);
						cnt++;
					}
				}
			}
			if(cnt == n) break;
		}
		//cout << endl;
		//for(int j = 1; j <= n; j++) cout << a[j] << ' ';
		//cout << endl;
	}
	cout << tot << ' ' << ans << endl;
	return 0;
}	
