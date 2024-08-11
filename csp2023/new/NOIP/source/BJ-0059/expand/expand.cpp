#include<stdio.h>
int f[2001][2001];
bool work(int*a,int*b,int n,int m){
	if(a[1]>=b[1])return 0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			f[i][j]=0;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i]<b[j])
				f[i][j]=f[i-1][j-1]||f[i-1][j]||f[i][j-1];
	return f[n][m];
}
int a[2001],b[2001],ta[20001],tb[2001];
int main(){
	freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	int c,n,m,q;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",ta+i);
	for(int i=1;i<=m;++i)scanf("%d",tb+i);
	printf("%d",work(ta,tb,n,m)||work(tb,ta,m,n));
	for(int kx,ky,x,v;q--;){
		for(int i=1;i<=n;++i)a[i]=ta[i];
		for(int i=1;i<=m;++i)b[i]=tb[i];
		scanf("%d%d",&kx,&ky);
		for(;kx--;)scanf("%d%d",&x,&v),a[x]=v;
		for(;ky--;)scanf("%d%d",&x,&v),b[x]=v;
		printf("%d",work(a,b,n,m)||work(b,a,m,n));
	}
	return 0;
}