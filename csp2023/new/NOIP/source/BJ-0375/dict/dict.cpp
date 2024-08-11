#include<bits/stdc++.h>
using namespace std;
int n,m,len[3005][30],mxn[3005],mxx[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	if(n==1){cout<<"1\n";return 0;}
	for(int i=1;i<=n;++i){
		string s;cin>>s;
		mxx[i]=-100;mxn[i]=100;
		for(char c:s){
			++len[i][c-'a'];
			mxx[i]=max(mxx[i],c-'a');
			mxn[i]=min(mxn[i],c-'a');
		}
	}
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(j!=i){
				if(mxn[i]<mxx[j])++cnt;
				else break;
			}
		}
		if(cnt==n-1)cout<<"1";
		else cout<<"0";
	}
	cout<<'\n';
	return 0;
}//ฝ๐าร