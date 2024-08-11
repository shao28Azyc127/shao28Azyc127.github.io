#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c;
inline int solve(int x){
	int ans=1;
	for(int i=2;i<=5000;i++){
		while(x%(i*i)==0) ans*=i,x/=(i*i);
	}
	return ans;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T>>M;
	while(T--){
		cin>>a>>b>>c;
		if(b*b-4*a*c<0){
			cout<<"NO\n";
			continue;
		}
		int sq=(int)sqrt(b*b-4*a*c);
		if(sq*sq==b*b-4*a*c){
			int mother,son;
			mother=2*a;
			if(mother<0) son=-b-sq;
			else son=-b+sq;
			int gcd=abs(__gcd(mother,son));
			mother/=gcd,son/=gcd;
			if(mother==1 || mother==-1) cout<<son/mother<<'\n';
			else if(son==0) cout<<0<<'\n';
			else{
				if(mother>0 && son>0) cout<<son<<'/'<<mother<<'\n';
				else if(mother<0 && son<0) cout<<-son<<'/'<<-mother<<'\n';
				else if(son<0) cout<<son<<'/'<<mother<<'\n';
				else cout<<-son<<'/'<<-mother<<'\n';
			}
		}else{
			int mother=2*a,son=-b,o=-1;
			int tm=solve(b*b-4*a*c),inside=(b*b-4*a*c)/tm/tm;
			int gcd=abs(__gcd(mother,son));
			mother/=gcd,son/=gcd;
			if(son==0) o=114514;
			else if(mother==1 || mother==-1) cout<<son/mother;
			else{
				if(mother>0 && son>0) cout<<son<<'/'<<mother;
				else if(mother<0 && son<0) cout<<-son<<'/'<<-mother;
				else if(son<0) cout<<son<<'/'<<mother;
				else cout<<-son<<'/'<<-mother;
			}
			mother=2*a;
			gcd=abs(__gcd(tm,mother));
			tm/=gcd,mother/=gcd;
			if(o==-1) cout<<"+";
			tm=(tm<0)?-tm:tm; mother=(mother<0)?-mother:mother;
			if(tm!=1 && tm!=-1){
				if(mother==1 || mother==-1) cout<<tm<<"*"<<"sqrt("<<inside<<")"<<'\n';
				else{
					cout<<tm<<"*"<<"sqrt("<<inside<<")/"<<mother<<'\n';
				}
			}else{
				if(mother==1 || mother==-1) cout<<"sqrt("<<inside<<")"<<'\n';
				else{
					cout<<"sqrt("<<inside<<")/"<<mother<<'\n';
				}
			}
		}
	}
	return 0;
}