#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],u[N],v[N],cnt[N];
bool f[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
	}
	ans=n;
	bool flag=true;
	while(true){
		for(int i=1;i<=n;i++){
			cnt[i]=max(b[i]+ans*c[i],1);
			if(a[i]<=cnt[i]){
				f[i]=true;
			}
		}
		for(int i=1;i<=n;i++){
			if(!f[i]){
				break;
			}
			if(i==n){
				flag=false;
				break;
			}
		}
		ans++;
		if(!flag){
			break;
		}
	}
	cout<<ans;
	return 0;
}
