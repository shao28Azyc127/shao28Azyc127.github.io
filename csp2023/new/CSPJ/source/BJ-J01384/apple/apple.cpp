#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long n,d,ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld",&n);
	bool flag=0;
	while(n){
		d++;
		if((n-1)%3==0 && flag==0){
			ans=d;
			flag=1;
		}
		n-=((n-1)/3+1);
	}
	printf("%lld %lld",d,ans);
	return 0;
}
