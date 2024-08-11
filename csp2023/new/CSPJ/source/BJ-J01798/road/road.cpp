#include<bits/stdc++.h>
using namespace std;
int n,d,ans = 0;
int v[100010],a[100010],cnt = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i = 1;i <= n-1;i++){
		cin>>v[i];
		cnt+=v[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	ans = (cnt/d)*a[1];
	cout<<ans<<endl;
	return 0;
}
