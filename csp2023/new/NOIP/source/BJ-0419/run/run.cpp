#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=1e5+5;
struct node{
	long long x,y,v;
}cha[N];
long long f[N][N];
long long n,m,k,d;
int T;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>T>>T;
	while(T--){
	cin>>n>>m>>k>>d;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		cha[i].x=0;
		cha[i].y=0;
		cha[i].v=0;
	}
	for(int i=1;i<=m;i++){
		long long tmp1,tmp2;
		cin>>tmp1>>tmp2;
		cha[tmp1+tmp2-1].x=tmp1;
		cha[tmp1+tmp2-1].y=tmp2;
		cin>>cha[tmp1+tmp2-1].v;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			f[i][j]=f[i-1][j-1]-d;
		}
		if(cha[i].v>0 && cha[i].y<=k){
			f[cha[i].x+cha[i].y-1][cha[i].y]=f[cha[i].x+cha[i].y-1][cha[i].y]+cha[i].v;
		}
	}
	long long maxx=-1000000000000;
	for(int i=1;i<=k;i++){
		maxx=max(maxx,f[n][i]);
	}
	cout<<maxx<<endl;
	}
	return 0;
}