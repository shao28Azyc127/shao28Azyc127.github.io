#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e8 + 5;

int n, cnt, tmp, k;
bool vis[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	
	cin >> n;
	tmp = n;
	while(tmp)
	{
		cnt = tmp / 3;
		if(tmp % 3 != 0) cnt++;
		tmp -= cnt, k++;
	}
	cout << k << " ";
	tmp = n;
	for(k = 1; tmp; k++)
	{
		cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if(!cnt) vis[i] = 1, tmp--;
			if(i == n && !cnt)
			{
				cout << k;
				return 0;
			}
			cnt++;
			if(cnt == 3) cnt = 0;
		}
	}
	
	return 0;
}