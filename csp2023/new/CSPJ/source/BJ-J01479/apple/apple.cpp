#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
signed main(){
	freopen("apple.in","r",stdin);	
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int cnt=0,cnt2=0;
	while(n%3!=1)
		n-=((n-1)/3)+1,cnt++;
	while(n)n-=((n-1)/3)+1,cnt2++;
	cout << cnt+cnt2 << " " <<cnt+1 ;
	return 0;
}
