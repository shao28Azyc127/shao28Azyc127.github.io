#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	cin>>n;
	int ans1=0;
	long long t=n;
	while(t)
	{
		ans1++;
		if(t%3==0) t=t/3*2;
		else t=t-(t+3)/3;
	}
	cout<<ans1<<' ';
	int ans2=1;
	while(n%3!=1)
	{
		ans2++;
		n=(n%3==0?n/3*2:(n+1)/3*2-1);
	}
	cout<<ans2;
	return 0;
}
