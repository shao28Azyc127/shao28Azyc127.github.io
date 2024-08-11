#include<bits/stdc++.h>
using namespace std;
long long y=1,n,m,a,b,c,d,e=1,ans,l=0;
long long r(long long b){
	e=1;
	for(long long i=1;i*i<=b;i++){
		if((b/e)%(i*i)==0){
			e*=i*i;
		}
	}
	return e;
}
long long p(long a,long b){
	e=1;
	for(long long i=1;i<=min(a,b);i++){
		if(a%i==0&&b%i==0){
			e=i;
		}
	}
	return e;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);	
	cin>>n>>m;
	while(n--){
		cin>>a>>b>>c;
		d=b*b-4*a*c;
		if(d<0){
			cout<<"NO"<<endl;
			continue;
		}else{
			ans=r(d);
			if(d==0){
				if(-b%(2*a)==0){
					cout<<-b/(2*a)<<endl;
					continue;
				}else{
					if((2*a)%-b==0){
						y=p(abs(2*a),abs(-b));
						cout<<-b/y<<"/"<<2*a/y<<endl;
						continue;
					}
					cout<<-b<<"/"<<(2*a)<<endl;
					continue;
				}
			}
			if(d/ans==1){
				l=sqrt(ans);
				if((l-b)%(2*a)==0){
					cout<<(l-b)/(2*a)<<endl;
					continue;
				}else{
					cout<<(l-b)<<"/"<<(2*a)<<endl;
				}
			}else{
				if(2*a==1){
					d/=ans;
					cout<<-b<<"+"<<ans<<"*"<<"sqrt("<<d<<")"<<endl;
					continue;
				}else{
					d/=ans;
					if(b==0){
						cout<<ans<<"*"<<"sqrt("<<d<<")"<<endl;
					}else{
						cout<<-b<<"/"<<(2*a)<<"+"<<ans<<"*"<<"sqrt("<<d<<")"<<"/"<<2*a;
					}
					continue;
				}
			}
		}
	}
	return 0;
}