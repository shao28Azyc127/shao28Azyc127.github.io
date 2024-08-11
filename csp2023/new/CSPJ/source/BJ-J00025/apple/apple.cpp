#include<iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,a=0,f,k=0;
	cin>>n;
	while(n>0)
	{
		if(n%3==1&&a==0)
		{
			f=k+1;
			a=1;
		}
		n-=n/3+(n%3>0);
		k++;
	}
	cout<<k<<" "<<f;
	return 0;
}
