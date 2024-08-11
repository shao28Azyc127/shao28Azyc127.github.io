#include<bits/stdc++.h>
using namespace std;
int n,k,day,ans;
int n1,k1,day1;
int main(){
	freopen('apple.in','r',stdin);
    freopen('apple.out','w',stdout);
	cin >> n;
	n1=n;
	while(1)
	{
		if(n%3!=0)k=n/3+1;
		else k=n/3;
		n=n-k;
		day++;
		if(n==0)break;
	}
	while(1)
	{
		if(n1%3==1)
		{
			ans=day1+1;
			break;
		}
		if(n1%3!=0)k1=n1/3+1;
		else k1=n1/3;
		n1=n1-k1;
		day1++;
		if(n1==0)break;
	}
	cout << day << " " << ans << endl;
    return 0;
}