#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define FileIO(f) freopen(f".in","r",stdin),freopen(f".out","w",stdout)
const int N=2e6+5;
int n,la[N][30];
ll ans[N];
char s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FileIO("game");
	int i,j,p;
	memset(la,-1,sizeof(la));
	memset(ans,0,sizeof(ans));
	cin>>n>>(s+1);
	for(i=2;i<=n;i++){
		la[i][s[i]-'a']=i;
		p=la[i-1][s[i]-'a'];
		if(p!=-1&&p!=1){
			for(j=0;j<26;j++){
				if(j==s[i]-'a')continue;
				la[i][j]=la[p-1][j];
			}
		}
		if(p!=-1){
			ans[i]=1;
			if(p!=1)ans[i]+=ans[p-1];
		}
	}
	cout<<ans[n];
	return 0;
}