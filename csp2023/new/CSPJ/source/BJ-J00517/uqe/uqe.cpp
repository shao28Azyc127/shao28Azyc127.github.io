#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1005;
int a,b,c;
bool pre[N];
vector<int> ve;
void init(){
	pre[1]=false;
	for(int i=2;i<=N;i++){
		if(pre[i]==false){
			continue;
		}else{
			for(int j=2;j*i<=N;j++){
				pre[i*j]=false;
			}
			ve.pb(i);
		}
	}
}
inline int gcd(int n,int m){
	int ans=1;
	int l=n,r=m;
	for(auto x:ve){
		if(x>min(n,m)){
			break;
		}
		while(l%x==0 && r%x==0){
			ans*=x;
			l/=x;
			r/=x;
		}
	}
	return ans;
}
inline void num(){
	int n=2*a,m=-b;
	if(m%n==0){
		cout<<m/n;
	}else{
		int gc=gcd(abs(n),abs(m));
		if(n<0){
			cout<<-m/gc<<"/"<<-n/gc;
		}else{
			cout<<m/gc<<"/"<<n/gc;
		}
	}
}
inline void sq(int dt){
	int p2=1,d=dt;
	for(auto x:ve){
		if(x*x>dt){
			break;
		}
		while(d%(x*x)==0){
			p2*=x;
			d/=(x*x);
		}
	}
	int r=dt/(p2*p2),n=2*a;
	if(p2%n==0){
		if(abs(p2/n)==1){
			cout<<"sqrt("<<r<<")";
		}else{
			cout<<abs(p2/n)<<"*sqrt("<<r<<")";		
		}
	}else{
		int gc=gcd(abs(n),abs(p2));
		if(p2/gc==1){
			cout<<"sqrt("<<r<<")"<<"/"<<abs(n/gc);	
		}else{
			cout<<abs(p2/gc)<<"*sqrt("<<r<<")"<<"/"<<abs(n/gc);
		}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	memset(pre,true,sizeof(pre));
	init();
	int T,M;
	cin>>T>>M;
	for(int ti=1;ti<=T;ti++){
		cin>>a>>b>>c;
		int dt=b*b-4*a*c;
		if(dt<0){
			cout<<"NO"<<endl;
			continue;
		}
		int z=sqrt(dt);
		bool p=false;
		if(z*z==dt){
			p=true;
			if(a<0){
				b+=z;
			}else{
				b-=z;
			}
		}
		if(b==0 && p==true){
			cout<<0;
		}
		if(b!=0){
			num();
			if(!p){
				cout<<"+";
			}
		}
		if(!p){
			sq(dt);
		}
		cout<<endl;
	}
	return 0;
}