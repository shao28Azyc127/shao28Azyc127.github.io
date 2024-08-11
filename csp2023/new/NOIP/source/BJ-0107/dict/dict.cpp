#include<bits/stdc++.h>
#define ffor(i,l,r) for(int i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(int i=(l),i##_end=(r);i>=i##_end;i--)
using namespace std;
using ll = long long;
const int MOD = 1000003577,BASE = 131;
int n,m;
string w[3010],rw[3010];
int ttord[3010];
int hsh[3010][3010];
int pw[3010];
bool ans[3010];
void runHash(){
	pw[0] = 1;
	ffor(i,1,m) pw[i] = 1ll*pw[i-1]*BASE%MOD;
	ffor(i,1,n){
		hsh[i][0] = 0;
		ffor(j,1,m){
			hsh[i][j] = (1ll*hsh[i][j-1]*BASE+rw[i][j]-'a'+1)%MOD;
		}
	}
}
int query(int i,int l,int r){
	return ((hsh[i][r]-1ll*hsh[i][l-1]*pw[r-l+1]%MOD)%MOD+MOD)%MOD;
}
bool compare(int a,int b){
	int l = 1,r = m,ret  = 0;
	while(l<=r){
		int mid = (l+r)>>1;
		if(query(a,1,mid)==query(b,1,mid)){
			ret = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	if(ret==m) return 0;
	return rw[a][ret+1]<rw[b][ret+1];
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<"1";
		return 0;
	}
	ffor(i,1,n){
		cin>>w[i];
		w[i] = ' '+w[i];
		rw[i] = w[i];
	}
	ffor(i,1,n){
		sort(rw[i].begin()+1,rw[i].end(),greater<char>());
		ttord[i] = i;
	}
	runHash();
	sort(ttord+1,ttord+n+1,compare);
	// ffor(i,1,n){
	// 	cout<<rw[ttord[i]]<<"\n";
	// }
	ffor(i,1,n){
		sort(w[i].begin()+1,w[i].end());
		int c = ttord[1];
		if(c==i) c= ttord[2];//n==1!!!!!
		ffor(j,1,m){
			if(w[i][j]<rw[c][j]){
				ans[i] = true;
				break;
			}
		}
	}
	ffor(i,1,n){
		if(ans[i])cout<<"1";
		else cout<<"0";
	}
	return 0;
}