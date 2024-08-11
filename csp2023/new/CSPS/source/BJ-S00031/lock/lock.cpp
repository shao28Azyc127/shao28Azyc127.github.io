// #include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define ll long long
#define N 11
int n, a[6], m[100005], ans;
int d[9][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{1,1,0,0,0},{0,1,1,0,0},{0,0,1,1,0},{0,0,0,1,1}};

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		for (int j=1;j<=5;j++) {
			scanf("%d", &a[j]);
		}
		for (int j=1;j<=9;j++) {
			for (int k=0;k<9;k++) {
				int p = (a[1]+d[k][0]*j)%10*10000 + (a[2]+d[k][1]*j)%10*1000 + (a[3]+d[k][2]*j)%10*100 + (a[4]+d[k][3]*j)%10*10 + (a[5]+d[k][4]*j)%10;
				m[p]++;
			}
		}
	}
	for (int i=0;i<=100000;i++) {
		if (m[i]>=n) {
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}

