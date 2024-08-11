#include<bits/stdc++.h>
using namespace std;
int a,b,c;
float x1,x2,der;
int find(int x){
	for(int i=1;;i++){
		if(x*i/2/a%1==0) return i;
	}
	
}
int search(int y){
	for(int i=1;i*i<=y;i++){
		if(y%(i*i)==0) return i*search(y/i/i);
	}
	return 1;
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	for(int s=1;s<=T;s++){
		cin>>a>>b>>c;
		der=b*b-4*a*c;
		if(der<0){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			if(sqrt(der)*sqrt(der)==der){
				if(a>0) x1=sqrt(der)-b;
				else x1=-1*sqrt(der)+b;
				int i=find(x1);
				int j=x1*i/2/a;
				if(i==1) cout<<j<<endl;
				else cout<<j<<"/"<<i<<endl;
			}
			else{
				if(b!=0){
					int i=find(-1*b);
					int j=b*-1*i/2/a;
					if(i==1) cout<<j<<"+";
					else cout<<j<<"/"<<i<<"+";
				}
				int y=search(der);
				der=der/y;
				if(y!=1) cout<<y<<"*";
				int z=find(y);
				y=y*z/2/a;
				cout<<y<<"*";
				cout<<"sqrt("<<der<<")";
				if(z!=1) cout<<"/"<<z<<endl;
				else cout<<endl;
			}
		}
	}
}