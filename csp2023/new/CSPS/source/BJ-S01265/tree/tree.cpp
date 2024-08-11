#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<long long,int>
#define fir first
#define sec second
const int MX = 1e5 + 7;
ll a[MX],b[MX],c[MX];
vector<int > g[MX];

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;ll minn = 1e18 + 7;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i] >> c[i];
		minn = min(minn,(ll)ceil(a[i] * 1.0 / b[i]));
	}
	cout << n - 1 + minn << '\n';
	return 0;
}// 完全不会T4,火大!!!!!!!