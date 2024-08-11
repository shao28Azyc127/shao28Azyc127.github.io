#include<iostream>
#include<vector>
using namespace std;
struct value
{
	bool is;
	int var;
	value(){}
	value(bool is,int var):is(is),var(var){}
	value operator ^ (int x){return value(is^x,var);}
};
vector<pair<int,bool>> g[100005];
value val[100005];
int color[100005];
bool vis[100005];
bool hasring;
int dfs(int u,bool c)
{
	if(vis[u] && color[u]!=c)	hasring=1;
	if(vis[u])	return 0;
	color[u]=c;
	vis[u]=1;
	int ans=1;
	for(auto e:g[u])
		ans+=dfs(e.first,c^e.second);
	return ans;
}
void mian()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	val[i]=value(1,i);
	for(int i=0;i<=n+1;i++)	g[i].clear(),vis[i]=0;
	for(int i=0;i<m;i++)
	{
		char ch;
		int x,y;
		cin>>ch;
		if(ch=='T' || ch=='F')	cin>>x,val[x]=value((ch=='F'),0);
		if(ch=='+' || ch=='-')	cin>>x>>y,val[x]=(val[y]^(ch=='-'));
		if(ch=='U')	cin>>x,val[x]=value(0,n+1);
	}
	for(int i=1;i<=n;i++)
		g[i].emplace_back(val[i].var,!val[i].is),
		g[val[i].var].emplace_back(i,!val[i].is);
	dfs(0,0);
	int ans=dfs(n+1,0)-1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			hasring=0,ans+=dfs(i,0)*hasring;
	cout<<ans<<endl;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)	mian();
}
/*
import requests
import time
import json
import sys	
head={"Cookie": "JSESSIONID=0F2EBBDF4500D4D68C830391421A67A6; JSE=USMH9e2gQY; lang=zh"}
while True:
	r=requests.get('http://172.17.21.100/user.CheckStarted.dt',headers=head)
	j=json.loads(r.text)
	left=int(j['timeleft'])
	if left<=0:
		break
	seconds=left%60
	if seconds<10:
		seconds='0'+str(seconds)
	left=left//60
	minutes=left%60
	if minutes<10:
		minutes='0'+str(minutes)
	hours=left//60
	print('\033c',end='')
	if hours:
		print(hours,minutes,seconds,sep=':',end='')
	else:
		print(minutes,seconds,sep=':',end='')
	print(' left to the end of the world!')
	time.sleep(0.2)
while True:
	print('\033cThe world has ended!')
	time.sleep(0.2)
*/