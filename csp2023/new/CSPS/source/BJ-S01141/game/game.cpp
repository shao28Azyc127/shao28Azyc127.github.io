#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=200010;
int n;
string s;
vector<int>E[N];
int cnt[N];
int ef(int x,int y){
	int t=E[x].size();
	if(t==0)return 0;
	if(t==1){
		if(E[x][0]==y)return 1;
		return 0;
	}
	int l=0,r=t-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(E[x][mid]==y)return 1;
		if(E[x][mid]>y)r=mid-1;
		if(E[x][mid]<y)l=mid+1;
	}
	return 0;
}
void solve1(){
	for(int i=1;i<n;i++){
		if(s[i]==s[i+1]){E[i].push_back(i+1);}
	}
	for(int len=3;len<=n;len++){
		for(int op=1;op+len-1<=n;op++){
			int ed=op+len-1;
			if(s[op]==s[ed]){
				int kk=ef(op+1,ed-1);
				if(kk){E[op].push_back(ed);continue;}
			}
			for(int i:E[op]){
				int kk=ef(i+1,ed);
				if(kk){E[op].push_back(ed);break;}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=E[i].size();
	}
	cout<<ans;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    s=" "+s;
    solve1();
    return 0;
}
