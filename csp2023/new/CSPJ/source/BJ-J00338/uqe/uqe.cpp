#include<bits/stdc++.h>
using namespace std;
int a,b,c,vis[100000],s[1000];
int n,t;
int com(int q,int w){
	if(w==0){
		return q;
	}
	else{
		return com(w,q%w);
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>n>>t;
	int g=1;
	for(int i=2;i<=t;i++){
		if(vis[i]==1) continue;
		else{
			s[g]=i;
			g++;
		}
		for(int j=i;i*j<=t;j++){
			vis[i*j]=1;
		}
	}
	while(n--){
		cin>>a>>b>>c;
		int h=b*b-4*a*c;

		if(h<0){
			cout<<"NO"<<endl;
		}
		else{
			if(h==floor(sqrt(h))*floor(sqrt(h))){
				double y=(sqrt(h)-b)*1.0/(2*a)*1.0;
				if(y==(int)y){
					cout<<y<<endl;
				}
				else{
					int o=sqrt(h)-b;
					int u=1;
					if(o<0 ){
						u*=-1;
						o*=-1;
					}
					int p=2*a;
					if(p<0 ){
						u*=-1;
						p*=-1;
					}
					int l=com(max(o,p),min(o,p));
					cout<<u*o/l<<"/"<<p/l<<endl;
				}
			}
			else{
				if(b==0){
				}
				else if((-1*b)%(2*a)==0){
					cout<<(-1*b)/(2*a);
				}
				else{
					int o=-1*b;
					int u=1;
					if(o<0 ){
						u*=-1;
						o*=-1;
					}
					int p=2*a;
					if(p<0 ){
						u*=-1;
						p*=-1;
					}
					int l=com(max(o,p),min(o,p));
					cout<<u*o/l<<"/"<<p/l;
				}
				
					int z=1;
					for(int i=1;i<=h;i++){
						int j=0;
						while(h%s[i]==0){
							h/=s[i];
							j++;
						}
						z*=pow(s[i],j/2);
						for(int k=1;k<=j%2;k++){
							h*=s[i];
						}
					}
					int p=2*a;
					if(b==0 && p>0){
					}
					else if(p>0){
						cout<<"+";
					}
					else{
						cout<<"-";
					}

						int u=1;
						if(p<0){
							p*=-1;
							u=-1;
						}
						int l=com(max(z,p),min(z,p));
						if(u==1){
							if(z==p){
								cout<<"sqrt("<<h<<")"<<endl;
							}
							else if(z==l){
								cout<<"sqrt("<<h<<")"<<"/"<<p/l<<endl;
							}
							else if(p==l){
								cout<<z/l<<"*"<<"sqrt("<<h<<")"<<endl;
							}
							else{
								cout<<z/l<<"*"<<"sqrt("<<h<<")"<<"/"<<p/l<<endl;
							}

							
						}
						else{
							if(z==p){
								cout<<"sqrt("<<h<<")"<<endl;
							}
							else if(z==l){
								cout<<"sqrt("<<h<<")"<<"/"<<p/l<<endl;
							}
							else if(p==l){
								cout<<z/l<<"*"<<"sqrt("<<h<<")"<<endl;
							}
							else{
								cout<<z/l<<"*"<<"sqrt("<<h<<")"<<"/"<<p/l<<endl;
							}

						}
	

			}
		}
	}
	return 0;
}
