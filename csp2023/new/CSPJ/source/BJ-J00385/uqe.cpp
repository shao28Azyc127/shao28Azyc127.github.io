#include<bits/stdc++.h>
using namespace std;
int t,m;
double p;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		p=b*b-4*a*c;
		if(p<0)cout<<"NO"<<endl;
		else{
			double x=(p-b)/(2*a);
			double y=(0-p-b)/(2*a);
			if(x>=y){
				if(x>=0)cout<<x<<endl;
				else cout<<"-1/"<<1/(0-x)<<endl;
			}
			else{
				if(y>=0)cout<<y<<endl;
				else cout<<"-1/"<<1/(0-y)<<endl;
			}
		}
	}
	return 0;
}