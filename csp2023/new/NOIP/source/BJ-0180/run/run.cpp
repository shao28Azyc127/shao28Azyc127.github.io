#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int NR=1e5+10;

int x[NR],y[NR],v[NR];
bool a[30];
long long ansx=0;

int n,m,k,d;

//last上一次不跑步
void dfs(int step,int last,long long sum){
	if(step>n){
		long long ans=0;
		//for(int i=1;i<=n;i++)cout << a[i] << " ";
		//cout << endl;
		for(int i=1;i<=m;i++){
			bool check=true;
			//cout << x[i] << " " << y[i] << endl;
			for(int j=x[i]-y[i]+1;j<=x[i];j++){
				if(a[j]==false){
					check=false;
					break;
				}
			}
			if(check)ans+=v[i];
		}
		ansx=max(ans-sum,ansx);
		return;

	}
	if(step-(last+1)+1<=k){
		a[step]=true;
		dfs(step+1,last,sum+d);
	}
	a[step]=false;
	dfs(step+1,step,sum);
	
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		if(c==1||c==2){
			long long ans=0;
			for(int i=1;i<=m;i++){
				cin >> x[i] >> y[i] >> v[i];
			}
			dfs(1,0,0);
			cout << ansx << endl;
		}
	}
}