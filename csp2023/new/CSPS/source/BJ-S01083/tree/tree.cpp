#include <bits/stdc++.h>
using namespace std;

#define int long long

#define gc getchar
#define pc putchar

inline int read(){
	int x=0; bool f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return f?x:-x;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

const int MAXN=100005;
vector<int> E[MAXN];

int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN],h[MAXN],g[MAXN],st[MAXN];

int dep[MAXN];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int v:E[u]) if(v!=fa) dfs(v,u);
}
bool check(int x){
	// cout<<x<<":\n";
	for(int i=1;i<=n;i++){
		if(c[i]>=0){
			int L=1,R=x,ans=-1;
			while(L<=R){
				int mid=(L+R)>>1;
				int en=b[i]+x*c[i],st=b[i]+mid*c[i];
				if((st+en)*(x-mid+1)/2>=a[i]) ans=mid,L=mid+1;
				else R=mid-1;
			}
			d[i]=ans;
		}
		else{
			if(st[i]>=x){
				int L=1,R=x,ans=-1;
				while(L<=R){
					int mid=(L+R)>>1;
					int en=b[i]+x*c[i],st=b[i]+mid*c[i];
					if((st+en)*(x-mid+1)/2>=a[i]) ans=mid,L=mid+1;
					else R=mid-1;
				}
				d[i]=ans;
			}else{
				if(x-st[i]>=a[i]) d[i]=x-a[i]+1;
				else{
					int L=1,R=st[i],ans=-1;
					while(L<=R){
						int mid=(L+R)>>1;
						int en=b[i]+x*c[i],st=b[i]+mid*c[i];
						if((st+en)*(x-mid+1)/2>=a[i]) ans=mid,L=mid+1;
						else R=mid-1;
					}
					d[i]=ans;
				}
			}
		}
		if(d[i]==-1) return 0;
		d[i]=min(d[i],n+1);
	}
	for(int i=1;i<=n+1;i++) h[i]=g[i]=0;
	for(int i=1;i<=n;i++) h[dep[i]]++,g[d[i]]++;
	for(int i=1;i<=n+1;i++){
		h[i]+=h[i-1],g[i]+=g[i-1];
		if(h[i]<g[i]) return 0;
	}
	return 1;
}

signed main(){
	// system("diff struct.out struct1.ans"); return 0;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i]<0){
			int m=-c[i];
			st[i]=b[i]/m;
		}
	}
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1,0);
	int l=1,r=1000000000,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}