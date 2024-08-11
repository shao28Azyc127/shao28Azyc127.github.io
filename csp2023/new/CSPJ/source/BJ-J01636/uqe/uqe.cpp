#include<bits/stdc++.h>
using namespace std;
int t,m;
double a,b,c,x;
int main(){
	freopen("que.in","r",stdin);
	freopen("que.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		int dlt=pow(b,2)-4*a*c;
		if(dlt<0){
			cout<<"NO"<<endl;
			continue;
		}
		x=(b*-1+sqrt(dlt))/2*a;
		cout<<x<<endl;
	}
	return 0;
}