#include<cstdio>
#include<iostream>
using namespace std;
int a[105][105],b;
int main(){
	int n,m,maxn=-301;cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			b=a[i][j]+a[i-1][j]+a[i][j-1]+a[i+1][j]+a[i][j+1]+a[i-1][j-1]+a[i-1][j+1]+a[i+1][j-1]+a[i+1][j+1];
			if(b>maxn){maxn=b;}
		}
	}cout<<maxn;return 0;
}
