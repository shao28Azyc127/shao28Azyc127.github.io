#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int v[1000001],a[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int maxv=0;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		maxv+=v[i];
		
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i];	
	}
	int x;
	if(maxv%d==0){
		x=maxv/d;
	}else{
		x=maxv/d+1;
	}
	cout<<x;
	
	return 0;
}
