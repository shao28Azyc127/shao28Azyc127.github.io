#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int n, x[10], y, p[10]={1}, ans;
struct L{int cnt, lk[10];} a[10];
int dt(int x, int k)
{
	if(k==1 && x==9)
		return -9;
	if(k==-1 && x==0)
		return 9;
	return k;
}
int v[N*10];
bool check(L x, L y)
{	
	int t=0, pt=0;
	for(int i=1; i<=5; ++i)
	{
		if(x.lk[i]!=y.lk[i] && t==0)
		{
			t=x.lk[i]-y.lk[i], pt=i;
			if(t<0) t+=10;
		}
		else if(x.lk[i]!=y.lk[i] && ((x.lk[i]<y.lk[i] ? 10+x.lk[i]-y.lk[i] : x.lk[i]-y.lk[i])!=t || i!=pt+1) )
			return 0;
		//cout << "t: " << t << endl;
	}
	//cout << endl << " x:";
	for(int i=1; i<=5; ++i)
	{
		if(x.lk[i]==10)
			x.lk[i]=0;
		//cout << x.lk[i];
		//cout << "t: " << t << endl;
	}
	//cout << endl << " y:";
	for(int i=1; i<=5; ++i)
	{
		if(y.lk[i]==10)
			y.lk[i]=0;
		//cout << y.lk[i];
		//cout << "t: " << t << endl;
	}
	return 1;
}
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1; i<=5; ++i) p[i]=p[i-1]*10;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=5; ++j)
		{
			cin >> a[i].lk[j];
			//if(a[i].lk[j]==0) a[i].lk[j]=10;
			//cout << a[i].lk[j] << endl;
		}
	}
	for(int i=1; i<=99999; ++i)
	{
		L te;
		int cnt=0;
		for(int j=1; j<=5; ++j)
		{
			te.lk[j] = i/p[5-j]%10;
			//if(te.lk[j]==0) te.lk[j]=10;
		}
		for(int j=1; j<=n; ++j)
		{//cout << 114 << endl;
			if(check(a[j], te))
				cnt++;
		}
		if(cnt==n)
		ans++;
	}
	//cout << "ans: ";
	cout << ans-n << endl;
	return 0;
}