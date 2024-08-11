#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans1=0,ans2=0;
	if(n==1)	cout<<"1 1";
	if(n==2)	cout<<"2 2";
	if(n==3)	cout<<"3 3";
	if(n==4)	cout<<"3 1";
	if(n==5)	cout<<"4 4";
	if(n==6)	cout<<"4 2";
	if(n==7)	cout<<"4 1";
	if(n==8)	cout<<"5 5";
	if(n==9)	cout<<"5 3";
	if(n==10)	cout<<"5 1";
	if(n<11)	return 0;
	bool flag=0;
	while(n>0)
	{
		int nn=n;
		int i;
		for(i=1;i<=n;i+=3)
			nn--;
		ans1++;
		if(i-3==n&&!flag)
		{
			ans2=ans1;
			flag=1;
		}	
		n=nn;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
// 1 1 1
// 2 2 2
// 3 3 3
// 4 3 1
// 5 4 4
// 6 4 2
// 7 4 1
// 8 5 5
// 1 4 7 10
// 2 6 11
// 3 9
// 5
// 8 