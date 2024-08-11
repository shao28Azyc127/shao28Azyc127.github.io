#include<bits/stdc++.h>
using namespace std;
const int N=10000+5;
int a[N],v[N],minid[N][N],sum[N][N],cost,d;
int minidex(int l,int r){
	if(l==r) return minid[l][r]=l;
	if(minid[l][r]!=0) return minid[l][r];
	int mid=(l+r)/2;
	int lm=minidex(l,mid),mr=minidex(mid+1,r);
	if(a[lm]>a[mr]) return minid[l][r]=mr;
	return minid[l][r]=lm;
}
int su(int l,int r){
	if(l==r-1){
		return sum[l][r]=v[l];
	}
	if(sum[l][r]!=0) return sum[l][r];
	int mid=(l+r)/2;
	return sum[l][r]=su(l,mid)+su(mid,r);
}
int la(int l,int r){
	int mi=minidex(l,r-1),s=su(l,r);
	if(mi==1){
		cost+=(s/d+(s%d!=0))*a[1];
		if(s%d==0) return 0;
		return d-s%d;
	}
	int s2=su(mi,r);
	int lo=la(l,mi);
	if(lo>=s2){
		return lo-s2;
	}
	cost+=((s2-lo)/d+((s2-lo)%d!=0))*a[mi];
	if((s2-lo)%d==0) return 0;
	return d-(s2-lo)%d;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	la(1,n);
	cout<<cost;
	return 0;
}
