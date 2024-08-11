#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
string s[N];
char gr[N],le[N];
int n,m;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) le[i]=char('z'+1),gr[i]=char('a'-1);
	for(int i=1;i<=n;i++){
		int ls=s[i].size();
		for(int j=0;j<ls;j++)
			gr[i]=max(gr[i],s[i][j]),le[i]=min(le[i],s[i][j]);
	}
	for(int i=1;i<=n;i++){
		bool flg=0;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(le[i]>gr[j]) flg=1;
				if(le[i]==gr[j] && gr[i]>=gr[j]) flg=1;
			}
		}
		cout<<(!flg);
	}
	return 0;
}
