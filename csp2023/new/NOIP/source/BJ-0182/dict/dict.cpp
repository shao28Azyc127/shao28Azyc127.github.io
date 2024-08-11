#include<bits/stdc++.h>
using namespace std;

int n,m;
string s;
int cnt[30][3005];
int mi[3005],mx[3005];

bool check(int x){
	for(int i=1;i<=n;++i){
		if(i==x){
			continue;
		}
		if(mi[x]>mx[i]){
			return 0;
		}
		if(mi[x]==mx[i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s;
		mx[i]=-1;
		mi[i]=101;
		for(int j=1;j<=m;++j){
			++cnt[s[j-1]-'a'+1][i];
			mx[i]=max(mx[i],s[j-1]-'a'+1);
			mi[i]=min(mi[i],s[j-1]-'a'+1);
		}
	}
	for(int i=1;i<=n;++i){
		cout<<check(i);
	}
	return 0;
}
