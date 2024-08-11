#include <bits/stdc++.h>
using namespace std;

#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
bool vis[100010];
int C,T;
char mpop[100010];
int mpa[100010],mpb[100010];
void ca34(){
	while(T--){
		memset(vis,0,sizeof vis);
		int n,m;
		cin >> n >>  m;
		int ans=0;
		fr(i,1,m){
			char v;
			int t;
			cin >>  v >> t;
			if(v=='U'){
				if(!vis[t])ans++;
				vis[t]=1;
			}	
			else{
				if(vis[t])ans--;
				vis[t]=0;
			}
		}
		cout << ans << endl;
	}
}
void ca56(){
	while(T--){
		memset(vis,0,sizeof vis);
		int n,m;
		cin >> n >>  m;
		int ans=0;
		fr(i,1,m){
			cin >> mpop[i];
			if(mpop[i]=='U')cin >> mpa[i];
			else cin >> mpa[i] >> mpb[i];
		}
		int last=-1;
		bool flag=1;
		while(ans!=last){
			if(flag)flag=0;
			else last=ans;
			fr(i,1,m){
				char op;
				int t;
				op=mpop[i];
				//cout << op << " ";
				if(op=='U'){
					t=mpa[i];
					if(!vis[t])ans++;
					vis[t]=1;
				}	
				else{
					int u,v;
					v=mpa[i],u=mpb[i];
					if(vis[u]&&!vis[v])ans++;
					if(!vis[u]&&vis[v])ans--;
					vis[v]=vis[u];
				}
			}
			
		}
		cout << ans << endl;
	}
}
int mpt[20],mp[20];
void ca12(){
	while(T--){
		int n,m;
		cin >> n >>  m;
		int tt=1;
		fr(i,1,m){
			cin >> mpop[i];
			if(mpop[i]=='U'||mpop[i]=='T'||mpop[i]=='F')cin >> mpa[i];
			else cin >> mpa[i] >> mpb[i];
		}
		fr(i,1,n)tt*=3;
		int ans=0x3f3f3f3f;
		fr(t,0,tt-1){
			int ttmp=t,cnt=0;
			fr(i,1,n){
				mp[i]=ttmp%3;
				cnt+=mp[i]==2;
				mpt[i]=mp[i];
				ttmp/=3;
			}
			fr(i,1,m){
				if(mpop[i]=='U')
					mp[mpa[i]]=2;
				if(mpop[i]=='T')
					mp[mpa[i]]=1;
				if(mpop[i]=='F')
					mp[mpa[i]]=0;
				if(mpop[i]=='+')mp[mpa[i]]=mp[mpb[i]];
				if(mpop[i]=='-'){
					if(mp[mpb[i]]==2)mp[mpa[i]]=mp[mpb[i]];
					else mp[mpa[i]]=!mp[mpb[i]];
				}
			}
			bool flag=1;
			fr(i,1,n){
				if(mp[i]!=mpt[i])flag=0;
			}
			if(flag)ans=min(ans,cnt);
		}
		cout << ans << endl;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> C  >> T;
	if(C==1||C==2)
		ca12();
	else if(C==3||C==4)
		ca34();
	else if(C==5||C==6)
		ca56();
	else{
		cout << 0;
	}
	return 0;
}
