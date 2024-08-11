#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll,ll>sqe(ll n){
	pair<ll,ll>ret;
	ret.first=1;
	for(ll i=2;i*i<=n;i++){
		while(!(n%(i*i))){
			ret.first*=i;
			n/=i*i;
		}
	}
	ret.second=n;
	return ret;
}
int gcd(int n1,int n2){
	int g1=__gcd(n1,n2);
	if(n2/g1<0)
		return -g1;
	return g1;
}
ll t,m,a,b,c,dt,n11,n12,g;
ll cnt1,cnt2,cnt3;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%lld %lld",&t,&m);
	for(;t--;printf("\n")){
		cin>>a>>b>>c;
		dt=b*b-4*a*c;
		if(dt<0){
			//cout<<a<<' '<<b<<' '<<c<<' '<<dt<<endl;
			printf("NO");
			continue;
		}
		if(dt==0){
			//cout<<a<<' '<<b<<' '<<c<<' '<<dt<<endl;
			cnt2++;
			g=gcd(-b,2*a);
			n11=-b/g;
			n12=2*a/g;
			if(n12==1) printf("%lld",n11);
			else printf("%lld/%lld",n11,n12);
			continue;
		}
		cnt3++;
		//cout<<a<<' '<<b<<' '<<c<<' '<<dt<<endl;
		pair<ll,ll>n2=sqe(dt);//sqrt(dt)=n2.f*sqrt(n2.s)
		if(n2.second==1){
			//n2.f:答案的分子
			//n2.s:答案的分母
			n2.first*=abs(a)/a;
			n2.first-=b;
			n2.second=2*a;
			//cout<<n2.first<<' '<<n2.second<<endl;
			g=gcd(n2.first,n2.second);
			n2.first/=g,n2.second/=g;
			printf("%lld",n2.first);
			if(n2.second!=1)
				printf("/%lld",n2.second);
			continue;
		}
		if(b!=0){	
			g=gcd(-b,2*a);
			n11=-b/g;
			n12=2*a/g;
			if(n12==1) printf("%lld+",n11);
			else printf("%lld/%lld+",n11,n12);
		}
		n12=abs(2*a);
		g=gcd(n2.first,n12);
		n2.first/=g;
		n12/=g;
		if(n2.first!=1) printf("%lld*",n2.first);
		printf("sqrt(%lld)",n2.second);
		if(n12!=1) printf("/%lld",n12);
	}
//	cout<<cnt1<<' '<<cnt2<<' '<<cnt3;
	return 0;
}/*
9 1000
1 ‐1 0
‐1 ‐1 ‐1
1 ‐2 1
1 5 4
4 4 1
1 0 ‐432
1 ‐3 1
2 ‐4 1
1 7 1
*/
