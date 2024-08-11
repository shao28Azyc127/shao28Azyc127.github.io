#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL N = 2005;
const LL M = 2005;

LL C,T;
LL n,m,k,d;

LL f[N][N];

struct node{
	LL len,val;
};

vector<node> a[N];

void ckmax(LL& xx,LL yy){
	if(xx < yy)
		xx = yy;
}

LL check(int xx,int len){
	LL res = 0;
	for(int i = 0;i < (int)a[xx].size();i++){
		if(len >= a[xx][i].len)
			res += max(0ll,a[xx][i].val);
	}
	return res;
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> T;
	while(T--){
		cin >> n >> m >> k >> d;
		//~ cerr << n << " " << m << " " << "\n";
		for(int i = 1;i <= n;i++){
			vector<node>().swap(a[i]);
		}
		for(int i = 1;i <= m;i++){
			int xx,tlen,tval;
			cin >> xx >> tlen >> tval;
			a[xx].push_back({tlen,tval});
		}
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= min((LL)i,k);j++){
				f[i][j] = -1e18;
			}
		}
		f[0][0] = 0;
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= min((LL)i,k);j++){
				ckmax(f[i+1][0],f[i][j] + check(i+1,0));
				if(j+1 <= k)
					ckmax(f[i+1][j+1],f[i][j] + check(i+1,j+1)-d);
			}
		}
		//~ for(int i = 0;i <= n;i++){
			//~ for(int j = 0;j <= min((LL)i,k);j++){
				//~ cerr << f[i][j] << " ";
			//~ }
			//~ cerr << "\n";
		//~ }
		//~ cerr << "\n";
		LL ans = 0;
		for(int j = 0;j <= k;j++){
			ckmax(ans,f[n][j]);
		}
		cout << ans << "\n";
	}
	return 0;
}
