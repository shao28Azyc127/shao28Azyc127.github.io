#include<bits/stdc++.h>
using namespace std;
int a1[1000055],b1[1000005],n,m,prem[100005],prei[100005],aa[1000055],bb[1000005];
bool check(int a[],int b[]){
	if(a[1]>b[1]){
		for(int i=1;i<=max(n,m)-1;i++){
			if(a[i]<=b[i]){
				if(prem[i]>b[i])continue;
				return false;
			}
		}if(a[n]>b[m])return true;
		return false;
	}if(a[1]<b[1]){
		for(int i=1;i<=max(n,m)-1;i++){
			if(a[i]>=b[i]){
				if(prei[i]<b[i])continue;
				return false;
			}
		}if(a[n]<b[m])return true;
		return false;
	}if(a[1]==b[1])return false;
	return false;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;cin>>c>>n>>m>>q;prei[0]=INT_MAX;
	if(c==1){
		for(int i=1;i<=n;i++)cin>>aa[i];
		for(int i=1;i<=m;i++)cin>>bb[i];
		if(aa[1]!=bb[1])cout<<1;else cout<<0;
		while(q--){
			int ka,kb;cin>>ka>>kb;
			for(int i=0;i<=n;i++)prei[i]=prem[i]=0;
			for(int i=0;i<=n;i++)a1[i]=aa[i];
			for(int i=0;i<=m;i++)b1[i]=bb[i];
			prei[0]=INT_MAX;
			for(int i=1;i<=ka;i++){
				int pa,va;cin>>pa>>va;a1[pa]=va;
			}for(int i=1;i<=kb;i++){
				int pb,vb;cin>>pb>>vb;b1[pb]=vb;
			}if(a1[1]==b1[1])cout<<0;
			else cout<<1;
		}cout<<endl;return 0;
	}
	for(int i=1;i<=n;i++)cin>>aa[i];
	for(int i=1;i<=m;i++)cin>>bb[i];
	if(m<n)for(int i=m+1;i<=n;i++)bb[i]=bb[m];
	if(m>n)for(int i=n+1;i<=m;i++)aa[i]=aa[n];
	for(int i=1;i<=max(n,m);i++)prem[i]=max(prem[i-1],aa[i]);
	for(int i=1;i<=max(n,m);i++)prei[i]=min(prei[i-1],aa[i]);
	cout<<check(aa,bb);
	while(q--){
		int ka,kb;cin>>ka>>kb;
		for(int i=0;i<=n;i++)prei[i]=prem[i]=0;
		for(int i=0;i<=n;i++)a1[i]=aa[i];
		for(int i=0;i<=m;i++)b1[i]=bb[i];
		prei[0]=INT_MAX;
		for(int i=1;i<=ka;i++){
			int pa,va;cin>>pa>>va;a1[pa]=va;
		}for(int i=1;i<=kb;i++){
			int pb,vb;cin>>pb>>vb;b1[pb]=vb;
		}for(int i=1;i<=max(n,m);i++)prem[i]=max(prem[i-1],a1[i]);
		for(int i=1;i<=max(n,m);i++)prei[i]=min(prei[i-1],a1[i]);
		cout<<check(a1,b1);
	}cout<<endl;return 0;
}