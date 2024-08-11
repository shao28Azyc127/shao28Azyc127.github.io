
//                               вувубъ your SB
//-----------------------------------------------------------------------------
//
//.......................................................
//I cant do it.....

#include <bits/stdc++.h>
using namespace std;

int f[100005];

struct Node
{
	int a, v;
}t[100005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	t[1].a = 0;
	for(int i = 2; i <= n; i++)
	{
		cin >> t[i].a;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> t[i].v;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += t[i].a;
	}
	
	cout << ans / d * t[1].v;
	return 0;
}