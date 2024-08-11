#include<bits/stdc++.h>
using namespace std;
bool f[1000010];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin >> n;
	bool fff = 1;
	int ans = 0,ret = 0;
	for(int i = 1;i <= n;i++)
		f[i] = 1;
	for(int i = 1;i <= n;i++)
	{
		int now = 2,cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			if(f[j] && now == 2) 
			{
				f[j] = 0;
				//cout << j << " ";
				now = 0;
			}
			else if(f[j]) now++;
			else cnt++;
		}
		if(cnt == n) 
		{
			ret = i-1;
			break;
		}
		//cout << endl;
		if(f[n] == 0 && fff) ans = i,fff = 0;
	}
	cout << ret << " " << ans;
	return 0;
}
