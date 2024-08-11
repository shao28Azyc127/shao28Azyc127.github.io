#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
unordered_set<int>nwmp;
int hsh(const vector<int>&x){
	int ans=0;
	for(auto i:x)ans=ans*10+i;
	return ans;
}
int main(){
	freopen("lock.in","r",stdin),freopen("lock.out","w",stdout);
	int n;cin>>n;mp.reserve(10000),nwmp.reserve(10000);
	for(int i=1;i<=n;++i){
		int nw=0;vector<int>x;nwmp.clear();
		for(int j=0,t;j<5;++j)cin>>t,x.push_back(t);
		for(int j=0;j<5;++j){
			vector<int>y=x;
			for(int k=0;k<10;++k)if(k^x[j]){
				int h=hsh(y);
				y[j]=k,++mp[h],nwmp.insert(h);
			}
		}
		for(int j=0;j<4;++j){
			vector<int>y=x;
			for(int k=1;k<10;++k){
				(++y[j])%=10,(++y[j+1])%=10;
				int h=hsh(y);
				if(!nwmp.count(h))++mp[h];
			}
		}
	}
	long long ans=0;
	for(auto i:mp)if(i.second>=n)++ans;
	cout<<ans<<endl;
	return 0;
}