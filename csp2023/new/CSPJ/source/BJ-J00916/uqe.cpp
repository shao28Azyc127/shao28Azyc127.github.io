#include<bits/stdc++.h>
using namespace std;

int t,m,ans,a,b,c,del,r;

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;++i){
		cin>>a>>b>>c;
		del=b*b-4*a*c;
		a*=2;
		if(del<0){
			cout<<"NO"<<endl;
		}
		else if(sqrt(del)==(int)sqrt(del)){
			b=(int)sqrt(del)-b;
			if(b%a==0){
				cout<<b/a<<endl;
			}
			else{
				for(int i=2;i<=b;++i){
					while(b%i==0&&a%i==0){
						b/=i;
						a/=i;
					}
				}
				if(a<0){
					a=-a;
					b=-b;
				}
				cout<<b<<"/"<<a<<endl;
			}
		}
		else{
			if(b%a!=0){
				r=a;
				for(int i=2;i<=b;++i){
					while(b%i==0&&a%i==0){
						b/=i;
						a/=i;
					}
				}
				if(a<0){
					a=-a;
					b=-b;
				}
			}
			int w=1;
			for(int i=2;i*i<del;++i){
				while(del%(i*i)==0){
					w*=i;
					del/=i*i;
				}
			}
			if(b==0){}
			else if(b%a==0){
				cout<<b/a<<"+";
			}
			else{
				cout<<-b<<"/"<<a<<"+";
			}
			if(a==w){
				cout<<"sqrt("<<del<<")"<<endl;
			}
			else if(a%w==0){
				a/=w;
				cout<<"sqrt("<<del<<")/"<<a<<endl;
			}
			else if(w%a==0){
				w/=a;
				cout<<w<<"*"<<"sqrt("<<del<<")"<<endl;
			}
			else{
				for(int i=2;i<=w;++i){
					while(a%i==0&&w%i==0){
						a/=i;
						w/=i;
					}
				}
				cout<<w<<"*"<<"sqrt("<<del<<")/"<<a<<endl;
			}
		}
	}
	
	
	return 0;
}
