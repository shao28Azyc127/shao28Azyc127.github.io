#include<iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ans=0,ans1;
	bool flag=true;
	cin>>n;
	while(n>0)
	{
		ans++;
		if(n%3==1&&flag)
		{
			ans1=ans;
			flag=false;
		}
		if(n/3==0)
			n--;
		else
		{
			if(n%3==0)
				n-=n/3;
			else
				n-=n/3+1;
		}
	}
	cout<<ans<<" "<<ans1;
	return 0;
}
