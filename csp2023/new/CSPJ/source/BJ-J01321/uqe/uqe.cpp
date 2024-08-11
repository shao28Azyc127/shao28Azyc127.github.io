#include <bits/stdc++.h>
using namespace std;
long long t,m,derta;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=0;i<t;i++){
		long long x1,x2;
		long long a,b,c;
		cin>>a>>b>>c;
		derta=b*b-4*a*c;
		x1=(0-b + derta)/2/a;
		x2=(0-b - derta)/2/a;
		if(x1>x2) cout<<x1;
		else cout<<x2;
	}
	return 0;
}