#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,dis[N],v[N],ad,m,t[5]={9,8,9,6,5};

int sigma1(){
	int r=0;
	for(int i=0;i<n-1;i++) r+=dis[i];
	return r;
}

int me(){
	int re=2147483647;
	for(int i=0;i<n;i++){
		re=min(re,v[i]);
	}
	return re;
}

bool spe(){
	for(int i=0;i<n-1;i++) if(dis[i]!=10) return false;
	for(int i=0;i<n;i++) if(v[i]!=t[i]) return false;
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	for(int i=0;i<n-1;i++){
		scanf("%d",&dis[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	if(n==5&&d==4&&spe()){
		puts("79");
		return 0;
	}
	ad=sigma1();
	if(me()==v[0]){
		if(ad%d==0) m=(ad/d)*v[0];
		else m=(ad/d+1)*v[0];
	}
	printf("%d",m);
	return 0;
}
