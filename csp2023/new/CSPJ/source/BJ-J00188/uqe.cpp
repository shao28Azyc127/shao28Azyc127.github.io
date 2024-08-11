#include<bits/stdc++.h>
#include<math.h>

using namespace std;
int a,b,c,t,m,delta,gcdr,q1,q2,sqro,sqrm,r,dwn1,dwn2,adjsqrt;
int gcd(int uppx,int dwnx){
	uppx = abs(uppx);
	dwnx = abs(dwnx);
	for (int i=uppx; i>=1; i--){
		//cout<<i<<" "<<uppx%i<<" "<<dwnx%i<<endl;
		if(uppx % i == 0 && dwnx % i ==0){
			return i;

		}
	}}
int fdsqr(int m){
	for (int i = sqrt(m);i>=1;i--){
		if (m%(i*i)==0){
			return i;
		}
	}}

signed main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
while(t--){
	cin>>a>>b>>c;
	delta=b*b-4*a*c;
//	cout<<delta<<" "<<sqrt(delta)<<" "<<sqrt(delta)*sqrt(delta)<<endl;

	if(delta<0){
		cout<<"NO"<<endl;}

//	adjsqrt=sqrt(delta);
	else if (int(sqrt(delta))*int(sqrt(delta))==delta){

		int upp,dwn;
		//cout<<"YES(delete before submit)";
		upp=sqrt(delta)-b;
		dwn=2*a;
		gcdr=gcd(upp,dwn);
		upp=upp/gcdr;
		dwn=dwn/gcdr;
		if(dwn<0){
			upp*=-1;
			dwn*=-1;
		}
		if(dwn ==1){
			cout<<upp<<endl;
		}else{
		cout<<upp<<"/"<<dwn<<endl;
		}
	}
	else{
		int dwn;
		
		//cout<<"NUM(delete before submit)";
		q2=fdsqr(delta);
		r=delta/q2/q2;
//		cout<<q2<<" "<<r;
		dwn=2*a;
		q1=b*-1;
		gcdr=gcd(q1,dwn);
	//	cout<<q1<<dwn<<gcdr;
		q1=q1/gcdr;
		dwn1=dwn/gcdr;
		if( dwn1 <0){
			q1*=-1;
			dwn1*=-1;
		}
		if(dwn1 ==1){
			cout<<q1<<"+";
		}else if (dwn1 == 0){}

		else{cout<<q1<<"/"<<dwn1<<"+";}
		gcdr=gcd(q2,dwn);
		q2=q2/gcdr;
		dwn2=dwn/gcdr;
		//cout<<q2<<" "<<dwn2<<" "<<gcdr;
		if(dwn2 <0){
                        q2*=-1;
                        dwn2*=-1;
                }// all minus to be added
		if(q2==1 && dwn2 ==1){
		cout<<"sqrt("<<r<<")"<<endl;
		}else if(q2==1){
		cout<<"sqrt("<<r<<")/"<<dwn2<<endl;
		}else{
		cout<<q2<<"*sqrt("<<r<<")/"<<dwn2<<endl;
		}






	}
}
	//cin>>a>>b;
return 0;
	//cout<<gcd(a,b);
	//hexi kawaii
	}

