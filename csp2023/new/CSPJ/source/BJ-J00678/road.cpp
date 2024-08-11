#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int guo[N], buguo[N], ganghao[N], price[N], dis[N];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	
	//shuru
	bool A = 1, B = 0;
	int n, d;
	scanf("%d%d", &n, &d);
	for(int i = 1; i < n; i++)
	{
		scanf("%d", &dis[i]);
		if(dis[i] % d != 0)
		{
			A = 0;
			buguo[i] = dis[i] / d;
			guo[i] = buguo[i] + 1;
		}
		else ganghao[i] = dis[i] / d;
	}
	int tmp;
	scanf("%d", &tmp);
	price[1] = tmp;
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &price[i]);
		if(price[i] < tmp)B = 1;
	}
	
	
	//chengxu
	int tkp = 100005, linshidis = 0;
	long long sumdis = 0;
	
	//pan1
	if(A == 1){
		for(int i = 1; i < n; i++)
		{
			if(price[i] < tkp)
			{
				sumdis += tkp * linshidis;
				linshidis = ganghao[i];
				tkp = price[i];
			}
			else linshidis += ganghao[i];
		}
		sumdis += tkp * linshidis;
		cout << sumdis;
	}
	
	
	//pan2
	if(B == 0)
	{
		for(int i = 1; i < n; i++)sumdis += dis[i];
		long long ans;
		ans = sumdis / d;
		if(sumdis %d != 0)ans++;
		ans *= price[1];
		cout << ans;
	}
	
	
	return 0;
}
