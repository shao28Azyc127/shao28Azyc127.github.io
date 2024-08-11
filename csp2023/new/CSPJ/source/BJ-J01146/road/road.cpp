#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d;
int v[N],a[N];
int f[N];	
int pre_min[N];
int pre_sum[N];
void solve(){
	cin>>n>>d;
	for(int i=2;i<=n;i++){
		cin>>v[i];
		pre_sum[i]=pre_sum[i-1]+v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[pre_min[i-1]]>a[i]){
				pre_min[i]=i;
			}
			else{
				pre_min[i]=pre_min[i-1];
			}
		}
		else pre_min[1]=1;
	}
	cout<<pre_sum[n]/d*a[1];
}
int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		solve();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
