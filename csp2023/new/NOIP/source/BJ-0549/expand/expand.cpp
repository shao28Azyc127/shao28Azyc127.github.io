#include<bits/stdc++.h>
using namespace std;
int cc,n,m,q,a[500005],b[500005],c[500005],d[500005];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>cc>>n>>m>>q;
	if(cc==1){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		cout<<1;
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=x;i++){
				int v,w;
				scanf("%d%d",&v,&w);
			}
			for(int i=1;i<=y;i++){
				int v,w;
				scanf("%d%d",&v,&w);
			}
			cout<<1;
		}
	}
	else if(cc==2){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) d[i]=b[i];
		if(n==1) c[2]=c[1];
		if(m==1) d[2]=d[1];
		if((c[1]-d[1])*(c[2]-d[2])<0) cout<<0;
		else cout<<1;
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			for(int i=1;i<=x;i++){
				int v,w;
				scanf("%d%d",&v,&w);
				c[v]=w;
			}
			for(int i=1;i<=y;i++){
				int v,w;
				scanf("%d%d",&v,&w);
				d[v]=w;
			}
			if(n==1) c[2]=c[1];
			if(m==1) d[2]=d[1];
			if((c[1]-d[1])*(c[2]-d[2])<0) cout<<0;
			else cout<<1;
		}
	}
	else if(8<=cc&&14>=cc){
		int maxx=0,maxy=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) d[i]=b[i];
		bool flag=true;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,c[i]);
			maxy=max(maxy,d[min(i,m)]);
			if(maxx>=maxy){
				flag=false;
				break;
			}
		}
		if(flag==true) cout<<1;
		else cout<<0;
		while(q--){
			maxx=0;
			maxy=0;
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=n;i++) c[i]=a[i];
			for(int i=1;i<=m;i++) d[i]=b[i];
			for(int i=1;i<=x;i++){
				int v,w;
				scanf("%d%d",&v,&w);
				c[v]=w;
			}
			for(int i=1;i<=y;i++){
				int v,w;
				scanf("%d%d",&v,&w);
				d[v]=w;
			}
			bool flag=true;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,c[i]);
				maxy=max(maxy,d[min(i,m)]);
				if(maxx>=maxy){
					flag=false;
					break;
				}
			}
			if(flag==true) cout<<1;
			else cout<<0;
		}
	}
	else{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		cout<<1;
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=x;i++){
				int v,w;
				scanf("%d%d",&v,&w);
			}
			for(int i=1;i<=y;i++){
				int v,w;
				scanf("%d%d",&v,&w);
			}
			cout<<1;
		}
	}
	return 0;
}
