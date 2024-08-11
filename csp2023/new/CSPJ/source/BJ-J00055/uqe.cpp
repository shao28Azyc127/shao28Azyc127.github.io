#include<bits/stdc++.h>
using namespace std;
int T,M;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int m=b*b-4*a*c;
		if(m<0){
			cout<<"NO"<<endl;
		}else{
			double ssr=(-b+sqrt(m))/1.0/(2*a);
			double tr=(-b-sqrt(m))/1.0/(2*a);
			cout<<max(ssr,tr)<<endl;
		}
	}
	return 0;
}
