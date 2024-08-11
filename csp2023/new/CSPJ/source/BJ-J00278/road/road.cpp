#include<bits/stdc++.h>
using namespace std;
int v[100000],a[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,m;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(v[i]%d==0){
			m+=(v[i]/d)*a[i];
		}else{
			m+=(v[i]/d+1)*a[i];
		}
	}
	cout<<m;
	return 0;
}
