#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,c;
void work1()
{
	int n,m;
	ll ans = 0;
	//unordered_map<int,int> mp;
	cin >> n >> m;
	int mp[100010];
	for(int i =1;i<=n;i++)
	{
		char a;int b,c;
		cin >> a >> b;
		if(a == '+') {
			cin >> c;
			mp[b] = mp[c];
		}
		else if(a == 'U') mp[b] = 1;
		else  mp[b] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0) ans++;
	}
	cout << ans << endl;
}
int main(){
	

	ios::sync_with_stdio(false);
	cin .tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	if(3<=c and c<=6)
	{
		while(t--) work1();
	}
	//this should be 40 pts
	return 0;
}