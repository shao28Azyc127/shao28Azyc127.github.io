#include <bits/stdc++.h>
using namespace std;
long long skm=0,ss=0,minmin=1000000000000,weizhimin,minn=10000000000000;
int main(){
	//freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
	int n,d,a[100005],v[100005];
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n-1;i++)	scanf("%d",&v[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<minmin && i!=n){
			minmin=a[i];
			weizhimin=i;
		}
	}
	if(weizhimin==1){
		for(int i=0;i<=n-1;i++)
			skm+=v[i];
		if(skm%d==0)	ss=skm/d * a[1];
		else ss=(skm/d+1) * a[1];
		cout<<ss;
		return 0;
	}else{
		int dis=0;
		for(int i=1;i<n;i++){
			if(a[i]<minn) minn=a[i];
			if((v[i]-dis)%d==0) ss+=floor((v[i]-dis)/d)*minn;
			else{
				ss+=floor((v[i]-dis)/d+1)*minn;
				dis=v[i]/d*d+d-v[i];
			}
		}
		cout<<ss;
	}
	return 0;
}
