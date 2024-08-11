#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int f(int a,int b){
	int m=max(a,b),n=min(a,b),r;
	while(n!=0){
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}
void yls(int b,int a){
	int x;
	if(b==0){
		return;
	}
	if(a*b<0){
		cout<<"-";
	}
	a=abs(a);
	b=abs(b);
	while(f(b,a)!=1){
		x=f(b,a);
		b=b/x;
		a=a/x;
	}
	cout<<b;
	if(a!=1){
		cout<<"/"<<a;
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int a,b,c,der,t,m,ji,i,x,d;
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		ji=1;
		der=b*b-4*a*c;
		if(der<0){
			cout<<"NO"<<endl;
			continue;
		}
		if(der==0){
			yls(-b,2*a);
			if(b==0){
				cout<<0;
			}
			cout<<endl;
			continue;
		}
		d=der;
		for(i=d;i>=1;i--){
			if(d%i==0&&int(sqrt(i))*int(sqrt(i))==i){
				der=der/i;
				ji=ji*sqrt(i);
				break;
			}
		}
		if(der==1){
			yls(-b+ji,2*a);
			if(-b+ji==0){
				cout<<0;
			}
			cout<<endl;
			continue;
		}
		yls(-b,2*a);
		if(b!=0){
			cout<<"+";
		}
		int up,down;
		up=ji;
		down=abs(2*a);
		while(f(up,down)!=1){
			x=f(up,down);
			up=up/x;
			down=down/x;
		}
		if(up!=1){
			cout<<up<<"*";
		}
		cout<<"sqrt("<<der<<")";
		if(down!=1){
			cout<<"/"<<down;
		}
		cout<<endl;
	}
	return 0;
}

