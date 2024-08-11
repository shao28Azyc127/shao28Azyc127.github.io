#include <bits/stdc++.h>
#include <string>
#include <map>
using namespace std;
#define endl "\n"
int n;
string s;
string now;
unordered_map<string,int> m;
string null;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long ans=0;
	cin>>n;
	cin>>s;
	m[null]=1;
	for(char c:s){
		if(now.size()==0) {
			now.push_back(c);
			ans+=m[now];
			m[now]+=1;
			continue;
		}
		if(c==now[now.size()-1]) now.erase(now.size()-1);
		else now.push_back(c);
		ans+=m[now];
		m[now]+=1;
	}
	cout<<ans<<endl;
	return 0;
}
