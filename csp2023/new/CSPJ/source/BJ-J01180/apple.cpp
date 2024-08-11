#include <iostream>
using namespace std;
int s(int x,int y)
{
	if (x%y==0) return x/y;
	else return x/y+1;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n=0,m=0;
	int l=1;
	bool flag=true;
	cin>>n;
	while (n>0)
	{
		m++;
		if (n%3==1&&flag)
		{
			l=m;
			flag=false;
		}
		n-=s(n,3);
	}
	cout<<m<<' '<<l;
	return 0;
}
