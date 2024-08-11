#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define pb push_back
#define fi first
#define wh(lzm) while(lzm--)
#define se second
using namespace std;
void fre(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
const int maxn=114514;
int a[maxn],n,m,ans,b[maxn],id,lzm;
namespace subtask{
	int op[maxn],px[maxn],py[maxn];
	void dfs(int i){
		if(i==n){
			F(i,1,n) b[i]=a[i];
			F(i,1,m){
				int posx=px[i],posy=py[i];
				if(op[i]==5) b[posx]=3;
				if(op[i]==4) b[posx]=2;
				if(op[i]==3) b[posx]=1;
				if(op[i]==2){
					if(b[posy]==3) b[posx]=3;
					else if(b[posy]==2) b[posx]=1;
					else if(b[posy]==1) b[posx]=2;
				}
				if(op[i]==1) b[posx]=b[posy];
			}
			F(i,1,n) if(a[i]!=b[i]) return;
			int cnt=0;
			F(i,1,n) if(a[i]==3) ++cnt;
			ans=min(ans,cnt);
			return;
		}
		F(j,1,3){
			a[i+1]=j;
			dfs(i+1);
		}
	}
	void solve1(){
		wh(lzm){
			cin>>n>>m;
			F(i,1,m){
				char tmp;
				cin>>tmp;
				if(tmp=='+'){
					cin>>px[i]>>py[i];
					op[i]=1;
				}
				else if(tmp=='-'){
					cin>>px[i]>>py[i];
					op[i]=2;
				}
				else{
					if(tmp=='T') op[i]=3;
					if(tmp=='F') op[i]=4;
					if(tmp=='U') op[i]=5;
					cin>>px[i];
				}
			}
			ans=1e9;
			dfs(0);
			cout<<ans<<'\n';
		}
	}
}
signed main(){
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>lzm;
	if(id<=2) return subtask::solve1(),0;
	if(id>=3&&id<=4){
		wh(lzm){
			int n,m;
			cin>>n>>m;
			F(i,1,n) a[i]=0;
			F(i,1,m){
				char tmp;
				cin>>tmp;
				int x;
				cin>>x;
				if(tmp=='T') a[x]=1;
				if(tmp=='F') a[x]=2;
				if(tmp=='U') a[x]=3;
			}	
			int ans=0;
			F(i,1,n) if(a[i]==3) ans++;
			cout<<ans<<'\n';
		}
		return 0;
	}
}
