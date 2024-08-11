#include<iostream>
using namespace std;;

int a[20];
struct que{
	char c; int i, j;
}q[20];
int b[20];

int n,m;

int ans = 1000000;
void solve(){
	for(int i = 1; i<=n; i++){
		b[i] = a[i];
	}
	for(int i = 1; i<=m; i++){
		if(q[i].c == -2){//+
			b[q[i].i] = b[q[i].j];
		}
		else if(q[i].c == -1){
			if(b[q[i].j] == 2) b[q[i].i] = 2;
			else
			b[q[i].i] = !b[q[i].j];
		}
		else b[q[i].i] = q[i].c;
	}
	int cnt = 0;
	for(int i = 1; i<=n; i++){
		if(b[i] != a[i]) return;
		if(b[i] == 2) cnt++;
	}
	ans = min(ans, cnt);
}

void dfs(int d){
	if(d == 10){
		solve();
		return;
	}
	a[d] = 0;
	dfs(d+1);
	a[d] = 1;
	dfs(d+1);
	a[d] = 2;
	dfs(d+1);
	return;
}

int main(){
freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans = 1000000;
		for(int i = 1; i <=m ;i++){
			char c;
			//int k, j;
			cin>>c;
			if(c=='T') {
				c=1;
				cin>>q[i].i;
			}
			else if(c=='F'){
				c=0;
				cin>>q[i].i;
			}
			else if(c=='U'){
				c=2;
				cin>>q[i].i;
			}
			else if(c=='+'){
				c = -2;
				cin>>q[i].i>>q[i].j;
			}
			else{
				c = -1;
				cin>>q[i].i>>q[i].j;
			}
			q[i].c = c;
		}dfs(1);
	cout<<ans<<endl;
	}
	
	return 0;
}
			
