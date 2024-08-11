#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	int ans;
	bool flag=1;
	while(n>0)
	{	
		cnt++;
		if(n%3==1&&flag==1)
		{
			
			ans=cnt;
			flag=0;
		}	
		n-=ceil(1.0*n/3);
		
	}
	cout<<cnt<<" "<<ans<<endl;
	return 0;
}