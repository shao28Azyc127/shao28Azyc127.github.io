#include<bits/stdc++.h>
using namespace std;
int n,m,ansx,ansy=1;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	m=n;
	while(n>0)
	{
		if(n%3==0) n-=(n/3);
		else n-=(n/3+1);
		ansx++;
	}
	while(m>0)
	{
		if(m%3==1) break;
		if(m%3==0) m-=(m/3);
		else m-=(m/3+1);
		ansy++;
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
