#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
int n,m;
int a[3010][3010];
int t[3010][30];
int b[3010][30][2]; //min
int c[3010][30][2]; //max
void cz(int x){
	int cnt=0;
	for(int i=1;i<=26;i++)
		if(t[x][i])
			b[x][++cnt][0]=i,b[x][cnt][1]=t[x][i];
	cnt=0;
	for(int i=26;i>=1;i--)
		if(t[x][i])
			c[x][++cnt][0]=i,c[x][cnt][1]=t[x][i];
}
bool bj(int x,int y){ // x min y max
	for(int i=1;i<=26;i++){
		if(b[x][i][0]>c[y][i][0]) return 0;
		if(b[x][i][0]<c[y][i][0]) return 1;
		if(b[x][i][1]!=c[y][i][1]) return 0;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char cc;cin>>cc;
			a[i][j]=cc-'a'+1;
			t[i][a[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cz(i);
	}
	for(int i=1;i<=n;i++){
		int tt=0;
		for(int j=1;j<=n;j++)
			if(i!=j&&!bj(i,j)) tt=1;
		cout<<1-tt;
	}
	return 0;
}
