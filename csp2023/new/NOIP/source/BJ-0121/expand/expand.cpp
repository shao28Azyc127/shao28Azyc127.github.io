#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,a[N],b[N],u[N],v[N];
deque<int> que;
void init(){
	que.clear();
	for(int i=1;i<=n;i++) u[i]=a[i];
	for(int i=1;i<=m;i++) v[i]=b[i];
}
void push(int i,int *x){
	while(!que.empty()&&x[que.back()]<=x[i]) que.pop_back();
	que.push_back(i);
}
bool solve(){
	int *x=&(u[0]),*y=&(v[0]);
	if(x[1]<=y[1]) swap(x,y);
	push(1,x);
	for(int j=1;j<=m;j++){
		int i=que.back();
		if(x[i]>y[j]){
			while(i+1<=n&&x[i+1]>y[j]){
				push(++i,x);
				i=que.back();
			}
		}else{
			while(x[que.back()]<=y[j]){
				que.pop_back();
				if(que.empty()) return 0;
			}
		}
	}
	return que.back()>=n;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);	
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	init();
	cout<<solve();
	while(q--){
		init();
		int kx,ky;cin>>kx>>ky;
		for(int i=1;i<=kx;i++){
			int p,e;cin>>p>>e;
			u[p]=e;
		}
		for(int i=1;i<=ky;i++){
			int p,e;cin>>p>>e;
			v[p]=e;
		}
		cout<<solve();
	}
	return 0;
}