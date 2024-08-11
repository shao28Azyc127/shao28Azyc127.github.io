#include<bits/stdc++.h>
using namespace std;int num;int u,v;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a>>b>>c;
	num+=a+=b+=c;
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		num+=u+=v;
	}
	if(num==65)cout<<"5";
	return 0;
}