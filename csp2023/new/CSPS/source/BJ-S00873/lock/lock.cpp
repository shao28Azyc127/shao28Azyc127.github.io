#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ans=0;
int a[10][10];
int b[100010];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=9;i++){
			int k=(a[j][1]+i)%10;
			int p=k*10000+a[j][2]*1000+a[j][3]*100+a[j][4]*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][2]+i)%10;
			int p=k*1000+a[j][1]*10000+a[j][3]*100+a[j][4]*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][3]+i)%10;
			int p=k*100+a[j][1]*10000+a[j][2]*1000+a[j][4]*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][4]+i)%10;
			int p=k*10+a[j][1]*10000+a[j][2]*1000+a[j][3]*100+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][5]+i)%10;
			int p=k+a[j][1]*10000+a[j][2]*1000+a[j][3]*100+a[j][4]*10;
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][1]+i)%10;
			int q=(a[j][2]+i)%10;
			int p=k*10000+q*1000+a[j][3]*100+a[j][4]*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][2]+i)%10;
			int q=(a[j][3]+i)%10;
			int p=k*1000+a[j][1]*10000+q*100+a[j][4]*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][3]+i)%10;
			int q=(a[j][4]+i)%10;
			int p=k*100+a[j][1]*10000+a[j][2]*1000+q*10+a[j][5];
			b[p]++;
		}
		for(int i=1;i<=9;i++){
			int k=(a[j][4]+i)%10;
			int q=(a[j][5]+i)%10;
			int p=k*10+a[j][1]*10000+a[j][2]*1000+a[j][3]*100+q;
			b[p]++;
		}
		
	}
	for(int i=99999;i>=0;i--){
		if(b[i]==n){
			//cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
