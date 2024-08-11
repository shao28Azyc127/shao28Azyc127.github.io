#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int v[N], a[N];//ajiage vjuli
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n;
	long long d;
	scanf("%d%lld", &n, &d);
	long long sumv = 0;
	for(int i = 1; i <= n - 1; i++)
	{
		scanf("%d", &v[i]);
		sumv += v[i];
	}
	//int minn = INT_MAX;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		//if(a[i] < minn) minn = a[i];
	}
	int mn = a[1];
	int last = 0;
	long long sum = 0;
	long long ans = 0;

	long long sum2 = 0;
	int lastpos = 1;
	for(int i = 2; i <= n; i++)
	{
		
		//cout << a[3] << ' ' << mn << endl;
		if(a[i - 1] < mn)
		{
			lastpos = i;
			//cout << mn << "fefefe" << endl;
			sum -= last;
			int num = ceil(sum * 1.0 / d);
			sum2 += sum + last;
			
			ans += num * mn;
			last = num * d - sum;
			sum = 0;
			mn = a[i - 1];
		}
		sum += v[i - 1];
	}
	//cout << lastpos << endl;
	sum = 0;
	for(int i = lastpos - 1; i <= n; i++)
	{
		sum += v[i];
		//cout << v[i] << 'p' << endl;
	}
	sum -= last;
	//cout << sum << ' ' << mn << endl;
	int num = ceil(sum * 1.0 / d);

	ans += num * mn;
	cout << ans;
}