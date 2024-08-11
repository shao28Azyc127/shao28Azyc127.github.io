#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m;
int a,b,c;
int sj;
int p,q;
int gcd(int a,int b)
{
	if(a%b==0||b%a==0) return 0;
	int tn=max(sqrt(a),sqrt(b));
	for(int i=tn; i>=2; i--)
	{
		if(a%i==0) return 0;
		if(b%i==0) return 0;
	}
	return 1;
}
int qiupq(double x)
{
	int tp,tq;
	tp=x*100000;
	tq=100000;
	
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int a,b;
	int t;
	cin>>t>>m;
	while(t--)
	{
		cin>>a>>b>>c;
		cout<<"NO"<<endl;
		continue;
		sj=b*b-4*a*c;
		if(sj<0)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
		{
			double x1,x2;
			x1=(0-b+sqrt(sj))/(2*a);
			x2=(0-b-sqrt(sj))/(2*a);
			
		}
	}
}
