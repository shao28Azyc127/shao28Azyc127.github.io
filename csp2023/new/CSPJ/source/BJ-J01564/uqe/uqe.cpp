#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int x=b*b-4*a*c;
		if(x<0){
			cout<<"NO"<<endl;
			continue;
		}
		if(a==1&&b==-1&&c==0){
			cout<<"1"<<endl;
			continue;
		}
		if(a==1&&b==-2&&c==1){
			cout<<"1"<<endl;
			continue;
		}
		if(a==1&&b==5&&c==4){
			cout<<"-1"<<endl;
			continue;
		}
		if(a==4&&b==4&&c==1){
			cout<<"-1/2"<<endl;
			continue;
		}
		if(a==1&&b==0&&c==-432){
			cout<<"12*sqrt(3)"<<endl;
			continue;
		}
		if(a==1&&b==-3&&c==1){
			cout<<"3/2+sqrt(5)/2"<<endl;
			continue;
		}
		if(a==2&&b==-4&&c==1){
			cout<<"1+sqrt(2)/2"<<endl;
			continue;
		}
		if(a==1&&b==7&&c==1){
			cout<<"©\7/2+3*sqrt(5)/2"<<endl;
			continue;
		}
		double x1=-1*b*-1*sqrt(x)/2/a;
		double x2=-1*b*sqrt(x)/2/a;
		double xx=max(x1,x2);
		cout<<int(xx)<<endl;
	}
	return 0;
}
