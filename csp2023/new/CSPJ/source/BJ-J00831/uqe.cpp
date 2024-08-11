#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,m;
unordered_map<int,int>mp;
ll check(ll x){
	if(!x)return 0;
	if(x<=1000000)return mp[x]?mp[x]:-1;
	ll t=sqrtl(x);
	for(ll i=t-20;i<=t+20;++i)if(i*i==x)return i;
	return -1;
}
pair<ll,ll>get(ll x){
	pair<ll,ll>ans={1,1};
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			ll num=0;
			while(x%i==0)x/=i,++num;
			for(int j=1;j*2<=num;++j)ans.first*=i;
			if(num&1)ans.second*=i;
		}
	}
	if(x>1)ans.second*=x;
	return ans;
}
ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
void out(ll a,ll b){//	a/b
	if(a==0){cout<<"0";return;}
	int f=(a<0)^(b<0);
	if(a<0)a=-a;
	if(b<0)b=-b;
	ll x=gcd(a,b);a/=x,b/=x;
	if(b==1){
		if(f)cout<<"-";
		cout<<a;
	}
	else{
		if(f)cout<<"-";
		cout<<a<<"/"<<b;
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t>>m;mp.reserve(1000),mp.max_load_factor(0.125);
	for(ll i=1;i<=1000;++i)mp[i*i]=i;
	while(t--){
		ll a,b,c;cin>>a>>b>>c;
		ll delta=b*b-4*a*c;
		if(delta<0){cout<<"NO\n";continue;}
		ll sqd=check(delta);
		if(sqd!=-1){
			if(a<0)out(-b-sqd,2*a);
			else out(-b+sqd,2*a);
		}
		else{
			bool flg=0;
			if(b)out(-b,2*a),flg=1;
			if(a>0){
				pair<ll,ll>ans=get(delta);
				ll g=gcd(abs(ans.first),abs(2*a)),fm=2*a;
				ans.first/=g,fm/=g;
				if(ans.first<0)fm=-fm,ans.first=-ans.first;
				if(ans.first==1){
					if(fm<0)cout<<"-sqrt("<<ans.second<<")";
					else{
						if(flg)cout<<"+";
						cout<<"sqrt("<<ans.second<<")";
					}
					if(abs(fm)!=1)cout<<"/"<<abs(fm);
				}
				else{
					if(fm>0){
						if(flg)cout<<"+";
						cout<<ans.first<<"*sqrt("<<ans.second<<")";
					}
					else{
						cout<<"-"<<ans.first<<"*sqrt("<<ans.second<<")";
					}
					if(abs(fm)!=1)cout<<"/"<<abs(fm);
				}
			}
			else{
				pair<ll,ll>ans=get(delta);
				ll g=gcd(abs(ans.first),abs(2*a)),fm=2*a;
				ans.first/=g,fm/=g;
				if(ans.first<0)fm=-fm,ans.first=-ans.first;
				if(ans.first==1){
					if(fm>0)cout<<"-sqrt("<<ans.second<<")";
					else{
						if(flg)cout<<"+";
						cout<<"sqrt("<<ans.second<<")";
					}
					if(abs(fm)!=1)cout<<"/"<<abs(fm);
				}
				else{
					if(fm<0){
						if(flg)cout<<"+";
						cout<<ans.first<<"*sqrt("<<ans.second<<")";
					}
					else{
						cout<<"-"<<ans.first<<"*sqrt("<<ans.second<<")";
					}
					if(abs(fm)!=1)cout<<"/"<<abs(fm);
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}