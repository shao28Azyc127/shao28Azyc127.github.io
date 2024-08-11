#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0)	return a;
	return gcd(b,a%b);
}
void eqa(int a,int b,int c){
	int delta=b*b-4*a*c;
	if(delta<0){
		cout<<"No"<<endl;
		return ;
	}
	bool flag=0;
	if(b){
		if(b%(2*a)==0)	cout<<-b/2/a;
		else{
			cout<<-b/gcd(2*a,b)<<"/"<<2*a/gcd(2*a,b);
		}
	}
	else	flag=1;
	if(delta==0){
		if(flag)	cout<<0<<endl;
		return ;
	}
	if(!flag)	cout<<"+";
	int i=2,del=1,del2=1,cou=0;
	while(delta){
		if(delta%i==0){
			delta/=i;
			del*=i;
			cou++;
		}
		else{
			if(cou%2){
				del/=i;
				del=(int)sqrt(del);
				del2*=i;
			}
			cou=0;
			i++;
		}
	}
	if(del2==1){
		if(del%(2*a)==0)	cout<<del/2/a;
		else	cout<<del/gcd(del,2*a)<<"/"<<2*a/gcd(del,2*a);
	}
	else{
		if(del%(2*a)==0)	cout<<del/2/a<<"*sqrt("<<del2<<")";
		else cout<<del/gcd(del,2*a)<<"*sqrt("<<del2<<")"<<2*a/gcd(del,2*a);
	}
	cout<<endl;
}
int main(){
	 freopen("uqe.in","r",stdin);
	 freopen("uqe.out","w",stdout);
	 int t,m,a,b,c;
	 cin>>t>>m;
	 while(t--){
		cin>>a>>b>>c;
		eqa(a,b,c);
	}
	return 0;
}
