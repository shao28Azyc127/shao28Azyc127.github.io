#include <bits/stdc++.h>
using namespace std;
int n,d,v[100001],a[100001],x,ans,o2;
double oil,o1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		v[i+1]=v[i]+x;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1,j;i<n;i=j){
		for(j=i+1;a[j]>=a[i]&&j<n;j++){}
		o1=(v[j]-v[i]+0.0)/d;
		if(o1>oil){
			o2=o1-oil;
			if(o2+oil<o1){
				o2++;
			}
			ans+=o2*a[i];
			oil+=o2;
		}
		oil-=o1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}