#include<bits/stdc++.h>
using namespace std;
int n,m,mp[10000010],jl[10000010];
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
int mi(int x,int y){
	int mul=1;
	for(int i=1;i<=y;++i) mul*=x;
	return mul;
}
int main(){
	freopen("uqe.in","r",stdin);freopen("uqe.out","w",stdout);
	cin>>n>>m;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		int d=b*b-4*a*c;
		if(d<0) {cout<<"NO\n";continue;}
		int e=sqrt(d);
		//cout<<e<<" "<<d<<"\n";
		if(e*e==d){
			if(e-b||-e-b){
				int eb=abs(e)-b,aa=2*a;
				if(aa<0) eb=abs(e)+b,aa=-aa;
				int g=gcd(abs(eb),aa);
				//cout<<eb<<" "<<aa<<" "<<g<<"\n";
				if(aa/g!=1) cout<<eb/g<<"/"<<aa/g<<"\n";
				else cout<<eb/g<<"\n";
			}
			else cout<<0<<"\n";
			continue;
		}
		if(b){
			int aa=2*a;
			if(aa<0) b=-b,aa=-aa;
			int g=gcd(abs(b),aa);
			if(aa/g!=1) cout<<-b/g<<"/"<<aa/g<<"+";
			else cout<<-b/g<<"+";
		}
		int bf=d,cnt=0,mul=1;
		for(int i=2;i*i<=bf;++i){
			if(bf%i) continue;
			jl[++cnt]=i;
			while(bf%i==0) bf/=i,mp[i]++;
		}
		for(int i=1;i<=cnt;++i){
			mul=mul*mi(jl[i],(mp[jl[i]]/2));
			d/=mi(jl[i],(mp[jl[i]]/2)*2);
			mp[jl[i]]=0;
		}
		//cout<<mul<<"\n";
		if(mul>1){
			int g=gcd(mul,abs(2*a));
			if(mul/g!=1) cout<<mul/g<<"*";
			cout<<"sqrt("<<d<<")";
			if(abs(2*a)/g!=1) cout<<"/"<<abs(2*a)/g;
			cout<<"\n";
		}
		else cout<<"sqrt("<<d<<")/"<<abs(2*a)<<"\n";
	}
	return 0;
}