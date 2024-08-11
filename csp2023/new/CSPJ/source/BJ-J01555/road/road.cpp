#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n, mn[N];
LL d, v[N], a[N], pre[N], sum;
#define FILE "road"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d;
	for(int i = 1; i < n; i++){
		cin>>v[i];
		pre[i+1] = pre[i]+v[i];
	}
	for(int i = 1; i < n; i++) cin>>a[i];
	for(int i = 1, cur = 1; i < n; i++){
		while(a[cur] >= a[i]) cur++;
		mn[i] = cur;
	}
	for(int i = 1, lst = 0, cur, dis; i < n; i = mn[i]){
		dis = pre[mn[i]]-pre[i];
		cur = (dis-lst-1)/d+1;
		lst += cur*d-dis;
		sum += cur*a[i];
	}
	cout<<sum;
	return 0;
}
