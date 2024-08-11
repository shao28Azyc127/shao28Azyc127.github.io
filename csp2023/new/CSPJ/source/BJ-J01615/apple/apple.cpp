#include<iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int o=0,ans,flag=0;
	while(n!=0)
	{
		o++;
		n-=1;
		if(n%3==0 && flag==0)
			ans=o,flag=1;
		n=n-(n/3);
	}
	cout<<o<<" "<<ans<<endl;
	return 0;
}
