#include<bits/stdc++.h>
using namespace std;
int T,M,a,b,c,td,ea,fb;
bool check[1000100]={};
vector<int> sq;
void getsq() {
	sq.push_back(0);
	sq.push_back(0);
	for(int i=2;i<=1000;i++) {
		check[i*i]=1;
		sq.push_back(i*i);
	}
	return ;
}
void solve() {
	scanf("%d%d%d",&a,&b,&c);
	if(b*b-4*a*c<0) {
		cout<<"NO"<<endl;
		return ;
	}
	td=b*b-4*a*c;
	ea=2*a;
	fb=-1*b;
		bool f=0,fu=0;
		int fr=1;
		for(int i=2;i<=sqrt(sqrt(td)+1)+1;i++) {
			if(sq[i]>td) break;
			while(td%sq[i]==0) {
				td/=sq[i];
				fr*=i;
		}	}
		if(td==1) f=1;
		int x=ea;
		for(int i=2;i<=min(fr,abs(ea));i++) {
			if(i>fr||i>abs(ea)) break;
			while(fr%i==0&&abs(ea)%i==0) {
				fr/=i;
				ea/=i;
		}	}
		for(int i=2;i<=min(abs(x),abs(fb));i++) {
			if(i>abs(x)||i>abs(fb)) break;
			while(abs(x)%i==0&&abs(fb)%i==0) {
				x/=i;
				fb/=i;
		}	}
		if(!fb) fu=1;
		else if(abs(x)==1) {
			if(x==1)cout<<fb;
			else cout<<-1*fb;
		}
		else {
			if(fb*x>0) printf("%d/%d",abs(fb),abs(x));
			else printf("-%d/%d",abs(fb),abs(x));
		}
		if(!td) if(fu) cout<<0<<endl;
		else if(abs(fr)%abs(ea)==0) {
			if(fr==-1*ea) cout<<"-";
			else if(fr!=ea) cout<<fr/ea<<endl;
		}
		else {
			if(fr==1) {}
			else {
				if(td!=1) printf("sqrt(%d)",td);
				else printf("1");
			}
			if(abs(ea)!=1) printf("/%d",abs(ea));
			cout<<endl;
		}
	return ;
}
int main() {
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	getsq();
	scanf("%d%d",&T,&M);
	for(int i=0;i<T;i++) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}