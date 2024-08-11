#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
struct node{
	ll p,q;
	void build(ll a,ll b){
		p=a,q=b;
		if(q==0)q=1;
		ll g=gcd(abs(p),abs(q));
		if(p<0&&q<0)p=-p,q=-q;
		else if(p>=0&&q<0){p=-p,q=-q;}
		p/=g,q/=g;
	}
	void print(){
		if(q==1){
			printf("%lld",p);
		}
		else{
			printf("%lld/%lld",p,q);
		}
	}
};
struct sqr{
	ll k,x;
	void build(ll o){
		x=o;
		ll t=x;k=1;
		for(ll i=sqrt(t);i*i>=2;i--){
			if(t%(i*i)==0){
				k=i;x/=k;x/=k;break;
			}
		}
	}
};
int main(){
	freopen("uqe.in","r",stdin);
	
	freopen("uqe.out","w",stdout);
	//~ node a;
	//~ a.p=1,a.q=-2;
	//~ a.print();
	
	ll T,m;cin>>T>>m;
	while(T--){
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		ll d=b*b-4*a*c;//cout<<"D"<<d<<endl;
		node q1,q2,tmp; sqr p;
		if(d<0){printf("NO\n");continue;}
		else if(d==0){
			q1.build(-b,2*a);
			q1.print();printf("\n");continue;
		}
		else// you lia jie
		{
			p.build(d);
			//cout<<p.k<<' '<<p.x<<"L"<<endl;
			if(p.x==1){//x shi you li shu
				tmp.build(-b+p.k,2*a);
				node r;//cout<<"KO";
				r.build(-b-p.k,2*a);
				//r.print();//cout<<"endl";tmp.print();
				if(((double)tmp.p/tmp.q)<((double)r.p/r.q)){r.print();}
				else tmp.print();
				printf("\n");continue;
			}
			else{
				q1.build(-b,2*a);q2.build(p.k,2*a);
				if(b!=0){
					q1.print();printf("+");
				}
				if(abs(q2.p)==1&&abs(q2.q)==1)
				{
					printf("sqrt(%lld)\n",p.x);continue;
				}
				if(abs(q2.q)==1)
				{
					printf("%lld*sqrt(%lld)\n",abs(q2.p),p.x);continue;
				}
				if(abs(q2.p)==1){
					printf("sqrt(%lld)/%lld\n",abs(p.x),q2.q);continue;
				}
				printf("%lld*sqrt(%lld)/%lld\n",abs(q2.p),p.x,abs(q2.q));
			}
		}
	}
	return 0;
}
