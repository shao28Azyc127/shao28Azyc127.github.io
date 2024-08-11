#include<bits/stdc++.h>
using namespace std;
int n, d, v[100005], a[100005], p = 100001;
long long sum = 0, s[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;++i)
    {
    	cin >> v[i];
    	s[i] = s[i - 1] + v[i];
    }
    for(int i = 1;i <= n;++i)
    {
    	cin >> a[i];
    }
    sum = a[1] * (s[n - 1] / d);
    if(s[n - 1] / d * d < s[n - 1])
    {
    	sum += a[1];
    }
    p = a[1];
    for(int i = 2;i < n;++i)
    {
//    	cout << sum << " ";
    	if(a[i] < p)
    	{
    	    sum -= (s[n - 1] - s[i - 1]) / d * p;
    	    sum += (s[n - 1] - s[i - 1]) / d * a[i];
    	    p = a[i];
    	}
//    	cout << (s[n - 1] - s[i - 1]) / d << endl;
    }
    cout << sum;
    return 0;
}