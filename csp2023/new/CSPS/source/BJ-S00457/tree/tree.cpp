#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=1e6+1;
int a[N],b[N],c[N],u,v,f[N],ans=0;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>b[i]>>c[i];
		if(a[i]%b[i]==0){
			f[i]=a[i]/b[i];
		}
		else{
			f[i]=a[i]/b[i];
			f[i]++;
		}
	}
	for(int i=1;i<n;i++){
		cin >>v>>u;
	}
	f[1]++;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
