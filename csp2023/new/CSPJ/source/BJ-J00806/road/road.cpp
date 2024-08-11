#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005],n,d,minm=999999,cnt=0;
void dfs(int de,int p,int m,int s){
	if(p==n||de<=0) {minm=min(m,minm);return;}
	for(int i=max((v[p+1]-s)/d,1);i<=de/d+1;i++){
		if(i*d+s>=v[p+1]) dfs(de-v[p+1],p+1,m+a[p+1]*i,s+i*d-v[p+1]);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++) scanf("%d",&v[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++) cnt+=v[i];
	if(n<=205){
		dfs(cnt,0,0,0);
		cout<<minm-1;
	}
	else{
		if(cnt%d==0) cout<<cnt/d*a[1];
		else cout<<((cnt/d)+1)*a[1];
	}
    return 0;
}
/*
 5 4 
 10 10 10 10
 9 8 9 6 5
 100 100 100 100 100 100 100 100
 1 100 100 100 100 100 100 100 100
*/
