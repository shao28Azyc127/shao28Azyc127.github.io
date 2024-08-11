#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n,i=0,ans=-1;
	scanf("%lld",&n);
	while(n>0){
		i++;
		if(n%3==1&&ans==-1)
			ans=i;
		if(n%3==0)
			n=n-n/3;
		else
			n=n-n/3-1;
	}
	printf("%lld %lld",i,ans);
	return 0;
}
