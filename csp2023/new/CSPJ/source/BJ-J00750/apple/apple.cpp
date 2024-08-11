#include<bits/stdc++.h>
using namespace std;
long long Up(long long n)
{
	if(n%3!=0)
		return n/3+1;
	else
		return n/3;
}
int main()
{
    freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,cnt=0,c,ans=0;
	cin>>n;
	c=n;
	while(c)
	{
		cnt++;
		if(!ans && (c-1)%3==0)
			ans=cnt;
		c-=Up(c);
	}
	cout<<cnt<<" "<<ans;
    return 0;
}