#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int n, cnt;
#define FILE "apple"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int tmp = n, k = 0;
	while(tmp){
		cnt++;
		if(tmp%3 == 1 && !k) k = cnt;
		tmp -= (tmp-1)/3+1;
	}
	cout<<cnt<<' '<<k<<endl;
	return 0;
}
