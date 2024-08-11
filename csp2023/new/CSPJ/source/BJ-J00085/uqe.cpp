#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct dat{
	ll p1,q1,p2,q2,k;
	void minimize();
	void display();
};
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void dat::minimize(){
	for(ll i=sqrt(k);i>=1;i--){
		if(k%(i*i)==0){
			p2*=i;
			k/=(i*i);
		}
	}
	ll g=gcd(p1,q1);
	p1/=g;
	q1/=g;
	if(q1<0){
		q1=-q1;
		p1=-p1;
	}
	g=gcd(p2,q2);
	p2/=g;
	q2/=g;
	if(q2<0){
		q2=-q2;
		p2=-p2;
	}
}
void dat::display(){
	if(k>1){
		if(p1!=0){
			if(q1==1)cout<<p1;
			else cout<<p1<<"/"<<q1;
			cout<<"+";
		}
		if(p2==1&&q2==1)cout<<"sqrt("<<k<<")";
		else if(q2==1)cout<<p2<<"*sqrt("<<k<<")";
		else if(p2==1)cout<<"sqrt("<<k<<")/"<<q2;
		else cout<<p2<<"*sqrt("<<k<<")/"<<q2;
		cout<<endl;
	}else if(k==1){
		ll p=p1*q2+p2*q1;
		ll q=q1*q2;
		ll g=gcd(p,q);
		p/=g;
		q/=g;
		if(q<0){
			p=-p;
			q=-q;
		}
		if(q==1)cout<<p<<endl;
		else cout<<p<<"/"<<q<<endl;
	}else if(k==0){
		if(q1==1)cout<<p1<<endl;
		else cout<<p1<<"/"<<q1<<endl;
	}
}
int T,M;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--){
		ll a,b,c;
		cin>>a>>b>>c;
		ll delta=b*b-4*a*c;
		if(delta<0)cout<<"NO"<<endl;
		else if(a>0){
			dat ans={-b,2*a,1,2*a,delta};
			ans.minimize();
			ans.display();
		}else{
			dat ans={-b,2*a,-1,2*a,delta};
			ans.minimize();
			ans.display();
		}
	}
}