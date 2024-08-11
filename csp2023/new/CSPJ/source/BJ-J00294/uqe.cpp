#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define ll long long
#define ld long double
ll t,m,a,b,c;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%lld%lld",&t,&m);
	while(t--){
		scanf("%lld%lld%lld",&a,&b,&c);
		if(b*b-4*a*c<0){
			puts("NO");
			continue;
		}
		if(sqrt(b*b-4*a*c)*sqrt(b*b-4*a*c)==b*b-4*a*c){
			ld q1=(2.0*a)/(b*-1+sqrt(b*b-4.0*a*c));
			ld q2=(2.0*a)/(b*-1-sqrt(b*b-4.0*a*c));
			ld x=max(q1,q2);
			cout<<x<<endl;
		}
	}
	return 0;
}