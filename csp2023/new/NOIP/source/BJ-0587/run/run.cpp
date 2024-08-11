#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,a[100005];
ll n,m,k,d;
struct r{
	int y=0,v=0;
}x[100005];
ll maxn=0;
void run(ll deep,ll num,ll t){
	if(deep>n){
		maxn=max(num,maxn);
		return;
	}
	if(t<k){
		if(x[deep].y<=t+2 && x[deep].y!=0){
			run(deep+1,num-d+x[deep+1].v,t+1);
		}else run(deep+1,num-d,t+1);
	}
	run(deep+1,num,0);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>m>>k>>d;
		for(int j = 1;j <= m;j++){
			int xi,yi,vi;
			cin>>xi>>yi>>vi;
			x[xi].y=yi;x[xi].v=vi;
		}
		run(0,0,0);
		cout<<maxn<<endl;maxn=0;
		for(int j = 1;j <= n;j++){
			x[j].y=0;x[j].v=0;
		}
	}
	return 0;
}
