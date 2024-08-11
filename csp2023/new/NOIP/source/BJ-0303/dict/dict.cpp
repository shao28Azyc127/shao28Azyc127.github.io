#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
void fre(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
const int maxn=3005;
string s[maxn],t[maxn];
int vis[maxn][30],pre[maxn][30],suf[maxn][30],pos[maxn][maxn];
bool check(int x,int y){
	int l=1,r=0;
	F(i,1,26){
		l=pre[x][i-1]+1,r=pre[x][i];
		if(l>r) continue;
		if(pos[y][l]>i||pos[y][r]>i) return 0;
	}
	return 1;
}
signed main(){
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	F(i,1,n) cin>>s[i];
	F(i,1,n) t[i]=s[i];
	F(i,1,n) sort(t[i].begin(),t[i].end()),reverse(t[i].begin(),t[i].end());
	F(i,1,n) s[i]=" "+s[i];
	F(i,1,n) F(j,1,m) vis[i][s[i][j]-'a'+1]++;
	F(i,1,n){
		F(j,1,26) pre[i][j]=pre[i][j-1]+vis[i][j];
		F(j,1,26) suf[i][j]=suf[i][j+1]+vis[i][j];
	}
	F(i,1,n) dF(j,m-1,0) pos[i][j+1]=t[i][j]-'a'+1;
	F(i,1,n){
		bool fl=1;
		F(j,1,n)
			if(check(i,j)){
				fl=0;
				break;
			}
		if(fl) cout<<1;
		else cout<<0;
	}
}
