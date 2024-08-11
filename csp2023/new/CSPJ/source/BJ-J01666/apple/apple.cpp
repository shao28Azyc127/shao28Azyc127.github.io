#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int tmp,ts=1,ans=0,cnt=0,flag=0;
	while(1)
	{
		cnt++;
		if(cnt!=1) ts++;
		if(n%3==1 && flag==0 && n>3) 
		{
			ans=ts;
			flag=1;
		}
		if(n<=3 && flag==0) 
		{
			ans=ts+2;
			flag=1;
		} 
		if(n%3==0 && n>=3) tmp=n/3;
		if(n%3!=0 && n>=3) tmp=n/3+1;
		if(n<3) tmp=1;
		n-=tmp;
		if(n<0) 
		{
			ts--;
			break;
		}
	}
	cout<<ts<<endl<<ans;
	return 0;
}
