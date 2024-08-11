#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
const int N=2e6+7;
int n;
string s, str;
int cnt[N][26];
map<string, bool> ma;
bool pd(string t){
	while(t.size()){
		bool f=1;
		for(int i=0;i+1<t.size();i++){
			if(t[i]==t[i+1]){
				f=0;
				t.erase(t.begin()+i);
				t.erase(t.begin()+i);
				i--;
			}
		}
		if(f)
			return 0;
	}
	return 1;
}
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n>>s;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			cnt[i][j]=cnt[i-1][j]+(s[i-1]==(j+'a'));
		}
	}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			bool f=1;
			for(int k=0;k<26;k++){
				if((cnt[j+1][k]-cnt[i][k])%2==1)
					f=0;
			}
			if(f){
				str=s.substr(i, j-i+1);
				if(!ma[str])
					ma[str]=pd(str);
				ans+=1LL*ma[str];
			}
		}
	cout<<ans<<endl;
	return 0;
}