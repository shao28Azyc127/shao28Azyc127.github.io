#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	long long cnt=0,day=0;
	while(n>0)
	{
		cnt++;
		if(n%3==1&&day==0)
		{
			day=cnt;
		}
		if(n%3==0)
		{
			n=n-n/3;
		}
		else
		{
			n=n-n/3-1;
		}
	}
	if(day==0)
	{
		day=cnt;
	}
	cout<<cnt<<" "<<day<<endl;
	return 0;
}