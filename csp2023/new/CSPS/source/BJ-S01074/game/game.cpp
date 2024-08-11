#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000020,S=1000000000;
int n,ans=0,top=0,stk[N],s1,s2,s3,s4;
int mod[12]={1,100111001,100050001,998244853,998244353};
int bas[12]={1,37,43,61,53};
char c[N];
map<pair<int,int>,int>mp;
int qpow(int m,int p,int mod){
	int res=1;
	while(p>0){
		if(p%2==1) res=res*m%mod;
		m=m*m%mod;
		p/=2;
	}
	return res;
}
void upd(int typ,int x){
	int s5=0,s6=0,s7=0;
	s6=s1%S,s7=s1/S;
	s5=x*typ*qpow(bas[1],top,mod[1])%mod[1];
	s6=(s6+s5+mod[1])%mod[1];
	s5=x*typ*qpow(bas[2],top,mod[2])%mod[2];
	s7=(s7+s5+mod[2])%mod[2];
	s1=s6+s7*S;

	s6=s2%S,s7=s2/S;
	s5=x*typ*qpow(bas[3],top,mod[3])%mod[3];
	s6=(s6+s5+mod[3])%mod[3];
	s5=x*typ*qpow(bas[4],top,mod[4])%mod[4];
	s7=(s7+s5+mod[4])%mod[4];
	s2=s6+s7*S;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	mp[make_pair(0,0)]=1;
	s1=s2=0;
	for(int i=1;i<=n;i++){
		s3=0;
		if(top==0 or stk[top]!=c[i]-'a'+1) top++,upd(1,c[i]-'a'+1),stk[top]=c[i]-'a'+1;
		else upd(-1,c[i]-'a'+1),top--;
		ans+=mp[make_pair(s1,s2)];
		mp[make_pair(s1,s2)]++;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
 * dont judge my obviously wrong hashing methods >:(
 * 
 * ive never learned it before
 * 
 * i reached <a_moderate_amount_of_cfratings> without any hashes anyways so i thought it doesnt matter
 * 
 * (remember kids that absolutely learning nothing also gets you 2200+ cf ratings :P )
 */
