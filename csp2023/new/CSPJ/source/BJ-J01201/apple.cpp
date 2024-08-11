#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d1=1,d2=0;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<1<<' '<<1;
		return 0;
		}
	while(n)
	{
		if((n-1)%3==0&&(!d2))d2=d1;
		if(n%3>0)
		n-=n/3,n--;
		else
		n-=n/3;
		if(!n)break;
		d1++;
		}
	cout<<d1<<' '<<d2;
	return 0;
	}
