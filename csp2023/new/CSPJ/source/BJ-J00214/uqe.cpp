#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

int gcd(int a,int b) {return (a%b==0?b:gcd(b,a%b));}

pii spl(int d)
{
	int r=1;
	for(int i=min(2500,d);i>=2;i--)
		if(d%(i*i)==0) {r=i; break;}
	d=d/r/r;
	return make_pair(r,d);
}

void p1(int a,int b)
{
	if(a==0) {cout<<"0"; return ;}
	int neg=(a*b<0?-1:1);
	a=(a<0?-a:a);
	b=(b<0?-b:b);
	int g=gcd(a,b);
	a/=g; b/=g;
	if(neg==-1) cout<<'-';
	if(b==1) cout<<a;
	else cout<<a<<'/'<<b;
}

void p2(pii d,int a)
{
	int g=gcd(a,d.first);
	a/=g; d.first/=g;
	if(d.first!=1) cout<<d.first<<"*";
	cout<<"sqrt("<<d.second<<")";
	if(a!=1) cout<<"/"<<a;
}

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T;
	cin>>T;
	int M;
	cin>>M;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0) {a=-a; b=-b; c=-c;}
		int D=b*b-4*a*c;
		if(D<0) {cout<<"NO\n"; continue;}
		if(D==0) {p1(-b,a+a); cout<<endl; continue;}
		pii d=spl(D);
//		cout<<d.first<<' '<<d.second<<endl;
		if(d.second==1) {p1(-b+d.first,a+a); cout<<endl; continue;}
		if(b!=0) {p1(-b,a+a); cout<<'+'; p2(d,a+a); cout<<endl; continue;}
		else {p2(d,a+a); cout<<endl; continue;}
	}
	return 0;
}
