#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,cnt[N][30];
char s[N];
inline bool check(int i,int j){
	int l=0,r=25;
	while(!cnt[i][l])	l++;
	while(!cnt[j][r])	r--;
	return l<r;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s+1;
		for(int j=1;j<=m;j++)	cnt[i][s[j]-'a']++;
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++)
			if(i!=j&&!check(i,j)){
				flag=0;
				break;
			}
		cout<<flag;
	}cout<<'\n';
	return 0;
}
