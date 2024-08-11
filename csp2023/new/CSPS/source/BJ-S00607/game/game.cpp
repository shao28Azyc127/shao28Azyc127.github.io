#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int nxt[2000010];
int main(){
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>s;s=' '+s;long long ans=0;
	for(int i=1;i<=n;++i)nxt[i]=i+1;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;j+=2){
			for(int k=i;k<=j;++k)nxt[k]=k+1;
			nxt[0]=i;
			while(nxt[0]<=j){
				int nw=0;bool flg=0;
				while(nxt[nxt[nw]]<=j){
					if(s[nxt[nw]]==s[nxt[nxt[nw]]]){
						nxt[nw]=nxt[nxt[nxt[nw]]];
						flg=1;
						break;
					}
					nw=nxt[nw];
				}
				if(!flg)break;
			}
			ans+=nxt[0]>j;
		}
	}
	cout<<ans<<endl;
	return 0;
}