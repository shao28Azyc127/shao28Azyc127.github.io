#include <bits/stdc++.h>
using namespace std;
#define po a1.o()

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

class fab{
public:
	void yf(){
		int g = gcd(p,q);
		p=p/g,q=q/g;
		if(q<0) q=-q,p=-p;
	}
	fab(int _p,int _q){p=_p,q=_q;yf();}
	pair<int,int> o(){
		return make_pair(p,q);
	}
	double z(){
		return 1.0*p/q;
	}

private:
	int p,q;
};

bool isq(int x){
	int t=sqrt(x);
	return t*t==x;
}

void op(fab a1){
	if(po.second==1) printf("%d",po.first);
	else printf("%d/%d",po.first,po.second);
}


pair<int,int> change(int a1){
	int a2=1;
	for(int i=2;i<=sqrt(a1);i++){
		while(a1&&a1%(i*i)==0) a2*=i,a1/=i*i;
	}
	return make_pair(a2,a1);
}

bool isz(double x){
	return double(int(x))==x;
}

void solve(){
	bool flag=0;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int dt=b*b-4*a*c;
	if(dt<0) printf("NO");
	else if(dt==0){
		fab a1(-b,2*a);
		op(a1);
	}else{
		fab a1(-b+sqrt(dt),2*a);
		fab a2(-b-sqrt(dt),2*a);
		if(a2.z()>a1.z()) a1=a2,flag=1;
		if(isq(dt)) op(a1);
		else{
			fab a3(-b,2*a);
			if(a3.z()!=0){op(a3);putchar('+');}
			auto x = change(dt);
			
			fab b1(-x.first,2*a);
			fab b2(x.first,2*a);
			if(!flag) b1=b2;

			if(b1.z()==1) printf("sqrt(%d)",x.second);
			else if(isz(b1.z())) printf("%d*sqrt(%d)",(int)b1.z(),x.second);
			else if(b1.o().first==1) printf("sqrt(%d)/%d",x.second,b1.o().second);
			else printf("%d*sqrt(%d)/%d",b1.o().first,x.second,b1.o().second);
		}
	}
	puts("");
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	scanf("%d%d",&T,&M);
	while(T--) solve();
	return 0;
}