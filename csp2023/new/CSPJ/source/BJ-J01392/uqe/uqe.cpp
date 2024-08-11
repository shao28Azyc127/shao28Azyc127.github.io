#include<bits/stdc++.h>
using namespace std;

int T,M;

int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int d=b*b-4*a*c;
		if(d<0){
			cout<<"NO"<<endl;
		}
		else if(d==0){
			if((-b+sqrt(d))/(2*a)==-0) cout<<"0"<<endl;
			else cout<<(-b+sqrt(d))/(2*a)<<endl;
		}
		else{
			int x1=(-b+sqrt(d))/(2*a);
			int x2=(-b-sqrt(d))/(2*a);
			if(max(x1,x2)==-0) cout<<"0"<<endl;
			else cout<<max(x1,x2)<<endl;
		}
	}
	return 0;
}
