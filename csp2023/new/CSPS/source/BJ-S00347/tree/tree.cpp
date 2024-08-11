#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int N=100010;
int n,s[N],hs[N],fa[N],top[N],cnt=0,fin[N],d[N];
long long a[N],b[N],c[N],trans[N];
vector<int> g[N];
void dfs(int p,int rt){
	s[p]=1;
	top[p]=p;
	for(int i=0; i<g[p].size(); ++i){
		int tar=g[p][i];
		if(tar!=rt){
			fa[tar]=p;
			d[tar]=d[p]+1;
			dfs(tar,p);
			s[p]+=s[tar];
		}
	}
}
void dfs2(int p,int rt){
	hs[p]=0;
	d[p]=d[fa[p]]+1;
	for(int i=0; i<g[p].size(); ++i){
		int tar=g[p][i];
		if(tar!=rt && s[hs[p]]<s[tar])
			hs[p]=tar;
	}
	if(hs[p]){
		top[hs[p]]=top[p];
		dfs2(hs[p],p);
	}
	for(int i=0; i<g[p].size(); ++i){
		int tar=g[p][i];
		if(tar!=hs[p] && tar!=rt)
			dfs2(tar,p);
	}
}
long long fig(int i,long long s,long long t){
	if(c[i]>=0)
		return c[i]*(((s+t)*(t-s+1))/2)+b[i]*(t-s+1);
	else{
		if(t<=trans[i])
			return c[i]*(((s+t)*(t-s+1))/2)+b[i]*(t-s+1);
		else if(s>trans[i])
			return t-s+1;
		else
			return c[i]*(((s+trans[i])*(trans[i]-s+1))/2)+b[i]*(trans[i]-s+1)+t-trans[i];
	}
}
long long figlat(int i,long long t){
	long long l=1,r=t;
	while(l<r){
		long long mid=(l+r+1)>>1;
		if(fig(i,mid,t)>=a[i])
			l=mid;
		else
			r=mid-1;
		//cout << l << ' ' << r << endl;
	}
	return l;
}
int figt(int p){
	long long res=0;
	while(p!=1){
		if(fin[top[p]]==0){
			res+=d[p]-d[top[p]]+1;
			fin[top[p]]=p;
			p=fa[top[p]];
		}
		else if(d[p]<=d[fin[top[p]]])
			return res;
		else{
			res+=d[p]-d[fin[top[p]]];
			fin[top[p]]=p;
			return res;
		}
	}
	return 0;
}
bool check(long long t){
	memset(fin,0,sizeof(fin));
	fin[1]=1;
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	for(int i=1; i<=n; ++i)
		q.push(make_pair(figlat(i,t),i));
	long long nt=1;
	while(!q.empty()){
		int p=q.top().second;
		nt+=figt(p);
		//cout << q.top().second << ' ' << q.top().first << ' ' << nt << endl;
		if(nt>q.top().first)
			return 0;
		q.pop();
	}
	return 1;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%lld %lld %lld",a+i,b+i,c+i);
		if(c[i]<0){
			/*long long l=1,r=1000000000000;
			while(l<r){
				long long mid=(l+r+1)>>1;
				if(mid*c[i]+b[i]<=1)
					r=mid-1;
				else
					l=mid;
			}
			trans[i]=l;*/
			trans[i]=(1-b[i])/c[i];
		}
	}
	for(int i=1; i<n; ++i){
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	d[1]=1;
	dfs(1,0);
	dfs2(1,0);
	long long l=n,r=1000000000;
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
		//cout << endl;
	}
	printf("%lld\n",l);
	return 0;
}