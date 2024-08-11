#include<bits/stdc++.h>
using namespace std;
const int N=805;
int n,ans;
string s;
bool vis[N][N];
int have(string tmp){
	int len=tmp.size();
	for(int i=2;i<=len;i++){
		if(tmp[i]==tmp[i-1]){
			return i-1;
		}
	}
	return -1;
}
bool check(string tmp){
	int res=have(tmp);
	//cout<<res<<' ';
	while(res!=-1){
		tmp.replace(res,2,"");
		res=have(tmp);
	}
	return tmp.size()==1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	s=" "+s;
	for(int i=1;i<n;i++){
		if(s[i]==s[i+1]){
			vis[i][i+1]=1;
		}
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			string tmp=s.substr(i,len);
			tmp=" "+tmp;
			if(check(tmp)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
