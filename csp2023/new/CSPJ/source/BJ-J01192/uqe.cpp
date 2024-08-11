#include<bits/stdc++.h>
using namespace std;

int T,M;

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	for(int i=1;i<=T;i++){
		int a,b,c;
		char x;
		cin>>a>>b>>c;
		if(M==1)cout<<0;
		else if((b*b-4*a*c)<0)cout<<"NO";
		else if(b*b-4*a*c==0){
			x=-b/(2*a);
			cout<<x;
		}
		else{
			x=(-b+sqrt(b*b-4*a*c))/2*a;
			cout<<x;
		}
	}
	return 0;
}
