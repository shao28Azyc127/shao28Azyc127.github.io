#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	int a,b,c,d;
	cin>>t>>m;
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		d=b*b-4*a*c;
		if(d<0) cout<<"NO"<<endl;
		else{
			cout<<(-b+sqrt(d))/(2*a)<<endl;
		}
	}
	return 0;
}
