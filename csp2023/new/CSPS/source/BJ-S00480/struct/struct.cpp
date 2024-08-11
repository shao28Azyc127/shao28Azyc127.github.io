#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<iostream>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
void fre(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
}
const int maxn=100005;
ll cur=-1,dq=-1,qs=-1;
map<ll,string>ans;
string rev[maxn];
map<string,int>getid;
ll g[maxn];
void solve1(int i){
	
}
void solve2(int i){
	string s,t;
	cin>>s>>t;
	rev[i]=t;
	getid[t]=i;
	if(s=="byte"){
		if(cur==-1) qs=cur=0;
		else qs=cur+1;
		ans[qs]=t;
		cur=qs;
	}
	if(s=="short"){
		if(cur==-1) qs=cur=0;
		else qs=(cur-(cur%2))+2;
		F(i,qs,qs+1) ans[i]=t;
		cur=qs+1;
	}
	if(s=="int"){
		if(cur==-1) qs=cur=0;
		else qs=(cur-(cur%4))+4;
		F(i,qs,qs+3) ans[i]=t;
		cur=qs+3;
	}
	if(s=="long"){
		if(cur==-1) qs=cur=0;
		else qs=(cur-(cur%8))+8;
		F(i,qs,qs+7) ans[i]=t;
		cur=qs+7;
	}
	g[i]=qs;
}
void solve3(){
	string s;
	cin>>s;
	int id=getid[s];
	cout<<g[id]<<endl;
}
void solve4(){
	ll x;
	cin>>x;
	if(!ans.count(x)) puts("ERR");
	else cout<<ans[x]<<endl;
}
signed main(){
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	F(i,1,n){
		int op;
		cin>>op;
		if(op==1) solve1(i);
		if(op==2) solve2(i);
		if(op==3) solve3();
		if(op==4) solve4();
	}
}
