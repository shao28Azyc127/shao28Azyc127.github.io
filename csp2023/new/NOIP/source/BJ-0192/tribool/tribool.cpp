#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int c,t,n,m,a[N],ans=0x3f3f3f3f,b[N],x[N],y[N],op[N];
char o[N];
inline int div(int x){
	if(x==0) return 1;
	if(x==1) return 0;
	if(x==2) return 2;
}
inline int ref(char x){
	if(x=='T') return 1;
	if(x=='F') return 0;
	if(x=='U') return 2;
}
inline void solve(int *a){
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++){
		if(o[i]=='+') a[x[i]]=a[y[i]];
		else if(o[i]=='-') a[x[i]]=div(a[y[i]]);
		else a[x[i]]=ref(o[i]);
	}
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]) return ;
	int res=0;
	for(int i=1;i<=n;i++)
		res+=(a[i]==2);
	ans=min(ans,res);
	return ;
}
inline void dfs(int cur){
	if(cur==n+1){
		solve(a);
		return ;
	}
	for(int i=0;i<=2;i++){
		a[cur]=i;
		dfs(cur+1);
	}
}
inline void work1(){
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>m;
		bool flg=0;
		for(int i=1;i<=m;i++){
			char op;
			cin>>op;
			o[i]=op;
			if(op=='+'){
				int u,v;
				cin>>u>>v;
				x[i]=u,y[i]=v;
				flg=1;
			}else if(op=='-'){
				int u,v;
				cin>>u>>v;
				x[i]=u,y[i]=v;
				flg=1;
			}else{
				int u;
				cin>>u;
				x[i]=u;
			}
		}
		if(n<=10){
			work1();
		}else if(!flg){
			ans=0;
			for(int i=1;i<=n;i++) a[i]=-1;
			for(int i=m;i>=1;i--)
				if(a[x[i]]<0) a[x[i]]=ref(o[i]);
			for(int i=1;i<=n;i++) ans+=(a[i]==2);
			cout<<ans<<'\n';
		}else{
			ans=0;
			for(int i=1;i<=n;i++) a[i]=-1;
			int t=600;
			while(t--){
				for(int i=1;i<=m;i++){
					if(o[i]=='+') a[x[i]]=a[y[i]];
					if(o[i]=='U') a[x[i]]=2;
				}
			}
			for(int i=1;i<=n;i++) ans+=(a[i]==2);
			cout<<ans<<'\n';
		}
	}
	return 0;
}