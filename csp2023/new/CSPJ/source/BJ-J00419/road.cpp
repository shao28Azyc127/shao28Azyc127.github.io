#include<bits/stdc++.h>
using namespace std;
int n,d;
int x,f,m;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>x;
		f+=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		if(i==1) m=x;
	}
	if(f%d==0) x=f/d;
	else x=f/d+1;
	cout<<m*x;
	return 0;
}
