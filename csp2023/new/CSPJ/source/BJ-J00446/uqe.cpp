#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int n=1;n<=t;n++){
		cin>>a>>b>>c;
		int drt=b*b-4*a*c;
		if(drt<0){
			cout<<"NO"<<endl;
			continue;
		}
		int sq=sqrt(drt),sqc=1;
		bool st=1;
		if(sq*sq==drt)st=0;
		else{
			bool x=0;
			for(sqc=drt;sqc>1&&x==0;sqc--){
				if(drt%sqc==0&&(drt/sqc)%sqc==0){
					drt/=sqc*sqc;
					sqc++;
					x=1;
				}
			}
		}
		int bf=0,fb=0-b,fm=2*a;
		if(fb<0)bf=1,fb=0-fb;
		if(st==1){
			int q1=__gcd(fb,fm),q2=fb/q1,q3=fm/q1;
			if(bf==1)cout<<'-';
			if(fb!=0){
				if(q3==1)cout<<q2<<'+';
				else cout<<q2<<'/'<<q3<<'+';
			}
			
			if(sqc!=1){
				int p1=__gcd(sqc,fm),p2=sqc/p1,p3=fm/p1;
				if(p2!=1)
					cout<<p2<<'*';
				cout<<"sqrt("<<drt<<")";
				if(p3!=1)
					cout<<"/"<<p3;
				cout<<endl;
			}
			else
				cout<<"sqrt("<<drt<<")/"<<fm<<endl;
		}
		else{
			if(bf==1)cout<<'-';
			int q1=__gcd(fb,fm),q2=fb/q1,q3=fm/q1;
			int p1=__gcd(sq,fm),p2=sq/p1,p3=fm/p1;
			if(q3==1){
				if(p3==1) cout<<p2+q2;
				else {if(q2!=0) cout<<q2<<'+';
				cout<<p2<<'/'<<p3;}
			}
			else{
				if(p3==1){
					cout<<q2<<'/'<<q3;
					if(p2!=0) cout<<'+'<<p2;
				}
				else{
					int r=fb+sq,r1=__gcd(r,fm),r2=r/r1,r3=fm/r1;
					if(r3==1) cout<<r2;
					else
						cout<<r2<<'/'<<r3;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
