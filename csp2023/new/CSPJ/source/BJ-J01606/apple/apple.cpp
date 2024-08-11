#include <iostream>

using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,s=0,aim;
	bool fl=false;
	cin>>n;
	while(n)
	{
		if(n%3==0)
		{
			n-=(n/3);
			s++;
		}
		else if(n%3==1)
		{
			n-=(n/3+1);
			s++;
			if(!fl)
			{
				fl=true;
				aim=s;
			}
		}
		else
		{
			n-=(n/3+1);
			s++;
		}
	}
	cout<<s<<" "<<aim;
}