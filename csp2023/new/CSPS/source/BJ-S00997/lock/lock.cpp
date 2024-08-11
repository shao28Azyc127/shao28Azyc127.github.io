#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;

int n,ans;
int a[N];
map<int,int> t;

void change(int pos,int k) {(a[pos]+=k+10)%=10;}
void work(int pre) {
	int res=0;
	for (int j=1; j<=5; j++)
		res=(res*10+a[j]);
	if (t[res]==pre) t[res]++,ans++;
}

int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) {
		ans=0;
		for (int j=1; j<=5; j++) cin>>a[j];
		for (int j=1; j<=5; j++)
			for (int k=1; k<=9; k++) {
				change(j,k); work(i-1); change(j,-k);
			}
		for (int j=1; j<5; j++) {
			for (int k=1; k<=9; k++) {
				change(j,k); change(j+1,k);
				work(i-1);
				change(j,-k); change(j+1,-k);
			}
		}
	} cout<<ans<<'\n';
	return 0;
}
