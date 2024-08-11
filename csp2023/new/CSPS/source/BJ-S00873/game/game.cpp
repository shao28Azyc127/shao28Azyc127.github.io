#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long ans=0;
int f[8010][8010],d[8010][8010],p[8010][8010];//f->first,d->end
char c[2000010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	memset(f,-1,sizeof(f));
	memset(d,-1,sizeof(d));
	memset(p,0x3f3f3f3f,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>c[i];
		d[i][i]=f[i][i]=c[i]-'a'+1;
		p[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i;k<j;k++){
				if(d[i][k]==f[k+1][j]&&d[i][k]!=-1&&d[i][k]!=0){
					if(p[i][k]+p[k+1][j]-2<p[i][j]){
						p[i][j]=p[i][k]+p[k+1][j]-2;
						if(p[i][j]==0) f[i][j]=0,d[i][j]=0;
						else f[i][j]=f[i][k],d[i][j]=d[k+1][j];
					}
				}else if(d[i][k]==f[k+1][j]&&d[i][k]==0){
					p[i][j]=0;
					f[i][j]=0,d[i][j]=0;
				}else if(d[i][k]==0){
					if(p[k+1][j]<p[i][j]){
						p[i][j]=p[k+1][j];
						f[i][j]=f[k+1][j],d[i][j]=d[k+1][j];
					}
				}else if(f[k+1][j]==0){
					if(p[i][k]<p[i][j]){
						p[i][j]=p[i][k];
						f[i][j]=f[i][k],d[i][j]=d[i][k];
					}
				}
			}
			if(p[i][j]==0) ans++;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}*/
	printf("%lld",ans);
	return 0;
}
