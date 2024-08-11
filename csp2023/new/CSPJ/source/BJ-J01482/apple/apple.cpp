#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int x=n;
    int ans1=0;
    while(n!=0)
    {
		if(n%3==0)
		{
			n-=n/3;
			ans1++;
		}
		else
		{
			n-=n/3+1;
			ans1++;
		}
	}
	cout<<ans1<<" ";
	if(x%3==1)
	{
		cout<<1;
	}
	else
	{
		cout<<ans1;
	}
}
