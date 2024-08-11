#include<bits/stdc++.h>
using namespace std;
const int N = 10;
unordered_map<int,bool> mp[10];
int n,ans;
int a[N][N],b[N],p[6];
int get(int x,int d)
{
	--d;
	while(d) 
	{
		x/=10;
		--d;
	}
	return x%10;
}
void check(int x)
{
	int num = 0;
	for(int i = 1;i <= 5;++i) num = num*10 + a[x][i];
	for(int i = 1;i <= 5;++i) 
	{
		int d = get(num,i)*p[i];
		for(int j = 0;j <= 9;++j) mp[x][num-d+p[i]*j] = true;
	}
	for(int i = 1;i <= 4;++i)
	{
		int d1 = get(num,i),d2 = get(num,i+1);
		for(int j = 1;j <= 9;++j)
		{
			mp[x][num-d1*p[i]-d2*p[i+1]+((d1+j)%10)*p[i]+((d2+j)%10)*p[i+1]] = true;
			//mp[x][num-d1*p[i]-d2*p[i+1]+((d1+j)%10)*p[i]+(((d2-j)%10+10)%10)*p[i+1]] = true;
			//mp[x][num-d1*p[i]-d2*p[i+1]+(((d1-j)%10+10)%10)*p[i]+((d2+j)%10)*p[i+1]] = true;
			//mp[x][num-d1*p[i]-d2*p2[i+1]+((d1+j)%10)*p[i]+((d2+j)%10)*p[i+1]] = true;
		}
	}
	mp[x][num] = false;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	p[1] = 1;
	for(int i = 2;i <= 5;++i) p[i] = p[i-1]*10;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= 5;++j) cin >> a[i][j];
	for(int i = 1;i <= n;++i) check(i);
	for(int i = 0;i < 100000;++i)
	{
		bool flag = true;
		for(int j = 1;j <= n;++j)
			if(!mp[j][i]) flag = false;
		if(flag) ++ans;
	}
	cout << ans << endl;
	return 0;
}
