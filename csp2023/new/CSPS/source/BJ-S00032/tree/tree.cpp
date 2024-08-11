#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],b[100001],c[100001],h[100001],u,v,x,cmp;
bool z[100001];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
	}
	for(x=1;x<=n;x++){
		for(int i=1;i<=x;i++){
			if(z[i]==0){
				h[i]+=max(b[i]+x*c[i],1);
				if(h[i]>=a[i]){
					z[i]=1;
					cmp++;
				}
			}
		}
	}
	for(x=1;cmp<n;x++){
		for(int i=1;i<=n;i++){
			if(z[i]==0){
				h[i]+=max(b[i]+x*c[i],1);
				if(h[i]>=a[i]){
					z[i]=1;
					cmp++;
				}
			}
		}
	}
	printf("%d",x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}