#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long t,m,a,b,c,derta,o,a1,f;
long long q1,q2;
bool zheng,u,w,z;
int gcd(int a,int b){
	if(a>b) swap(a,b);
	if(a==0) return b;
	else if(a==1) return 1;
	else return gcd(b%a,a);
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(a>0)
			zheng=true;
		else 
			zheng=false;
		if(b==0) z=true;
		else z=false;
		derta=(b*b-4*a*c);
		b=-b;
		a1=abs(a)*2;
		if(derta<0){
			cout<<"NO"<<endl;
			continue;
		}
		else if(derta==0){
			if((a<0||b<0)&&(a>=0||b>=0)){
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				if(a==1){
					cout<<-b<<endl;
				}
				else{
					cout<<-b<<"/"<<a<<endl;
				}
			}
			else{
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				if(a==1){
					cout<<b<<endl;
				}
				else{
					cout<<b<<"/"<<a<<endl;
				}
			}
		}//derta=0
		else{
			q2=1;
			o=sqrt(derta)+1;
			while(o>0){
				if(derta%(o*o)==0){
					q2*=o;
					derta/=(o*o);
				}
				o--;
			}
			if(derta==1) u=true;
			else u=false;
			if(u==true){
				if(a<0){
				b-=q2;
				if(b<=0) w=true;
				else w=false;
				a1=abs(a)*2;
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				if(a==1){
					if(w==true) cout<<b<<endl;
					else cout<<-b<<endl;
				}
				else {
					if(w==true) cout<<b<<"/"<<a<<endl;
					else cout<<-b<<"/"<<a<<endl;
				}
			}
			else {
				b+=q2;
				if(b>=0) w=true;
				else w=false;
				a1=abs(a)*2;
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				
				if(a==1){
					if(w==true) cout<<b<<endl;
					else cout<<-b<<endl;
				}
				else {
					if(w==true) cout<<b<<"/"<<a<<endl;
					else cout<<-b<<"/"<<a<<endl;
				}
			}
			}//huajianmeile
			else{
				if((a<0||b<0)&&(a>=0||b>=0)&&b!=0){
				a1=abs(a)*2;
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				if(a==1){
					cout<<-b;
				}
				else {
					cout<<-b<<"/"<<a;
				}
			}
			else if(b!=0){
				a1=abs(a)*2;
				a=abs(a)*2;
				b=abs(b);
				f=gcd(a,b);
				a/=f;
				b/=f;
				if(a==1){
					cout<<b;
				}
				else{
					cout<<b<<"/"<<a;
				}
			}
			f=gcd(q2,a1);
			a1/=f;
			q2/=f;
//			cout<<a1<<" "<<q2<<" "<<f<<endl;
			if(zheng==false){
				if(u==true){
					if(a1==1){
						if(z==true) cout<<q2<<endl;
						else cout<<"-"<<q2<<endl;
					}
					else{
						if(z==false)cout<<"-"<<q2<<"/"<<a1<<endl;
						else cout<<q2<<"/"<<a1<<endl;
					}
				}
				else{
					if(q2==1&&a1==1){
						if(z==true) cout<<"sqrt("<<derta<<")"<<endl;
						else cout<<"+sqrt("<<derta<<")"<<endl;
					}
					else if(q2==1)
						if(z==true)  cout<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
						else cout<<"+sqrt("<<derta<<")"<<"/"<<a1<<endl;
					else if(a1==1){
						if(z==true) cout<<q2<<"*"<<"sqrt("<<derta<<")"<<endl;
						else cout<<"+"<<q2<<"*"<<"sqrt("<<derta<<")"<<endl;
					}
					else{
						if(z==true) cout<<q2<<"*"<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
						else cout<<"+"<<q2<<"*"<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
					}
				}
			}
			else{
				if(u==true){
					if(a1==1){
						if(z==true) cout<<q2<<endl;
						else cout<<"+"<<q2<<endl;
					}
					else{
						if(z==false)cout<<"+"<<q2<<"/"<<a1<<endl;
						else cout<<q2<<"/"<<a1<<endl;
					}
				}
				else{
					if(q2==1&&a1==1){
						if(z==true) cout<<"sqrt("<<derta<<")"<<endl;
						else cout<<"+sqrt("<<derta<<")"<<endl;
					}
					else if(q2==1)
						if(z==true)  cout<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
						else cout<<"+sqrt("<<derta<<")"<<"/"<<a1<<endl;
					else if(a1==1){
						if(z==true) cout<<q2<<"*"<<"sqrt("<<derta<<")"<<endl;
						else cout<<"+"<<q2<<"*"<<"sqrt("<<derta<<")"<<endl;
					}
					else{
						if(z==true) cout<<q2<<"*"<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
						else cout<<"+"<<q2<<"*"<<"sqrt("<<derta<<")"<<"/"<<a1<<endl;
					}
				}
			}
		}
	}
}
	return 0;
}
	
