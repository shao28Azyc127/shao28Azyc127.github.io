#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int N=500010;
int c,n,m,q;
int a[N],b[N];
int ba[N],bb[N];
inline bool solve(int n,int m,int a[],int b[]){
	int maxa=1,mina=1,maxb=1,minb=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[maxa])
			maxa=i;
		if(a[i]<a[mina])
			mina=i;
	}
	for(int i=2;i<=m;i++){
		if(b[i]>b[maxb])
			maxb=i;
		if(b[i]<b[minb])
			minb=i;
	}
	int xa=a[maxa],ia=a[mina],xb=b[maxb],ib=b[minb];
	if(xa<=xb)
		return 0;
	if(ia<=ib)
		return 0;
	if(a[1]<=b[1])
		return 0;
	if(a[n]<=b[m])
		return 0;
	int i=1,j=1;
	while(a[i]>b[j]&&i<=maxa)
		i++;
	for(;i<=maxa&&j<=minb;)
		if(a[i]>b[j])
			i++,j++;
		else if(--i==0)
			return 0;
	i=n,j=m;
	while(a[i]>b[j]&&i>=maxa)
		i--;
	for(;i>=maxa&&j>=minb;)
		if(a[i]>b[j])
			i++,j++;
		else if(++i>n)
			return 0;
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	memcpy(ba,a,sizeof ba);
	memcpy(bb,b,sizeof bb);
	printf("%d",solve(n,m,a,b)||solve(m,n,b,a)?1:0);
	while(q--){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		while(k1--){
			int p,v;
			scanf("%d%d",&p,&v);
			a[p]=v;
		}
		while(k2--){
			int p,v;
			scanf("%d%d",&p,&v);
			b[p]=v;
		}
		printf("%d",solve(n,m,a,b)||solve(m,n,b,a)?1:0);
		memcpy(a,ba,sizeof a);
		memcpy(b,bb,sizeof b);
	}
	return 0;
}