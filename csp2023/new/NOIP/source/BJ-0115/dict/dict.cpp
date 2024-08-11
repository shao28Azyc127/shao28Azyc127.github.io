#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
typedef unsigned long long ll;
const int N=3010;
const ll Z=1000000007;
int n,m;
ll hss[N][N],hsa[N][N];
char s[N][N],a[N][N];
bool cmp(const char &x,const char &y){
	return x>y;
}
int pd(int x,int y){
	int l,r,mid;
	l=0;r=m;
	while(l<=r){
		mid=(l+r)>>1;
		if(hss[x][mid]==hsa[y][mid]) l=mid+1;
		else r=mid-1;
	}
	//printf("%d %d %d %c %c\n",x,y,l,s[x][l],a[y][l]);
	return s[x][l]>=a[y][l];
}
int sov(int x){
	int i;
	for1(i,n) if(i!=x){
		if(pd(x,i)) return 0;
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for1(i,n){
		scanf("%s",a[i]+1);
		for1(j,m) s[i][j]=a[i][j];
		sort(s[i]+1,s[i]+m+1);
		sort(a[i]+1,a[i]+m+1,cmp);
		for1(j,m){
			hsa[i][j]=hsa[i][j-1]*Z+a[i][j];
			hss[i][j]=hss[i][j-1]*Z+s[i][j];
		}
	}
	for1(i,n) printf("%d",sov(i));
	return 0;
}
