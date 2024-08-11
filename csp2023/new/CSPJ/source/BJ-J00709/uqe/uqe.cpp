#include<bits/stdc++.h>
using namespace std;
const int maxm=10007;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int p[maxm];
void out(int up,int down){
	if(up==0){
				cout<<"0";
				return;
			}
			int g=gcd(up,down);
			up/=g;
			down/=g;
			
			if(up>0&&down<0){
				up*=(-1);
				down*=(-1);
			}
			if(down==1){
				cout<<up;
				return;
			}
			cout<<up<<"/"<<down;
			return;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	for(int i=0;i<maxm;i++){
		//cout<<"1";
		p[i]=i*i;
	}
	//return 0;
	//cout<<"1";
	while(T--){
		long long a,b,c;
		cin>>a>>b>>c;
		long long der=b*b-4*a*c;
		if(der<0){
			cout<<"NO"<<endl;
			continue;
		}
		int d=1;
		for(int i=sqrt(der)+1;i>=2;i--){
			//cout<<"1";
			if(der%p[i]==0){
				d=i;
				der/=p[i];
				break;
			}
		}
		//cout<<"1";
		if(der==0){
			out(-1*b,2*a);
			cout<<endl;
			continue;
		}
		if(der==1){
			//cout<<d;
			if(a>0){
				out((-1*b+d),2*a);
			}else{
				out((-1*b-d),2*a);
			}
			
			cout<<endl;
			continue;
		}
		if(b!=0){
			out(-1*b,2*a);
			cout<<"+";
		}
		if(abs(d)==abs(2*a)){
			cout<<"sqrt("<<der<<")"<<endl;
			continue;
		}
		int up=d,down=2*a;
		int g=gcd(up,down);
		up/=g;
		down/=g;
		if(up<0)up*=(-1);
		if(down<0)down*=(-1);
		if(up==1){
			cout<<"sqrt("<<der<<")/"<<down<<endl;
			continue;
		}
		if(down==1){
			cout<<up<<"*sqrt("<<der<<")"<<endl;
			continue;
		}
		cout<<up<<"*sqrt("<<der<<")/"<<down<<endl;
	}
	return 0;
}