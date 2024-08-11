#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==1) return a;
	if(a==1) return b;
	return gcd(a%b,b);
}
int main(){
	int t,m;
	freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		int a,b,c;
		cin>>a>>b>>c;
		long long ans=b*b-4*a*c;
		if(ans<0){
			cout<<"NO"<<endl;
		}else{
			cout<<(-b+sqrt(ans))/(2*a)<<endl;
		}
	}
	return 0;
}