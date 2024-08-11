#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
using namespace std;
const int N=100005;
int n,a[N],t[N],p[N],ans;
int nt(int x){
	if(x==9) return 0;
	return x+1;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int i,j,k,x,y,w;
	scanf("%d",&n);
	p[0]=1;
	for1(i,5) p[i]=p[i-1]*10;
	for1(i,n) for1(j,5){
		scanf("%d",&x);
		a[i]=a[i]*10+x;
	}
	for1(k,n){
		for0(i,5){
			x=a[k]/p[i]%10;
			w=a[k]-x*p[i];
			for1(j,9){
				x=nt(x);
				t[w+x*p[i]]++;
			}
		}
		for0(i,4){
			x=a[k]/p[i]%10;y=a[k]/p[i+1]%10;
			w=a[k]-x*p[i]-y*p[i+1];
			for1(j,9){
				x=nt(x);y=nt(y);
				t[w+x*p[i]+y*p[i+1]]++;
			}
		}
	}
	for0(i,100000) if(t[i]==n) ans++;
	printf("%d\n",ans);
	return 0;
}
/*
3
4 0 5 2 3
4 0 4 2 3
5 0 6 2 3
*/
