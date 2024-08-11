#include<iostream>
#include<cmath>
using namespace std;
int a,b,c;
double d;
int gcd(int a,int b){
	if (b==0)
		return a;
	if (a==1)
		return 1;
	return gcd(b,a%b);
}
void print(){
	int q=sqrt(d);
	int x=abs(-b+q),y=abs(2*a);
	int g=gcd(min(x,y),max(x,y));
	if ((b+q>0)+(2*a<0)==1)
		cout<<'-';
	cout<<x/g;
	if (g==y)
		cout<<endl;
	else
		cout<<"/"<<y/g;
}
bool che(int x){
	if (sqrt(x)==(int)sqrt(x))
		return true;
	return false;
}
int pd(int x){
	int u=sqrt(x);
	int t=1;
	for (int i=2;i<=u;i++){
		while (x%(i*i)==0){
			t*=i;
			x/=(i*i);
		}
	}
	return t;
}
int main(){
//	freopen("road.in","r",stdin);
   // freopen("road.out","w",stdout);
	int n,m;
	cin>>n>>m;
	while (n--){
		cin>>a>>b>>c;
		d=b*b-4*a*c;
		if (d<0){
			cout<<"NO"<<'\n';
			continue;
		}
		else if (d==0){
			int q=sqrt(d);
			int x=abs(-b+q),y=abs(2*a);
			if (x==0){
				cout<<0<<endl;
				continue;
			}
			int g=gcd(min(x,y),max(x,y));
			if ((b+q>0)+(2*a<0)==1)
				cout<<'-';
			cout<<x/g;
			if (g==y)
				cout<<endl;
			else
				cout<<"/"<<y/g;
			continue;
		}
		if (che(d)){
			int q=sqrt(d);
			int x=(a<0)?abs(-b-q):abs(-b+q);
			int y=abs(2*a);
			if (x==0){
				cout<<0<<endl;
				continue;
			}
			int g=gcd(min(x,y),max(x,y));
			if ((a<0 && (-b+q)<0) || (a<0 && (-b-q)>0))
				cout<<"-";
			if ((b+q>0)+(2*a<0)==1)
				cout<<'-';
			cout<<x/g;
			if (g==y)
				cout<<endl;
			else
				cout<<"/"<<y/g;
		}
		else{
			int u=pd(d);
			double q2=1.0/(2.0*a)*sqrt(d)*sqrt(u);
			if (-b/(2.0*a)==int(-b/(2.0*a)) && -b/(2.0*a)!=0)
				cout<<-b/(2.0*a)<<"+";
			if (q2==(int)q2)
				cout<<q2<<"*sqrt("<<u<<")";
			else if (1.0/q2==int(1.0/q2))
				cout<<"sqrt("<<u<<")/"<<q2;
		}
	}
	return 0;
}
