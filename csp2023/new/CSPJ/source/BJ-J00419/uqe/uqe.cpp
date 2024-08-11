#include<bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c;

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		int z=b*b-4*a*c;
		if(z<0){cout<<"NO\n";continue;}
		int x=(-b+sqrt(z))/(2*a);
		cout<<x<<"\n";
	}
	return 0;
}

