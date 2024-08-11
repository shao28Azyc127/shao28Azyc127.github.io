#include<iostream>
using namespace std;
int n;
int map[100000];
int a[10];
void add(){
	int index = a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
	map[index]++;
	return;
}
long long tot;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=5;j++){
			scanf("%d",&a[j]);
		}
		for(int j = 1;j<=5;j++){
			int t = a[j];
			for(int k = 1;k<=9;k++){
				a[j]+=k;
				a[j]%=10;
				tot++;
				add();
				a[j] = t;
			}

		}
		for(int j = 1;j<=4;j++){
			int t1 = a[j];
			int t2 = a[j+1];
			for(int k = 1;k<=9;k++){
				a[j]+=k;
				a[j]%=10;
				a[j+1]+=k;
				a[j+1]%=10;
				add();
				tot++;
				a[j] = t1;
				a[j+1] = t2;
			}

		}
	}
	long long ans = 0;
	for(int i = 0;i<100000;i++){
		if(map[i]==n)ans++;
	}
	cout << ans;
	return 0;
}
