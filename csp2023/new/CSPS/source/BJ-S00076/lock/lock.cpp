#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
map<string,ll>mp;
map<string,bool>vis;
ll n;
string cg(string s,ll pos,ll x){
	string t=s;t[pos-1]=x+'0';return t;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=1;j<=5;j++){
			char c;scanf(" %c",&c);s+=c;
		}
		vis[s]=1;
		for(int j=1;j<=5;j++){
			for(int k=0;k<10;k++){
				if(s[j-1]==(k+'0'))continue;
				string t=s;
				t[j-1]=k+'0';
				mp[t]++;//ans1++;
				//cout<<t<<endl;
			}
		}
		for(int j=1;j<5;j++){
			for(int k=0;k<=10;k++){
				string t=s;
				ll k1=k+s[j-1]-'0',k2=k+s[j]-'0';
				k1%=10,k2%=10;
				if(s[j-1]==(k1+'0')&&s[j]==(k2+'0'))continue;
				t[j-1]=k1+'0';t[j]=k2+'0';
				//cout<<t<<endl;
				mp[t]++;
			}
		}
	}
	ll cnt=0;
	map<string,ll>::iterator it;
	for(it=mp.begin();it!=mp.end();it++){
		if((it->second)==n&& vis.find( (it->first))==vis.end()){
			cnt++;}
	}
	cout<<cnt;
	return 0;
}
