#include<iostream>
using namespace std;
int gcd(int x,int y){
	if(y==0)	return x;
	return gcd(y,x%y);
}
int mx(int x){
	if(x==0)	return 1;
	int ret=0;
	for(int i=1;i*i<=x;i++)
		if(x%(i*i)==0)	ret=i;
	return ret;
}
void prt(int b,int a,int sq){
	b*=mx(sq);
	sq/=mx(sq)*mx(sq);
	int fu=1;
	if(a<0)	fu*=-1,a=-a;
	if(b<0)	fu*=-1,b=-b;
	int ab=gcd(a,b);
	a/=ab;
	b/=ab;
	if(fu==-1)	cout<<'-';
	if(sq!=0){
		if(b!=1) cout<<b<<'*';
		cout<<"sqrt("<<sq<<')';
	}
	else	cout<<b;
	if(a!=1)	cout<<'/'<<a;
}
void solve(int a,int b,int c){
	int dt=b*b-4*a*c;
	if(dt<0){
		cout<<"NO"<<endl;
		return;
	}
	if(dt==0){
		prt(-b,2*a,0);
		cout<<endl;
		return;
	}
	if(dt>0){
		if(mx(dt)*mx(dt)==dt){
			if(a>0)	b=-b+mx(dt);
			if(a<0)	b=-b-mx(dt);
			prt(b,2*a,0);
			cout<<endl;
			return;
		}
		if(b!=0){
			prt(-b,2*a,0);
			cout<<'+';
		}
		a=max(a,-a);
		b=max(b,-b);
		prt(1,2*a,dt);
		cout<<endl;
		return;
	}
	return;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		solve(a,b,c);
	}
	return 0;
}