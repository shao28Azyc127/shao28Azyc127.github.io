#include<bits/stdc++.h>
using namespace std;

int id;
int n,m,q;
int ax[500005],bx[500005];
int a[500005],b[500005];
int ka,kb,p,v;

void init(){
	for(int i=1;i<=n;++i){
		a[i]=ax[i];
	}
	for(int i=1;i<=m;++i){
		b[i]=bx[i];
	}
	return;
}

bool dfs1(int l1,int l2){
	if(l1==n && l2==m){
		return 1;
	}
	if(l1!=n && l2!=m && a[l1+1]<b[l2+1]){
		if(dfs1(l1+1,l2+1)==1){
			return 1;
		}
	}
	if(l2!=m && a[l1]<b[l2+1]){
		if(dfs1(l1,l2+1)==1){
			return 1;
		}
	}
	if(l1!=n && a[l1+1]<b[l2]){
		if(dfs1(l1+1,l2)==1){
			return 1;
		}
	}
	return 0;
}

bool dfs2(int l1,int l2){
	if(l1==n && l2==m){
		return 1;
	}
	if(l1!=n && l2!=m && a[l1+1]>b[l2+1]){
		if(dfs2(l1+1,l2+1)==1){
			return 1;
		}
	}
	if(l2!=m && a[l1]>b[l2+1]){
		if(dfs2(l1,l2+1)==1){
			return 1;
		}
	}
	if(l1!=n && a[l1+1]>b[l2]){
		if(dfs2(l1+1,l2)==1){
			return 1;
		}
	}
	return 0;
}

bool solve(){
	if(a[1]==b[1] || a[n]==b[m]){
		return 0;
	}
	if(a[1]<b[1]){
		if(a[n]>b[m]){
			return 0;
		}
		return dfs1(1,1);
	}
	else{
		if(a[n]<b[m]){
			return 0;
		}
		return dfs2(1,1);
	}
}

bool solve2(){
	if(a[1]==b[1] || a[n]==b[m]){
		return 0;
	}
	if(a[1]<b[1]){
		if(a[n]>b[m]){
			return 0;
		}
		return 1;
	}
	else{
		if(a[n]<b[m]){
			return 0;
		}
		return 1;
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>id>>n>>m>>q;
	for(int i=1;i<=n;++i){
		cin>>ax[i];
	}
	for(int i=1;i<=m;++i){
		cin>>bx[i];
	}
	if(id<=7){
		init();
		cout<<solve();
		while(q--){
			init();
			cin>>ka>>kb;
			while(ka--){
				cin>>p>>v;
				a[p]=v;
			}
			while(kb--){
				cin>>p>>v;
				b[p]=v;
			}
			cout<<solve();
		}
		return 0;
	}
	init();
	cout<<solve2();
	while(q--){
		init();
		cin>>ka>>kb;
		while(ka--){
			cin>>p>>v;
			a[p]=v;
		}
		while(kb--){
			cin>>p>>v;
			b[p]=v;
		}
		cout<<solve2();
	}
	return 0;
}
