#include<bits/stdc++.h>
#define ffor(i,l,r) for(ll  i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(ll  i=(l),i##_end=(r);i>=i##_end;i--)
using namespace std;
using ll = long long;
ll  n;
char s[2000010];
char st[2000010];
ll  dp[2000010];
ll  tp = 0,ans = 0;
ll ggcnt = 0;
set<pair<int,int>> mp;
void calc(int l,int r){
	tp = 0;
	ffor(i,l,r){
		tp = 0;
		ffor(j,i,r){
			if(tp&&st[tp]==s[j]) tp--;
			else{
				st[++tp] = s[j];
			}
			if(tp==0) mp.insert(make_pair(i,j));
		}
	}
}
void AKIOI(){
	vector<int> pos;
	ffor(i,1,n-1){
		if(s[i]==s[i+1]) pos.push_back(i);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	ans = 0;
	for(int x:pos){
		calc(max(1ll,x-20ll),min(n,x+20ll));
	}
	cout<<mp.size();
	exit(0);
}
int  main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//dp[0] = 1;
	cin>>n;
	cin>>(s+1);
	ffor(i,1,n){
		ll  cnt = 0;
		tp  = 0;
		rfor(j,i,1){
			ggcnt++;
			if(ggcnt>6e7) AKIOI();
			if(tp&&st[tp]==s[j]) tp--;
			else{
				st[++tp] = s[j];
			}
			if(tp==0){
				cnt++;
				cnt*=(dp[j-1]+1);
				break;
			} 
		}
		dp[i] = cnt;
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}