#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
int gcd_rp(int x,int y){
	if(x<y)	std::swap(x,y);
	while(x!=0){
		if(y==0)	return x;
		int t=y;
		y=x%y;
		x=t;
	}
	return y;
}
void get_div(int &x,int &y){
	if(y<0){x=-x;y=-y;}
	int tmp=gcd_rp(x,y);
	if(tmp<0)tmp=-tmp;
	x/=tmp;
	y/=tmp;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int del=b*b-4*a*c;
		if(del<0){
			cout<<"NO\n";
			continue;
		}
		if(sqrt(del)==(int)sqrt(del)){
			int x1=-b+sqrt(del),y1=2*a,x2=-b-sqrt(del),y2=2*a;
			get_div(x1,y1);get_div(x2,y2);
			if(1.0*x1/y1<1.0*x2/y2){x1=x2;y1=y2;}
			cout<<x1;
			if(y1!=1)	cout<<'/'<<y1;
			cout<<endl;
		} else {
			int q2=1;
			while(1){
				bool flag=false;int i=2;
				for(;i*i<=del;i++)
					if(del%(i*i)==0){
						del/=i*i;
						q2*=i;
						flag=true;
						break;
					}
				if(!flag)	break;
			}
			int x=-b,y=2*a;
			get_div(x,y);
			if(x!=0){
				cout<<x;
				if(y!=1)	cout<<'/'<<y;
				cout<<'+';
			}
			x=q2;y=2*a;int x2=-q2,y2=2*a;
			get_div(x,y);get_div(x2,y2);
			if(1.0*x/y<1.0*x2/y2){x=x2;y=y2;}
			if(x<0)	x=-x;
			if(y<0)	y=-y;
			if(x!=1)	cout<<x<<'*';
			cout<<"sqrt("<<del<<')';
			if(y!=1)	cout<<'/'<<y;
			cout<<endl;
		}
	}
	return 0;
}
