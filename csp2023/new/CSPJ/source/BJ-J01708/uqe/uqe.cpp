// why rdfz has just 2 cpu too
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll mod=0;
ll t,m,a,b,c;
ll getpf(ll x){
	ll tmp=0;
	for(ll i=1;i*i<=x;i++)if(x%(i*i)==0)tmp=i;
	return tmp;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		ll delta=b*b-4ll*a*c;
		if(delta<0)cout<<"NO\n";
		else{
			//-b/2a+sqrt(delta)/2a
			ll q1p1=-b,q1q1=2*a;
			ll q1p2=-b,q1q2=2*a;
			ll q2p=getpf(delta),q2q=2*a;
			if(q2p*q2p==delta||delta==0)q1p1+=q2p,q1p2-=q2p,q2p=0;
			ll g=gcd(q1p1,q1q1);
			q1p1/=g,q1q1/=g;
			if(q1q1<0)q1p1=-q1p1,q1q1=-q1q1;
			g=gcd(q1p2,q1q2);
			q1p2/=g,q1q2/=g;
			if(q1q2<0)q1p2=-q1p2,q1q2=-q1q2;
			ll q1p,q1q;
			double tmp1=q1p1*1.0/q1q1,tmp2=q1p2*1.0/q1q2;
			if(tmp1<tmp2)q1p=q1p2,q1q=q1q2;
			else q1p=q1p1,q1q=q1q1;
			if(q1p!=0){
				cout<<q1p;
				if(q1q>1) cout<<"/"<<q1q;
			}
			if(q2p!=0){
			ll r=delta/q2p/q2p;
				g=gcd(q2p,q2q);
				q2p/=g,q2q/=g;
				if(q2q<0)q2q=-q2q;
				if(q2p<0)q2p=-q2p;
				if(q2p!=0&&q1p!=0)cout<<"+";
				if(q2p!=0){
					if(q2p!=1)cout<<q2p<<"*";
					cout<<"sqrt("<<r<<")";
					if(q2q>1)cout<<"/"<<q2q;
				}
			}
			if(q2p==0&&q1p==0)cout<<0;
			cout<<'\n';
		}
	}
	return 0;
}