#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,M;
typedef long long ll;
ll a,b,c;
ll q1z,q1m,q2z,q2m,r,g;//(-b/2a)+q2*sqrt(r)
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
ll p[1005] = {};
bool f = 0;

void pry(ll p,ll q){
	if(p==0 || q==0)return;
	f = 1;
	if(q < 0){
		p = -p;
		q = -q;
	}
	if(q == 1)printf("%lld",p);
	else printf("%lld/%lld",p,q);
}
void prw(ll x,ll m,ll g){
	if(x==0 || r==0 || m==0)return;
	if(f)printf("+");
	if(m < 0){
		x = -x;
		m = -m;
	}
	if(x == 1)printf("sqrt(%lld)",g);
	else printf("%lld*sqrt(%lld)",x,g);
	if(m != 1)printf("/%lld",m);
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	
	for(ll i=1;i<=1001;i++)p[i] = i*i;
	scanf("%d%d",&T,&M);
	while(T--){
		f = 0;
		scanf("%lld%lld%lld",&a,&b,&c);
		r = b*b-4*a*c;
		if(r < 0){//wujie
			printf("NO\n");
			continue;
		}
		//
		q2z = 1ll;
		for(int i=1001;i>1;i--){
			if(r%p[i] == 0){
				q2z *= (long long)i;
				r /= p[i];
			}
		}
		//
		if(r == 1){
			//if(a < 0)q2z = -q2z;
			g = gcd(-b+q2z,2*a);
			q1z = (-b+q2z) / g;
			q1m = 2*abs(a)/g;
			//if(a < 0)q1z = -q1z;
			//cout<<"&&&"<<q1z<<" "<<q1m<<" "<<q2z<<" "<<q2m<<" "<<r<<endl;
			pry(q1z,q1m);
			printf("\n");
			continue;
		}
		//
		g = gcd(-b,2*a);
		//cout<<"---"<<g<<endl;
		q1z = (-b) / g;
		q1m = abs(a)*2/g;
		//if(a < 0)q1z = -q1z;
		
		g = gcd(q2z,2*a);
		q2z /= g;
		q2m = abs(a)*2/g;
		//if(a < 0)q2z = -q2z;
		//
		pry(q1z,q1m);//youlishushuchu
		prw(q2z,q2m,r);//wulishushuchu
		printf("\n");
		//cout<<"&&&"<<q1z<<" "<<q1m<<" "<<q2z<<" "<<q2m<<" "<<r<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
