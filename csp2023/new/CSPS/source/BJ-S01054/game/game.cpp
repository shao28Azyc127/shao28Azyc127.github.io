#include<bits/stdc++.h>
using namespace std;
vector<int>ve[50005];
int n,cnt;
string s;
void dfs(int l,int r){
	if(l>0&&r<n-1&&s[l-1]==s[r+1]){
		ve[l-1].push_back(r+1);
		dfs(l-1,r+1);
	}
	if(r<n-1&&ve[r+1].size()){
		for(int i=0;i<ve[r+1].size();i++){
			ve[l].push_back(ve[r+1][i]);
			dfs(l,ve[r+1][i]);
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w,",stdout);
	cin>>n;
	cin>>s;
	for(int i=n;i>=0;i--){
		if(s[i]==s[i+1]){
			ve[i].push_back(i+1);
			dfs(i,i+1);
		}
	}
	for(int i=0;i<n;i++){
		//for(auto v:ve[i]){
		//	for(int j=i;j<=v;j++)cout<<s[j];
		//	cout<<" ";
		//}
		cnt+=ve[i].size();
		//cout<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}

/*
可消除的子串+可消除的子串=可消除的子串
c+可消除的子串+c=可消除的子串
其中c为任意字母
*/