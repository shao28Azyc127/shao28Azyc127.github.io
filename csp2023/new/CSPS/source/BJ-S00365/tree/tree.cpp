#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n;
bool flgb=1, flgd=1;
long long a[maxn],b[maxn],c[maxn],d[maxn];
vector<int>m[maxn];
void solve1(){
	long long ans=0;
	for(int i = 1; i <= n; i++){
		ans=max(ans,d[i]+i-1);
	}
	cout << ans <<"\n";
}
void solve2(){
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n-i; j++){
			if(m[1][j]>m[1][j+1]){
				int tmp=m[1][j];
				m[1][j]=m[1][j+1];
				m[1][j+1]=tmp;
			}
		}	
	}
	for(int i = 0; i < m[1].size(); i++){
		ans=max(ans,d[i]+i);
	}
	cout << ans <<"\n";
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
		int tmp=0,cnt=0;
		while(tmp<a[i]){
			cnt++;
			tmp+=max(b[i]+cnt*c[i],(long long)1);
		}
		d[i]=cnt;
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		m[u].push_back(v);
		m[v].push_back(u);
		if(u!=i || v!=i+1){
			flgb=0;
		}
		if(u!=1){
			flgd=0;
		}
	}
	if(flgb==1){
		solve1();
	}
	else if(flgd==1){
		solve2();
	}
	return 0;
}