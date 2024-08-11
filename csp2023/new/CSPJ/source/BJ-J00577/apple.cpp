#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i;
	cin>>n;
	int time=0,ans=0;
	int out=0;
	bool flag=false;
	for(i=n;i>0;i+=0)
	{
		out=(i+2)/3;
		time++;
		if((i+2)%3==0 and flag==false)
		{
			flag=true;
			ans=time;
		}
		i-=out;
	}
	cout<<time<<" "<<ans;
	return 0;
}