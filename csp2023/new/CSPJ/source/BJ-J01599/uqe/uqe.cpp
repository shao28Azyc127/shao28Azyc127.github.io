#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("uqe.in","r",stdin);
freopen("uqe.out","w",stdout);
int t,m,a,b,c,s;
cin>>t>>m;
for(int i=0;i<t;i++){
	cin>>a>>b>>c;
	s=b*b-4*a*c;
	if(s<0){cout<<"NO"<<endl;continue;}
	else{
		double d=sqrt(s);
		int ans=max((-b+d)/2/a,(-b-d)/2/a);
		cout<<ans<<endl;
	}
}
return 0;
}