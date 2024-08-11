#include <iostream>

using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	
	int n;
	cin>>n;

	int day=0,take=-1;
	while(n>0)
	{
		n--;
		if(n%3==0 && take==-1)
		{
			take=day+1;
		}
		n-=n/3;
		day++;
	}

	cout<<day<<" "<<take<<endl;

	return 0;
}