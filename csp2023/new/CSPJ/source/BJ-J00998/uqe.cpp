#include<bits/stdc++.h>
using namespace std;
int delta,n,m,a,b,c;
int gcd(int x,int y){
	if(x==1||y==1)return 1;
	else if(x%y==0||y%x==0)return min(x,y);
	else if(x>y)return gcd(x%y,y);
	else return gcd(x,y%x);
}
int main(){
	freopen("uqe.in","r",stdin);freopen("uqe.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		if(b==0&&c==0){cout<<"0"<<endl;}
		else if(c==0){
			if(a<0&&b<0){
				int g=gcd(-1*a,-1*b);
				a=(-1*a)/g;b=(-1*b)/g;
				if(a==1)cout<<"-"<<b<<endl;
				else cout<<"-"<<b<<"/"<<a<<endl;
			}
			else if(a<0&&b>0){
				int g=gcd(-1*a,b);
				a=(-1*a)/g;b=b/g;
				if(a==1)cout<<b<<endl;
				else cout<<(-1*a)/g<<"/"<<b/g<<endl;
			}
			else if(a>0&&b>0){
				int g=gcd(a,b);
				a=a/g;b=b/g;
				if(a==1)cout<<"-"<<b<<endl;
				else cout<<"-"<<a/g<<"/"<<b/g<<endl;
			}
			else if(a>0&&b<0){
				int g=gcd(a,-1*b);
				a=a/g;b=(-1*b)/g;
				if(a==1)cout<<b<<endl;
				else cout<<a/g<<"/"<<(-1*b)/g<<endl;
			}
		}
		else{
			delta=b*b-4*a*c;
			if(delta==0){
				cout<<(-1*b)/(2*a)<<endl;
			}
			else if(delta>0){
				delta=sqrt(delta);
				int t=((-1*b)+delta)/(2*a);
				cout<<t<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
