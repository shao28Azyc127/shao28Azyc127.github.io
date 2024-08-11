#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#define LL long long
using namespace std;

const int NR=1e6+10;
const int MR=0;
const int MOD=0;

int n;

int cnt[NR];

int a[6],b[6];

int gn(){
	return 10000*b[1]+1000*b[2]+100*b[3]+10*b[4]+b[5];
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin >> a[j];
		}
		for(int j=1;j<=5;j++){
			memcpy(b,a,sizeof(b));
			for(int k=0;k<=9;k++){
				if(k==a[j])continue;
				b[j]=k;
				cnt[gn()]++;
			}
		}
		for(int j=1;j<=4;j++){
			for(int k=1;k<=9;k++){
				memcpy(b,a,sizeof(b));
				b[j]=(b[j]+k)%10;
				b[j+1]=(b[j+1]+k)%10;
				cnt[gn()]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=99999;i++){
		if(cnt[i]==n)ans++;
	}
	cout << ans << endl;

}