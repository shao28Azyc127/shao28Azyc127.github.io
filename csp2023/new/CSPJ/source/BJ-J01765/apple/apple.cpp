#include <iostream>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,k,d,b=0;
	cin>>n;
	k=n;
	for(int i=1;i<=k;i++)
	{
		n-=1;
		if(n%3==0&&b==0)
		{
			d=i;
			b++;
		}
		if(n==0)
		{
			cout<<i<<" ";
			break;
		}
		n=n/3*2+n%3;
	}
	cout<<d;
	return 0;
}