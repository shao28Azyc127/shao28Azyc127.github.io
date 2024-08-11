#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int len[100010],c[100010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,d;
	cin >> n >> d;
	fr(i,2,n)cin >> len[i];
	fr(i,1,n)cin >> c[i];
	int minc=c[1],ans=0,last=0;
	fr(i,2,n){
		if(last>=len[i]){
			last-=len[i];
			minc=min(minc,c[i]);
			continue;
		}
		int nl=len[i]-last;
		last=0;
		int need=(nl+d-1)/d;
		ans+=need*minc;
		last+=(need*d)-nl;
		minc=min(minc,c[i]);
	}
	cout << ans;
	return 0;
}
