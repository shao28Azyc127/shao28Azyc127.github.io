#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int a[N][27];//第i个单词里从1-26个英文字母各有几个
int n,m;
char x;
int minn[N],maxx[N];//第i个单词里最小的字母是什么
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	for(int i=1;i<=N;i++){
		minn[i]=1000000;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			int lnx=int(x-'a'+1);
			a[i][lnx]++;
			minn[i]=min(minn[i],lnx);
			maxx[i]=max(maxx[i],lnx);
		}
	}
	for(int i=1;i<=n;i++){
		bool first=0;
		for(int j=1;j<=n;j++){
			if(j!=i){
				if(maxx[j]<=minn[i]) {first=1; break;}
			}
		}
		if(first==0) {cout<<1; continue;}
		else {cout<<0; continue;}
	}
	return 0;
}
