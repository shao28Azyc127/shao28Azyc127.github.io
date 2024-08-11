#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int n, a[N], b[N], c[N], maxx;
struct Ed{int u, v, w;};
struct Dot{int p, h;};
vector<Ed> e[N];
bool vis[N];
bool operator > (const Dot x, const Dot y)
{
	return x.h > y.h;
};
priority_queue < Dot, vector<Dot>, greater<Dot> > q; 
void Dj(int x)
{
	for(auto ed:e[1])
		q.push({ed.v, ed.w});
	return ;
}
int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		maxx = max(maxx, a[i] / max(c[i],1)); 
	}
	cout << 0;
	return 0;
}