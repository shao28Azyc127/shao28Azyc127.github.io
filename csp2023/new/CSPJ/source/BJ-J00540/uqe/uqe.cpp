#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(x==y){
		return x;
	}else{
		return gcd(max(x,y)-min(x,y),min(x,y));
	}
}
int pf(int n){
	bool fla=0;
	while(fla){
		for(int i=2;i<=sqrt(n);i++){
			if(n%(i*i)==0){
				n/=i*i;
				break;
			}
			if(i==sqrt(n)){
				fla=!fla;
			}
		}
		if(fla){
			break;
		}
	}
	return n;
}
int qtwo(int n){
	bool flag=0;
	int ans=1;
	while(flag){
		for(int i=2;i<=sqrt(n);i++){
			if(n%(i*i)==0){
				n/=i*i;
				ans*=i;
				break;
			}
			if(i==sqrt(n)){
				flag=!flag;
			}
		}
		if(flag){
			break;
		}
	}
	return ans;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0){
			a=-a;
			b=-b;
			c=-c;
		}
		if(b*b<4*a*c){
			cout<<"NO"<<endl;
		}else if(b*b==4*a*c){
			int x=a,y=b;
			if(x==y){
				cout<<1<<endl;
				continue;
			}else if(x+y==0){
				cout<<"-1"<<endl;
				continue;
			}
			if(y<0){
				y=-y;
				x/=gcd(x,y);
				y/=gcd(x,y);
				cout<<x<<"/"<<y<<endl;
				continue;
			}else if(y==0){
				cout<<0<<endl;
				continue;
			}
			x/=gcd(x,y);
			y/=gcd(x,y);
			cout<<"-"<<x<<"/"<<y<<endl;
		}else{
			if(x==y){
				cout<<1;
			}else if(x+y==0){
				cout<<"-1";
			}else if(b!=0){
				int x=a,y=b;
				if(y<0){
					y=-y;
					x/=gcd(x,y);
					y/=gcd(x,y);
					cout<<x<<"/"<<y<<"+";
				}else{
					x/=gcd(x,y);
					y/=gcd(x,y);
					cout<<"-"<<x<<"/"<<y<<"+";
				}
			}
			if(qtwo(b*b-4*a*c)==1){
				continue;
			}
			int x=a,y=b;
			int cnt=pf(b*b-4*a*c),ans=qtwo(b*b-4*a*c);
		}
	}
	return 0;
}
