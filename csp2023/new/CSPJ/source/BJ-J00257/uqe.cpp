//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define WA cerr<<"QWQ\n"
#define INF 0x3f3f3f3f
#define H cout<<"\n"
#define C continue
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(b);i>=(a);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b);i>(a);i--)
#define MAXN 200019
#define ull unsigned long long
#define db double
#define S(__) cout<<"sqrt("<<__<<")"
#define N cout<<"NO\n"
int m;
int yu;
int yf(int x)
{
	int xx=x;
	int rt=1;
	For(i,2,sqrt(x)+1)
	{
		if(xx==1) break;
		while(xx%(i*i)==0) xx/=(i*i),rt*=i;
	}
	return rt;
}
bool cksqrt(int x) { if(x==0) return 1; return yf(x)*yf(x)==x; }
//bool cksqrt(int x) { int f=sqrt(x); return (f*f)==x; }
int gcd(int x,int y) { return (x%y==0)?(y):(gcd(y,x%y)); }
void pr(int p,int q,int qwq=-1)
{
	if(p==0||q==0) { cout<<0; return ; }
	bool f=yu;
	if(p*q<0) f=!f;
	p=abs(p); q=abs(q);
	int g_=gcd(p,q);
	p/=g_; q/=g_;
	if(f) cout<<"-";
	if(qwq!=-1)
	{
		if(p!=1) cout<<p<<"*"; 
		S(qwq); cout<<"/"<<q;
		return ;
	}
	
	if(p%q==0) cout<<p/q;
	else cout<<p<<"/"<<q;
	return ;
}
 main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(15);
	int _; cin>>_>>m;
	while(_--)
	{
/*
1 1000
-2 12 270
*/
		yu=0;
		int a,b,c;
		cin>>a>>b>>c;
		int de=(b*b)-(4*a*c);
		if(de<0) { N; C; }
		if(cksqrt(de)) 
		{
			int hor=sqrt(de);
			if(((hor-b)/a)<((-hor-b)/a)) hor=-hor;
			hor-=b;
			pr(hor,2*a); H;
			C;
		}
		db a1=(sqrt(de)-b)/a,a2=(-sqrt(de)-b)/a;
		int hjl=yf(de);
		de=de/hjl/hjl;
		if(a1<a2) hjl=-hjl;
		//if(hjl<0) { cerr<<hjl<<"\n"; return 0; }
		if(hjl*a<0) 
		{ 
			if(a<0) a=abs(a),yu=1;
			else hjl=abs(hjl);
		} //hjl=abs(hjl);
		if(b!=0) { pr(-b,2*a); cout<<"+"; }
		yu=0;
		if(abs(hjl)%abs(2*a)==0)
		{
			if(hjl==2*a) S(de);
			else { cout<<hjl/2/a<<"*"; S(de); } 
			H; C;
		}
		if(hjl==1)
		{
			S(de); cout<<"/"<<2*a; H; C;
		}
		pr(hjl,2*a,de); H;
	}
	return 0;
}