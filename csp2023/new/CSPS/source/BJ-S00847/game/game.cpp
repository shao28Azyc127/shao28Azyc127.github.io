#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
char s[(int)(2e6+10)];
int res=0;
const int mod=1e9+7;
const int mod1=1e9+9;
struct node
{
	char c;
	int hs,hs1;
};
stack<node>st;
map<int,int>mp;
void get(int l,int r)
{
	int cnt=0;
	if(l>=r) return ;
	int mid=(l+r)>>1;
	for(int i=mid+1;i<=r;i++)
	{
		if(!st.empty()&&s[i]==st.top().c) 
		{
			st.pop();
			if(st.empty()) mp[0]++;
			else mp[st.top().hs*st.top().hs1]++;
		}
		else
		{
			int h,h1;
			if(st.empty()) h=h1=0;
			else h=st.top().hs,h1=st.top().hs1;
			st.push((node){s[i],(h*27ll%mod+s[i])%mod,(h1*27ll%mod1+s[i])%mod1});
			mp[st.top().hs*st.top().hs1]++;
		}
	}
	while(!st.empty()) st.pop();
	for(int i=mid;i>=l;i--)
	{
		if(!st.empty()&&s[i]==st.top().c)
		{
			st.pop();
			if(st.empty()) cnt+=mp[0];
			else cnt+=mp[st.top().hs*st.top().hs1];
		}
		else
		{
			int h,h1;
			if(st.empty()) h=h1=0;
			else h=st.top().hs,h1=st.top().hs1;
			st.push((node){s[i],(h*27ll%mod+s[i])%mod,(h1*27ll%mod1+s[i])%mod1});
			cnt+=mp[st.top().hs*st.top().hs1];
		}
	}
	while(!st.empty()) st.pop();
	mp.clear();
	get(l,mid);get(mid+1,r);
	res+=cnt;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>(s+1);
	get(1,n);
	cout<<res;
}