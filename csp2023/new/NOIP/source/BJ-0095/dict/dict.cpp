#include<iostream>
#include<algorithm>
#include<fstream>
#include<set>
using namespace std;
const int N=3010;
int n,m;
char ch[N][N];
char chmin[N][N],chmax[N][N];
inline bool cmp(char a,char b){
	return a>b;
}
inline bool compair(char a[],char b[]){
	for(int i=1;i<=m;i++)
		if(a[i]!=b[i])
			return a[i]<b[i];
	return 0;
}
inline int check(int x){
	for(int i=1;i<=n;i++){
		if(i==x)
			continue;
		if(!compair(chmin[x],chmax[i]))
			return 0;
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(int j=1;j<=m;j++)
			chmin[i][j]=chmax[i][j]=ch[i][j];
		sort(chmin[i]+1,chmin[i]+1+m);
		sort(chmax[i]+1,chmax[i]+1+m,cmp);
		//printf("%s\n",ch[i]+1);
	}
	for(int i=1;i<=n;i++)
		printf("%d",check(i));
	return 0;
}