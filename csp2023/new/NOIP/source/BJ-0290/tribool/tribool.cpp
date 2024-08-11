#include<bits/stdc++.h>
using namespace std;
int c,T,a[100005],nm[100005],jb[100005];char tp[100005];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;if(c==3||c==4){
		while(T--){
			int n,m;cin>>n>>m;int ans=0;
			for(int i=1;i<=m;i++){
				cin>>tp[i]>>nm[i];
				if(tp[i]=='U')a[nm[i]]=-1;
				if(tp[i]=='T')a[nm[i]]=1;
				if(tp[i]=='F')a[nm[i]]=0;
			}for(int i=1;i<=n;i++)if(a[i]==-1)ans++;
			cout<<ans<<endl;for(int i=1;i<=n;i++)a[i]=0;
		}
	}
	while(T--){
		int n,m;cin>>n>>m;int ans=0;
		for(int i=1;i<=m;i++){
			cin>>tp[i];
			if(tp[i]=='U')cin>>nm[i],a[nm[i]]=-1;
			if(tp[i]=='+')cin>>nm[i]>>jb[i],a[nm[i]]=a[jb[i]];
		}for(int i=1;i<=m;i++){
			if(tp[i]=='+')a[nm[i]]=a[jb[i]];
		}for(int i=1;i<=n;i++)if(a[i]==-1)ans++;
		cout<<ans<<endl;for(int i=1;i<=n;i++)a[i]=0;
	}
	return 0;
}