#include <bits/stdc++.h>
using namespace std;

int c,t,ans,n,m,x,y;
int r[100005],ru[100005][2];
char s[100005];

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==5||c==6){
		for(int zzz=1;zzz<=t;zzz++){
			ans=0;
			memset(r,0,sizeof(r));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>s[i];
				if(s[i]=='U'){
					scanf("%d",&x);
					r[x]=1;
					ru[i][1]=x;
				}else if(s[i]=='+'){
					scanf("%d%d",&x,&y);
					r[x]=r[y];
					ru[i][1]=x,ru[i][2]=y;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(s[j]=='U'){
						r[ru[j][1]]=1;
					}else if(s[j]=='+'){
						r[ru[j][1]]=r[ru[j][2]];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(r[i]!=0){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}else{
		for(int zzz=1;zzz<=t;zzz++){
			ans=0;
			memset(r,0,sizeof(r));
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				cin>>s[i];
				if(s[i]=='U'){
					scanf("%d",&x);
					r[x]=1;
					ru[i][1]=x;
				}else if(s[i]=='+'){
					scanf("%d%d",&x,&y);
					r[x]=r[y];
					ru[i][1]=x,ru[i][2]=y;
				}else if(s[i]=='T'){
					scanf("%d",&x);
					r[x]=2;
					ru[i][1]=x;
				}else if(s[i]=='F'){
					scanf("%d",&x);
					r[x]=-2;
					ru[i][1]=x;
				}else{
					scanf("%d%d",&x,&y);
					r[x]=-r[y];
					ru[i][1]=x,ru[i][2]=y;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(s[i]=='U'){
						ru[i][1]=x;
					}else if(s[i]=='+'){
						r[x]=r[y];
					}else if(s[i]=='T'){
						r[x]=2;
					}else if(s[i]=='F'){
						r[x]=-2;
					}else{
						r[x]=-r[y];
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(r[i]==1){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
