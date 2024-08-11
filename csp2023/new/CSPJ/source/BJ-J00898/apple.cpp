#include <bits/stdc++.h>
using namespace std;
int n,ans1,ans2,flag;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>0)
	{
		int i=1;
		int cnt=1;
		ans1++;
		while(i+3<=n)
		{
			cnt++;
			i+=3;
		}
		if(i==n&&flag==0) 
		{
			flag=1;
			ans2=ans1;
		}
		n-=cnt;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
