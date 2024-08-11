#include<bits/stdc++.h>
using namespace std;
int T,m;
double t1,t2;
int a1,a2;
int y;
double r2;
int q1,q2,q3;
int find(int r){
	r2=r;
	y=sqrt(r2);
	while(1){
		if(r%(y*y)==0){
			return y;
		}
		y--;
	}
	return 1;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>m;
	while(T--){
		double a,b,c;
		cin>>a>>b>>c;
		double s=(b*b-4*a*c);
		if(s<0){
			cout<<"NO"<<endl;
			continue;
		}
		//bool e=false;
		t1=(-b+sqrt(s))/(2*a);
		t2=(-b-sqrt(s))/(2*a);
		//if(t1>t2)
		//	e=false;
		//else
		//	e=true;
		int u=sqrt(s);
		if(u*u==s){
			int tmp;
			if(t1>t2){	
				a1=-b+u;
				a2=2*a;
				tmp=__gcd(a1,a2);
			}
			else{
				a1=-b-u;
				a2=2*a;
				tmp=__gcd(a1,a2);
			}
			a1/=tmp;
			a2/=tmp;
			if(a2==1){
				cout<<a1<<endl;
			}
			else{
				if(a2<0){
					a2=abs(a2);
					cout<<"-";
				}
				cout<<a1<<"/"<<a2<<endl;
			}
		}
		else{
			
			q1=-b;
			q2=find(s);
			q3=s/q2/q2;
			a2=2*a;
			int tmp=__gcd(q1,a2);
			q1/=tmp;
			a2/=tmp;
			if(a2==1&&q1!=0){
				cout<<q1<<"+";
			}
			else if(q1!=0){
				if(a2<0){
					a2=abs(a2);
					cout<<"-";
				}
				cout<<q1<<"/"<<a2<<"+";
			}
			if(t1<t2) q2*=-1;
			if(q2==1){
				cout<<"sqrt("<<q3<<")/"<<a2;
			}
			else{
				int tmp=__gcd(q2,a2);
				q2/=tmp;
				a2/=tmp;
				if(a2==1){
					if(q2==1){
						cout<<"sqrt("<<q3<<")";
					}
					else{
						cout<<q2<<"*sqrt("<<q3<<")";
					}
				}
				else {
					if(a2<0){
						a2=abs(a2);
						cout<<"-";
					}
					cout<<q2<<"*sqrt("<<q3<<")/"<<a2;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
