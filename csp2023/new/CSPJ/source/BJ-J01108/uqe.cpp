#include<cmath>
#include<iostream>
using namespace std;
int T,M;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	
	int a,b,c;
	cin>>a>>b>>c;
	int delta=b*b-4*a*c;
	
	if(delta<0){
		cout<<"NO"<<endl;
		return;
	}
	
	if(((int)sqrt(delta))*((int)sqrt(delta))==delta){
		int fm=2*a,fz=-1*b;
		if(a>0) fz+=sqrt(delta);
		else fz-=sqrt(delta);
		int k=gcd(abs(fz),abs(fm));
		fz/=k,fm/=k;
		if(fz*fm<0) cout<<"-";
		fz=abs(fz),fm=abs(fm);
		if(fm==1) cout<<fz<<endl;
		else cout<<fz<<"/"<<fm<<endl;
	}
	else{
		int fz=-1*b,fm=2*a,r=1,k=gcd(abs(fz),abs(fm));
		
		if(fz!=0){
			fz/=k,fm/=k;
			if(fz*fm<0) cout<<"-";
			fz=abs(fz),fm=abs(fm);
			if(fm==1) cout<<fz;
			else cout<<fz<<"/"<<fm;
			cout<<"+";
		}
		for(int i=3*M;i>=1;i--){
			if(delta%(i*i)==0) r*=i,delta/=(i*i);
		}
		
		fz=r;fm=abs(2*a);
		k=gcd(fz,abs(fm));
		fz/=k,fm/=k;
		
		if(fm==1&&fz==1) cout<<"sqrt("<<delta<<")"<<endl;
		else if(fm==1) cout<<fz<<"*"<<"sqrt("<<delta<<")"<<endl;
		else if(fz==1) cout<<"sqrt("<<delta<<")/"<<fm<<endl;
		else cout<<fz<<"*"<<"sqrt("<<delta<<")/"<<fm<<endl;
	}
	return;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--) solve();
	return 0;
}
