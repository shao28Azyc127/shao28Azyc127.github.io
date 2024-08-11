#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int NR=1e5+10;

int a[NR];

int ct(char c){
	if(c=='T')return 1;
	if(c=='F')return 0;
	if(c=='U')return 2;
	return -1;
}

bool flag[NR];

int fs(int x){
	//cout << x << " " << a[x] << endl;
	if(a[x]==0||a[x]==-1||flag[a[x]])return x;
	flag[x]=true;
	a[x]=fs(a[x]);
	flag[x]=false;
	return a[x];
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	int C,T;
	cin >> C >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		if(C==1){

		}
		if(C==2){

		}
		if(C==3||C==4){
			for(int i=1;i<=n;i++){
				a[i]=-1;
			}
			for(int i=1;i<=m;i++){
				char op;
				cin >> op;
				int x;
				cin >> x;
				a[x]=ct(op);
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2)ans++;
			}
			cout << ans << endl;
		}
		if(C==5||C==6){
			for(int i=1;i<=n;i++){
				a[i]=-1;
			}
			for(int i=1;i<=m;i++){
				char op;
				cin >> op;
				if(op=='+'){
					int x,y;
					cin >> x >> y;
					if(a[y]==0)a[x]=0;
					else a[x]=fs(y);
				}
				if(op=='U'){
					int x;
					cin >> x;
					a[x]=0;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0||a[fs(i)]==0)ans++;
			}
			cout << ans << endl;
		}
	}
}