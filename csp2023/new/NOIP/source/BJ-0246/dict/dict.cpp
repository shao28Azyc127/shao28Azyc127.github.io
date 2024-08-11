#include <bits/stdc++.h>
using namespace std;
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
string mp[3010];
char maxn[3010],minn[3010],qmin[3010],hmin[3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	qmin[0]='z';
	hmin[n+1]='z';
	fr(i,1,n){
		cin >> mp[i];
		mp[i]= " " +mp[i];
		maxn[i]='a';
		minn[i]='z';
		fr(j,1,m)maxn[i]=max(maxn[i],mp[i][j]),minn[i]=min(minn[i],mp[i][j]);
		qmin[i]=min(qmin[i-1],maxn[i]);
	}
	dfr(i,n,1)hmin[i]=min(hmin[i+1],maxn[i]);
	if(n==1){
		cout << 1;
		return 0;
	}
	fr(i,1,n){
		if(minn[i]<min(qmin[i-1],hmin[i+1]))cout << 1;
		else cout << 0;
	}
	return 0;
}
