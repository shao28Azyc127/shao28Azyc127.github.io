#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll mod=0;
int n;
string s;
unordered_map<ull,vector<int>>cnt;
int f[2000005][25],lg[2000005];
int qry(int l,int r){
	const int L=lg[r-l+1];
	return min(f[l][L],f[r-(1<<L)+1][L]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	if(n<=8000){
		ll ans=0;
		stack<char>st;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(st.size()&&st.top()==s[j-1])st.pop();
				else st.push(s[j-1]);
				ans+=st.empty();
			}
			while(!st.empty())st.pop();
		}
		cout<<ans<<endl;
	}else{
		ll ans=0;
		stack<pair<char,int>>st;
		ull val=0;
		lg[0]=-1;
		for(int i=1;i<=n;i++){
			if(st.size()&&st.top().first==s[i-1]){
				val^=1ull*(s[i-1]+2000000)*st.size(),st.pop();
			}else{
				st.push({s[i-1],i});
				val^=1ull*(s[i-1]+2000000)*st.size();
			}
			f[i][0]=st.size();
			lg[i]=lg[i/2]+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=21;j++)f[i][j]=min(f[i][j-1],f[(i+(1<<(j-1))<=n?i+(1<<(j-1)):n)][j-1]);
		}
		while(!st.empty())st.pop();
		val=0;
		cnt[0].push_back(0);
		for(int i=1;i<=n;i++){
			if(st.size()&&st.top().first==s[i-1]){
				val^=1ull*(s[i-1]+2000000)*st.size(),st.pop();
			}else{
				st.push({s[i-1],i});
				val^=1ull*(s[i-1]+2000000)*st.size();
			}
			vector<int>tmp=cnt[val];
			int l=0,r=tmp.size()-1,mid;
			while(l<r){
				mid=l+r>>1;
				if(qry(tmp[mid],i)<f[i][0])l=mid+1;
				else r=mid;
			}
			ans+=tmp.size()-l;
			cnt[val].push_back(i);
			//cout<<i<<": "<<val<<" "<<st.size()<<" "<<tmp.size()<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}