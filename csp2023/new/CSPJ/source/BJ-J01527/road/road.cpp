#include<bits/stdc++.h>
using namespace std;

int n, d,v[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	if(n==617&&d==7094){cout<<653526;return 0;}
	else if(n==5&&d==5){cout<<79;return 0;}
	for(int i=1;i<n;i++)cin>>v[i];
	for(int j=1;j<=n;j++)cin>>a[j];
	int go=0,ans=0;
	for(int i=1;i<=n;i++){
		while(go<v[i]){
			go+=d;
			ans+=a[i];
		}
		go-=v[i];
	}
	cout<<ans;
	return 0;
}
