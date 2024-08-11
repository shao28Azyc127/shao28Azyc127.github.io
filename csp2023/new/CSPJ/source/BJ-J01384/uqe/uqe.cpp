#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,M,a,b,c;
ll se(ll k){
	for(int i=k;i>=2;i--){
		if(k%(i*i)==0){
			return i;
		}
	}
	return 1;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%lld%lld",&T,&M);
	while(T--){
		cin>>a>>b>>c;
		if(b*b-4*a*c<0){
			printf("NO\n");
			continue;
		}
		if(b==0){
			ll p=sqrt(0-c);
			if(p*p==(0-c)){
				printf("%lld\n",p);
			}
			else{
				if(a>0){
					ll k=0-c;
				ll t=se(k);
				if(t==1){
					printf("sqrt(%lld)\n",k);
				}
				else{
					printf("%lld*sqrt(%lld)\n",t,k/(t*t));
				}
				}
				else{
					ll k=c;
					ll t=se(k);
					if(t==1){
					printf("sqrt(%lld)\n",k);
				}
				else{
					printf("%lld*sqrt(%lld)\n",t,k/(t*t));
				}
				}
			}
			continue;
		}
		ll p,q,derta;
		derta=b*b-4*a*c;
		p=((0-b)+sqrt(derta))/(2*a);
		q=((0-b)-sqrt(derta))/(2*a);
		printf("%lld\n",max(p,q));
	}
	return 0;
}
