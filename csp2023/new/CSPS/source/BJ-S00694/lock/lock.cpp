#include<bits/stdc++.h>
using namespace std;

int n, s[10][5], cnt, ans;
int a[5] = {10000, 1000, 100, 10, 1};

bool check(int x, int y)
{
	int tmp = 0;
	for(int i = 0; i < 5; i++) if(s[y][i] != x / a[i] % 10) tmp++;
	if(tmp == 1) return 1;
	if(tmp != 2) return 0;
	for(int i = 0; i < 4; i++)
	{
		int t1 = (s[y][i] - (x / a[i] % 10) + 10) % 10;
		int t2 = (s[y][i + 1] - (x / a[i + 1] % 10) + 10) % 10;
		if(!t1 || !t2 || t1 != t2) continue;
		tmp = 1;
	}
	if(tmp == 2) return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 5; j++)
			cin >> s[i][j];
	for(int k = 0; k < 100000; k++)
	{
		ans = 1;
		for(int i = 0; i < n; i++)
			ans &= check(k, i);
		cnt += ans;
	}
	cout << cnt;
	
	return 0;
}