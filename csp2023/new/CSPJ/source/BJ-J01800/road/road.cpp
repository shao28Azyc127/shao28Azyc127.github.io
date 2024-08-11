#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,d;
ll sum,tot,ans;
const int N = 1e5+9;
int v[N],a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n-1;i++)
	{
		cin >> v[i];
		sum += v[i];
		v[i] = (sum%d!=0)+sum/d;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(i>1) a[i] = min(a[i-1],a[i]);
	}

	for(int i=1;i<=n-1;i++)
	{
		//cout << v[i] << " " << a[i] << endl;
		ans += (v[i]-tot) * a[i];
		tot = v[i];
	}
	cout << ans << endl;
}