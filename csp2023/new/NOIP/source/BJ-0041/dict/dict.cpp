//Ayaka bless me
#include <bits/stdc++.h>
#define rep(i,a,b,c)	for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)	for(int i=(a);i>=(b);i-=(c))
#define i64 long long
using namespace std;

const int mod=1e9+7;
const int maxn=5000;

int fpow(int a,int b){
	if(b==1)	return a;if(b==0)	return 1;
	int ans=fpow(a,b/2);ans*=ans;ans%=mod;
	if(b%2)	ans*=a;return ans%mod;
}	

int a[100],n;
int lowbit(int x){return x&(-x);}
void padd(int x,int val){
	while(x>0){
		a[x]+=val;x-=lowbit(x);
	}
}int qsum(int x){
	int ans=0;
	while(x<=n){
		ans+=a[x];x+=lowbit(x);
	}return ans;
}

string s[maxn];
int cnt[26][maxn];
int beg[maxn],ed[maxn];

int main(){ios::sync_with_stdio(0);cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;cin>>n>>m;
	rep(i,1,n,1){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		beg[i]=s[i][0],ed[i]=s[i][m-1];
	}rep(i,1,n,1){
		bool flg=1;
		rep(j,1,n,1){
			if(j==i)	continue ;
			if(ed[j]<beg[i]){
				flg=0;break ;
			}if(ed[j]==beg[i] && beg[j]!=beg[i]){
				flg=0;break ;
			}
		}cout<<flg;
	}
	return 0;
}