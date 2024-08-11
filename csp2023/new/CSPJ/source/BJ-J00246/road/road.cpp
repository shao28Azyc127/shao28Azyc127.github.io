#include<iostream>
#include<cmath>
using namespace std;
int dis[100005], w[100005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin>>n>>d;
	for(int i = 1; i < n; i++) cin>>dis[i];
	for(int i = 1; i <= n; i++) cin>>w[i];
	int mnxxx=0x3f3f3f3;
	for(int i = 1; i <= n; i++) mnxxx = min(mnxxx, w[i]);
	int mn = w[1];
	double dx=0;
	int ans=0, cnt=0;
	n++;
	w[n+1] = 0;
	for(int i = 2; i <= n; i++)
	{
		cnt += dis[i-1];
		if(w[i] >= mn) continue;
		int qwq = ceil((cnt*1.0-dx) / (d*1.0));
		ans += qwq * mn;
		dx = d*qwq - (cnt*1.0-dx);
		cnt=0;
		mn = w[i];
	}
	cout<<ans;
}
