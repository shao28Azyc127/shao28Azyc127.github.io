//v1 60pts
#include <bits/stdc++.h>
using namespace std;
int a[10];

int hsh[100000];
bool hsh_t[100000];

void shash(bool t){
	int v=a[1]+a[2]*10+a[3]*100+a[4]*1000+a[5]*10000;
	if(t){
		if(hsh[v]<0) return;
		if(hsh_t[v]) return;
		hsh_t[v]=1;
		hsh[v]++;
	}
	else hsh[v]=-0x3f3f3f3f;
}

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

	int n,ans=0;
	scanf("%d",&n);
	if(n==1) printf("81"),exit(0);

	for(int i=1;i<=n;i++){
		memset(hsh_t,0,sizeof hsh_t);
		for(int j=1;j<=5;j++) scanf("%d",&a[j]);
		shash(0);
		//A
		for(int j=1;j<=5;j++){
			int nw=a[j];
			for(int k=0;k<=9;k++)
				if(nw==k) continue;
				else a[j]=k,shash(1);
			a[j]=nw;
		}

		for(int j=1;j<=4;j++){
			int nw1=a[j],nw2=a[j+1];
			for(int k=0;k<=9;k++){
				a[j]=(nw1+k)%10,a[j+1]=(nw2+k)%10,shash(1);
			}
			a[j]=nw1,a[j+1]=nw2;
		}
	}
	for(int i=1;i<=99999;i++)
		if(hsh[i]==n) ans++;
	printf("%d",ans);
	return 0;
}