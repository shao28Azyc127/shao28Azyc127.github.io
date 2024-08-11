#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define maxn 200008
using namespace std;
struct node{
	int l,r;
}a[maxn];
struct xx{
	char c;
	int id;
};
vector<int> mp[maxn];
string s;
int ans;
bool chk(int l,int r){
	for(int i=0;i<(int)mp[l].size();i++){
		if(mp[l][i]==r) return false;
	}
	return true;
}
void dfs(int l,int x){//cout<<"ok";
	
	for(int i=0;i<(int)mp[x].size();i++){
		if(chk(l,mp[x][i])==false) continue;
		//cout<<mp[x][i]<<" ";
		ans++;
		mp[l].push_back(mp[x][i]);
		dfs(l,mp[x][i]+1);
	}
}
int main(){	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	cin>>s;
	
	for(int i=0;i<n-1;i++){
		int l=i,r=i+1;
		while(l>=0&&r<n&&s[l]==s[r]){
			mp[l].push_back(r);
			a[++cnt].l=l;
			a[cnt].r=r;
			l--;
			r++;
		}
	}
	stack<xx> st;
	for(int i=0;i<n;i++){
		if(!st.empty()&&st.top().c==s[i]){
			if(chk(st.top().id,i)){
				a[++cnt].l=st.top().id;
				a[cnt].r=i;
				mp[a[cnt].l].push_back(a[cnt].r);
			}
			st.pop();
		}
		else{
			st.push(xx{s[i],i});
		}
	}
	ans=cnt;
//	cout<<cnt<<endl;
	//for(int i=1;i<=cnt;i++){
	//	cout<<a[i].l<<" "<<a[i].r<<":";
	//	dfs(a[i].l,a[i].r+1);
	//	cout<<endl;
	//}
	for(int i=0;i<n;i++){
		for(int j=0;j<(int)mp[i].size();j++){
			dfs(i,mp[i][j]+1);
		}
	}
	cout<<ans;
	return 0;
}
