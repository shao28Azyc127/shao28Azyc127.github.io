// kamisako
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int maxn=10;
int n,a[maxn][maxn],b[maxn];
int bb[maxn],cc[maxn];

int ma[100000];

int gn() {
	return b[1]*10000+b[2]*1000+b[3]*100+b[4]*10+b[5];
}

int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j) scanf("%d",&a[i][j]);
	}
	int cnt=0;
	for (int kk = 1; kk <= n; ++kk) {
		for (int i = 0; i <= 99999; ++i) {
			int fl=0;
			for (int j = 1; j <= 5; ++j) {
				int k=(10+a[kk][j]-b[j])%10;
				if (k) ++fl,bb[fl]=j,cc[fl]=k;
			}
			if (fl==1){
				ma[gn()]++;
			}
			if (fl == 2&&bb[1]+1==bb[2]&&cc[1]==cc[2]) {
				ma[gn()]++;
			}

			b[1]++;
			int id=1;
			while (b[id]>9) b[id+1]++,b[id]-=10,id++;
		}
	}
	for (int i = 0; i <= 99999; ++i) {
		if (ma[i] == n) ++cnt;
	}
	printf("%d\n",cnt);

	return 0;
}