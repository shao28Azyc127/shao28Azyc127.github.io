#include<bits/stdc++.h>
using namespace std;

int t,m;
long long a,b,c;
long long drt,sqdrt;
long long p,q,g;
long long p1,q1,p2,q2,r;
long long tmp;

long long gcd(long long ax,long long bx){
	if(bx==0){
		return ax;
	}
	return gcd(bx,ax%bx);
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	scanf("%d%d",&t,&m);
	while(t--){
		scanf("%lld%lld%lld",&a,&b,&c);
		drt=b*b-4*a*c;
		if(drt<0){
			printf("NO\n");
		}
		else{
			sqdrt=sqrt(drt);
			if(sqdrt*sqdrt==drt){
				if(2*a>0){
					p=sqdrt-b;
				}
				else{
					p=-sqdrt-b;
				}
				q=2*a;
				if(q<0){
					q=-q;
					p=-p;
				}
				if(p<0){
					g=gcd(-p,q);
					p/=g;
					q/=g;
					if(q==1){
						printf("%lld\n",p);
					}
					else{
						printf("%lld/%lld\n",p,q);
					}
				}
				else if(p>0){
					g=gcd(p,q);
					p/=g;
					q/=g;
					if(q==1){
						printf("%lld\n",p);
					}
					else{
						printf("%lld/%lld\n",p,q);
					}
				}
				else{
					printf("0\n");
				}
			}
			else{
				p1=-b;
				q1=2*a;
				if(2*a>0){
					p2=1;
				}
				else{
					p2=-1;
				}
				q2=2*a;
				r=drt;
				if(q1<0){
					q1=-q1;
					p1=-p1;
				}
				if(p1<0){
					g=gcd(-p1,q1);
					p1/=g;
					q1/=g;
				}
				else if(p1>0){
					g=gcd(p1,q1);
					p1/=g;
					q1/=g;
				}
				if(p1!=0){
					if(q1==1){
						printf("%lld+",p1);
					}
					else{
						printf("%lld/%lld+",p1,q1);
					}
				}
				for(int i=2;i*i<=r;++i){
					while(r%(i*i)==0){
						r/=i*i;
						p2*=i;
					}
				}
				if(q2<0){
					q2=-q2;
					p2=-p2;
				}
				if(p2<0){
					g=gcd(-p2,q2);
					p2/=g;
					q2/=g;
				}
				else if(p2>0){
					g=gcd(p2,q2);
					p2/=g;
					q2/=g;
				}
				if(p2==1 && q2==1){
					printf("sqrt(%lld)\n",r);
				}
				else if(q2==1){
					printf("%lld*sqrt(%lld)\n",p2,r);
				}
				else if(p2==1){
					printf("sqrt(%lld)/%lld\n",r,q2);
				}
				else{
					printf("%lld*sqrt(%lld)/%lld\n",p2,r,q2);
				}
			}
		}
	}
	return 0;
}
