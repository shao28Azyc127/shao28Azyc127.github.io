#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,cnt=0,cnt1=0,cnt2=0;
	cin>>n;
	for(int i=1;;i=i+2)
	{
		a[i]=0;
		cnt++;
		if(a[i]==0)
		{
			i++;
		}
		if(a[n]==0)
		{
			cnt1=i;
		}
		if(n==0)
		{
			cnt2=cnt;
		}
		n--;
	}
	cout<<cnt1<<cnt2;
	return 0;
}
