#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,aa[15],bb[15],cc[15],dd[15],ans;
char vv[15];
bool b[100005];
void dfs(int x,int count){
	if(x==n){
		for(int i=1;i<=n;i++) dd[i]=cc[i];
		for(int i=1;i<=m;i++){
			if(vv[i]=='T') dd[aa[i]]=2;
			if(vv[i]=='F') dd[aa[i]]=1;
			if(vv[i]=='U') dd[aa[i]]=3;
			if(vv[i]=='-'){
				if(dd[bb[i]]==3) dd[aa[i]]=3;
				else if(dd[bb[i]]==2) dd[aa[i]]=1;
				else if(dd[bb[i]]==1) dd[aa[i]]=2;
			}
			if(vv[i]=='+') dd[aa[i]]=dd[bb[i]];
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(dd[i]!=cc[i]){
				flag=false;
				break;
			}
		if(flag==true) ans=min(ans,count);
		return;
	}
	for(int i=1;i<=3;i++){
		cc[x+1]=i;
		if(i==3) count++;
		dfs(x+1,count);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==1||c==2){
		while(t--){
			ans=11;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>vv[i];
				if(vv[i]=='T'||vv[i]=='F'||vv[i]=='U') scanf("%d",&aa[i]);
				else scanf("%d%d",&aa[i],&bb[i]);
			}
			dfs(0,0);
			printf("%d\n",ans);
		}
	}
	if(c==3||c==4){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++) b[i]=false;
			for(int i=1;i<=m;i++){
				char cx;
				int cy;
				scanf("%s%d",&cx,&cy);
				if(cx=='U') b[cy]=true;
				else b[cy]=false;
			}
			for(int i=1;i<=n;i++) if(b[i]==true) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}