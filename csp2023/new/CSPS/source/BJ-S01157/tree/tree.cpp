#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100010],b[100010],c[100010],ans;
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++) {
		int cnt=0;
		while(a[i]) {
			a[i]-=max(b[i]+(i+cnt)*c[i],1);
			cnt++;
		}
		ans=max(ans,cnt+i);
	}
	cout<<ans<<"\n";
	return 0;
}