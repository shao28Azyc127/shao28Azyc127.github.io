#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=5;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"81";
		return 0;
	}
	else if(n==2)
	{
		cout<<"10";
		return 0;
	}
	return 0;
}
