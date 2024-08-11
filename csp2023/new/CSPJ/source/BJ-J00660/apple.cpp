#include <iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int ans=-1;
	while (n!=0)
	{
		if(n%3==1&&ans==-1)
		{
			ans=cnt+1;
		}
		if(n%3==0)
		{
			n-=n/3;
		}
		else
		{
			n-=(n/3)+1;
		}
		cnt++;
	}
	cout<<cnt<<" "<<ans<<endl;
}
