#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=500010;
int c,n,m,q,a[N],b[N],ya[N],yb[N];
bool check12(){
	if(n==1 && m==1)
		return 1;
	else if(n==2 && m==1)
		return ((a[1]-b[1])*(a[2]-b[1])>0);
	else if(n==1 && m==2)
		return ((a[1]-b[1])*(a[1]-b[2])>0);
	else
		return ((a[1]-b[1])*(a[2]-b[2])>0);
}
bool check(){
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&c,&n,&m,&q);
	for(int i=1; i<=n; ++i)
		scanf("%d",ya+i);
	for(int i=1; i<=m; ++i)
		scanf("%d",yb+i);
	for(int i=1; i<=n; ++i)
		a[i]=ya[i];
	for(int i=1; i<=m; ++i)
		b[i]=yb[i];
	printf("%d",c<=2?check12():check());
	for(int i=1; i<=q; ++i){
		for(int i=1; i<=n; ++i)
			a[i]=ya[i];
		for(int i=1; i<=m; ++i)
			b[i]=yb[i];
		int kx,ky,p,v;
		scanf("%d %d",&kx,&ky);
		for(int j=1; j<=kx; ++j){
			scanf("%d %d",&p,&v);
			a[p]=v;
		}
		for(int j=1; j<=ky; ++j){
			scanf("%d %d",&p,&v);
			b[p]=v;
		}
		printf("%d",c<=2?check12():check());
	}
	return 0;
}