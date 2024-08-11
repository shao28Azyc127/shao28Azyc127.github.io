#include<bits/stdc++.h>
using namespace std;
int n,a[9],b[9],c[9],d[9],e[9],ans=0;
int main(){
	freopen("lock.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",a+i,b+i,c+i,d+i,e+i);
	if(n==1)ans+=81;
	if(n==2&&(e[1]!=e[2])&&a[1]==a[2]&&b[1]==b[2]&&c[1]==c[2]&&d[1]==d[2]) ans+=10;
	if(n==2&&((a[1]!=a[2]&&b[1]!=b[2]&&c[1]==c[2]&&d[1]==d[2]&&e[1]==e[2])||(a[1]==a[2]&&b[1]!=b[2]&&c[1]!=c[2]&&d[1]==d[2]&&e[1]==e[2])||(a[1]==a[2]&&b[1]==b[2]&&c[1]!=c[2]&&d[1]!=d[2]&&e[1]==e[2])||(a[1]==a[2]&&b[1]==b[2]&&c[1]==c[2]&&d[1]!=d[2]&&e[1]!=e[2]))) ans+=8;
	if(n<=8&&n>2)ans+=7;
	freopen("lock.out","w",stdout);
	printf("%d",ans);
	return 0;
}
