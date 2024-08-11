#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,f=0,ans1=0,ans2=0;
	cin>>n;
	while(n)
	{
		n--;
		ans1++;
		if((n)%3==0&&f==0)ans2=ans1,f=1;
		n-=n/3;
		
	}
	cout<<ans1<<" "<<ans2;
}
