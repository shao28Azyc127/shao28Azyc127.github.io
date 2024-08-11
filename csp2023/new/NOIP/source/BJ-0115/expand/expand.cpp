#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
const int N=100005;
int C,n,m,q,a[N],b[N];
int sov(){
	if(a[1]>b[1]&&a[n]>b[m]) return 1;
	if(a[1]<b[1]&&a[n]<b[m]) return 1;
	return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j,x,y,kx,ky;
	scanf("%d%d%d",&n,&m,&q);
	for1(i,n) scanf("%d",&a[i]);
	for1(i,m) scanf("%d",&b[i]);
	printf("%d",sov());
	for1(i,q){
		scanf("%d%d",&kx,&ky);
		for1(j,kx) scanf("%d%d",&x,&y),a[x]=y;
		for1(j,ky) scanf("%d%d",&x,&y),b[x]=y;
		printf("%d",sov());
	}
	return 0;
}
