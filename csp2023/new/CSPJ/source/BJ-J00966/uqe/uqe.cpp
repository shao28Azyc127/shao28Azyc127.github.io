#include<iostream>
#include<cmath>
using namespace std;
void work(double x){
	if(x==x-int(x*1)){
		cout<<x;
		return;
	}
	else{
		if(x>0){
			for(int i=1;i<=1000000;i++){
				for(int j=1;j<=1000;j++){
					if((i*1.0/j)-x<=0.00001){
						cout<<i<<"/"<<j<<endl;
						return;
					}
				}
			}
		}
		else{
			for(int i=-1000000;i<=-1;i++){
				for(int j=1;j<=1000;j++){
					if((i*1.0/j)-x<=0.00001){
						cout<<i<<"/"<<j<<endl;
						return;
					}
				}
			}
		}
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	double T,M,a,b,c;
	cin>>T>>M;
	while(T--){
		cin>>a>>b>>c;
		double x,y;
		if(b*b-4*a*c<0){
			cout<<"NO"<<endl;
			continue;
		}
		x=-1*b+sqrt(b*b-4*a*c)/-2*a;
		y=-1*b-sqrt(b*b-4*a*c)/-2*a;
		if(y>=x){
			swap(x,y);
		}
		work(x);
	}
	return 0;
}