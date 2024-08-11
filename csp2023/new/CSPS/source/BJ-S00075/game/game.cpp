#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
string s;
stack<int>st;
bool check(int l,int r){
	while(!st.empty()) st.pop();
	//cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++){
		//cout<<s[i];
		if(st.empty()) st.push(i);
		else if(s[st.top()]!=s[i]) st.push(i);
		else st.pop();
	}
	//puts("");
	if(st.empty()) return true;
	else return false;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&n);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((j-i+1)%2==0&&check(i,j)) ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
