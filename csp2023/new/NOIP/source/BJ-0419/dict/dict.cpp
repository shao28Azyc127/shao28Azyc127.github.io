#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int a[N][27];//��i���������1-26��Ӣ����ĸ���м���
int n,m;
char x;
int minn[N],maxx[N];//��i����������С����ĸ��ʲô
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
