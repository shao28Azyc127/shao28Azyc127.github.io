#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b-4*a*c<0) cout<<"NO"<<endl;
		else{
			int xone=(-b+sqrt(b*b-4*a*c))/2;
			int xtwo=(-b-sqrt(b*b-4*a*c))/2;
			int ans=max(a,b);
			if(ans==xone){
				if(ans%1==0) cout<<ans;
				else cout<<-b<<"+sqrt("<<b*b-4*a*c<<")";
			}
			if(ans==xtwo){
				if(ans%1==0) cout<<ans;
				else cout<<-b<<"-sqrt("<<b*b-4*a*c<<")";
			}
		}
	}
	return 0;
}