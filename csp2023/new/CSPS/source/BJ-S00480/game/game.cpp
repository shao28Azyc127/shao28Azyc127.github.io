#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<iostream>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=2401141;
void fre(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}
int n,nxt[maxn],lst[maxn],dp[maxn],pos[30];
bool fl[maxn],p[maxn];
string s;
bool check(string pp){
	string t=pp;
	while(1){
		bool fl=1;
		int len=t.size();
		F(i,0,len-1) p[i]=1;
		F(i,0,len-2) if(t[i]==t[i+1]) p[i]=p[i+1]=0,fl=0,i++;
		string nxt;
		F(i,0,len-1) if(p[i]) nxt+=t[i];
		t=nxt;
		if(fl) break;
	}
	return t.empty();
}
namespace subtask1{
	void solve(){
		F(i,2,n){
			string cur;
			dF(j,i,1){
				cur+=s[j];
				if(check(cur)) dp[i]++;
			}
		}
		ll ans=0;
		F(i,2,n) ans+=dp[i];
		cout<<ans;
	}
}
signed main(){
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	s=" "+s;
	ll ans=0;
	F(i,0,26) pos[i]=0;
	F(i,1,n){
		int c=s[i]-'a'+1;
		lst[i]=pos[c];
		pos[c]=i;
	}
	if(n<=800) return subtask1::solve(),0;
	F(i,1,n){
		//sb
		int k=lst[i];
		if((i-k+1)%2){fl[i]=0; continue;}
		if(!k){fl[i]=0; continue;}
		if(k==i-1) fl[i]=1;
		else{
			fl[i]=1;
			int p=i-1;
			while(p>=k){
				if(s[i]==s[p]) break;
				if(!fl[p]){
					fl[i]=0;
					break;
				}
				p=lst[p]-1;
			}
		}
	}
	/*F(i,2,n){
		int k=lst[i];
		if((i-k+1)%2){fl[i]=0; continue;}
		if(!k){fl[i]=0; continue;}
		if(k==i-1) fl[i]=1;
		else{
			string cur;
			F(j,k,i) cur+=s[j];
			fl[i]=check(cur);
		}
	}*/
	F(i,1,n) if(fl[i]) dp[i]=dp[lst[i]-1]+1;
	// puts("onehow");
	F(i,1,n) ans+=dp[i];
	cout<<ans;
}
