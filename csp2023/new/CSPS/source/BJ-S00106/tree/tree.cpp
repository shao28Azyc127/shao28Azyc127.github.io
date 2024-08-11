#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
long long a[MAXN],b[MAXN],c[MAXN],u[MAXN],v[MAXN],m[MAXN],f[MAXN],cor,n;
int s;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		m[u[i]]=v[i];
		m[v[i]]=u[i];
	}
	f[1]=0;
	while(cor<n){
		s++;
		for(int i=1;i<=n;i++){
			f[m[i]]=0;
			if(b[i]+s*c[i]>1){
				f[m[i]]+=b[i]+s*c[i]+1;
			}else{
				f[m[i]]++;
			}
			if(f[i]>=a[i]){
				cor++;
			}
		}
	}
	cout<<s;
	return 0;
}
