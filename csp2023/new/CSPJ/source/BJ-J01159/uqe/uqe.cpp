#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	int xx=max(x,y),yy=min(x,y);
	while(1){
		if(xx%yy==0) return yy;
		xx=xx%yy;
		if(yy%xx==0) return xx;
		yy=yy%xx;
		if(xx%yy==0) return yy;
	}
}
void print(int x,int y){
	bool p=0;
	if(x<0){
		if(y<0){
			x=-x;
			y=-y;
		}
		else{
			p=1;
			x=-x;
		}
	}
	else if(y<0){
		y=-y;
		p=1;
	}
	int g=gcd(x,y);
	x/=g;
	y/=g;
	if(p) cout<<"-";
	if(y==1) cout<<x;
	else cout<<x<<"/"<<y;
}
void print2(int de,int x,int c){
	x=abs(x);
	c=abs(c);
	int g=gcd(x,c);
	x/=g;
	c/=g;
	if(x==c) cout<<"sqrt("<<de<<")";
	else if(c==1) cout<<x<<"*sqrt("<<de<<")";
	else if(x==1) cout<<"sqrt("<<de<<")/"<<c;
	else cout<<x<<"*sqrt("<<de<<")/"<<c;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int del=b*b-4*a*c;
		if(del<0){
			cout<<"NO"<<endl;
			continue;
		}
		int s=sqrt(del);
		if(s*s==del){
			print(-b+s,2*a);
			cout<<endl;
			continue;
		}
		int q2=1;
		for(int i=s;i>1;i--){
			if(del%(i*i)==0){
				del/=i*i;
				q2*=i;
			}
		}
		if(b!=0){
			print(-b,2*a);
			cout<<"+";
		}
		print2(del,q2,2*a);
		cout<<endl;
	}
	return 0;
}
