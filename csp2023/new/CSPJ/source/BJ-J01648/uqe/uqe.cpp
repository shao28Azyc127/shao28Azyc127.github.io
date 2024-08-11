#include<bits/stdc++.h>
using namespace std;
long long t,m,a,b,c;
int main(){
	//freopen("uqe.in","r",stdin);
	//freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		double z;
		z=1.0*b*b-4*a*c;
		if(b==0){
			cout<<"NO"<<endl;
			continue;
		}
		if(z<0){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			double x=(-b*1.0+sqrt(z))/(2.0*a);
			double y=(-b*1.0-sqrt(z))/(2.0*a);
			if(y>x)x=y;
				if(x==(int)x){
				for(int q=1;q<=1000;q++){
					int p=x*q;
					for(int j=1000;j>=1;j--){
						if(a%j==0&&b%j==0){
						break;
						}
					}
					if(j==0){
						if(q==1){
							cout<<p<<endl;
							break;
						}else{
							cout<<p<<"/"<<q<<endl;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
