#include <bits/stdc++.h>
using namespace std;
freopen("uqe.in",'r',stdin);
freopen("uqe.out",'w',stdout);
int t,m,a,b,c;
int main(){
	cin>>t>>m;
	for (int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if (b*b-4*a*c<0){
			cout<<"NO";
			continue;
		}
	}
	return 0;
}
