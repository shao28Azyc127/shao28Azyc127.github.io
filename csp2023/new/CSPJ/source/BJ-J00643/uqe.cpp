#include<iostream>
#include<cmath>
using namespace std;
int t,m,a,b,c,pbs,sqrpbs;
int exgcd(int x,int y){
	if(!y){
		return x;
	}
	return exgcd(y,x%y);
}
void yls(int x,int y){
	int k=exgcd(abs(x),abs(y));
	x/=k;y/=k;
	if(y<0){
		x=-x;
		y=-y;
	}
	if(y==1){
		cout<<x;
	}
	else{
		cout<<x<<"/"<<y;
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		pbs=b*b-4*a*c;
		sqrpbs=int(sqrt(pbs));
		if(pbs<0){
			cout<<"NO"<<endl;
			continue;
		}
		if(sqrpbs*sqrpbs==pbs){
			yls(sqrpbs*((a<0)?-1:1)-b,2*a);
			cout<<endl;
			continue;
		}
		int q1c,q1d,q2c,q2d,r,mx=0;
		q1c=-b;q1d=2*a;q2c=(a<0)?-1:1;q2d=2*a;r=pbs;
		for(int i=1;i*i<=r;i++){
			if((r%(i*i))==0){
				mx=max(mx,i);
			}
		}
		q2c*=mx;r/=(mx*mx);
		if(q1c!=0){
			yls(q1c,q1d);
			cout<<"+";
		}
		if(q2c==q2d){
			cout<<"sqrt("<<r<<")";
		}
		else if(abs(q2c)%abs(q2d)==0){
			yls(q2c,q2d);
			cout<<"*sqrt("<<r<<")";
		}
		else if(abs(q2d)%abs(q2c)==0){
			cout<<"sqrt("<<r<<")/";
			yls(q2d,q2c);
		}
		else{
			int k=exgcd(abs(q2c),abs(q2d));
			q2c/=k;q2d/=k;
			if(q2d<0){
				q2c=-q2c;
				q2d=-q2d;
			}
			cout<<q2c<<"*"<<"sqrt("<<r<<")/"<<q2d;
		}
		cout<<endl;
	}
	return 0;
}
