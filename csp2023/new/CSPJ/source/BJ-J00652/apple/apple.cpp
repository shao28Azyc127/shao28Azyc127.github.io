#include <iostream>
#include <cstdio>
using namespace std;
long long n,len;
long long a[1000005];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int t1=n;
	int a1=0;
	int a2=0;
	while(t1)
	{
		int tmp=t1/3;
		if(t1%3!=0) tmp++;
		if(t1-tmp<=0) break;
		t1-=tmp;
		a1++;
	}
	a1++;
	if((n-1)%3==0) a2=1;
	else
	{
		t1=n;
		while(t1)
		{
			int tmp=t1/3;
			if(t1%3!=0) tmp++;
			if(t1-tmp<=0) break;
			t1-=tmp;
			a2++;
			if((t1-1)%3==0)
			{
				a2++;
				break;
			}
		}
	}
	cout<<a1<<" "<<a2<<endl;
	return 0;
}
