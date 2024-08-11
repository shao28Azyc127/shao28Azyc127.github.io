#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long n;
	cin >> n;
	long nn=n;
	long nnn=nn;
	int now=1;
	int ans=0,ans2=0,ci=0;
	while(nn>0)
	{
		now=1;
		ans++;
		while(now<=nn)
		{
			nnn--;
			if(now==nn&&ci==0)
			{
				ans2=ans;
				ci++;
			}
			now+=3;
		}
		now=1;
		nn=nnn;
	}
	cout << ans << " " << ans2;
	return 0;
}
