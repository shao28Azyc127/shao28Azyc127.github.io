#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int N=1e5+50;
struct node
{
	int id,t;
	node(int a,int b){
		id=a,t=b;
	}
	bool operator<(const node &y) const
	{
		if(t==y.t) return id<y.id;
		else return t<y.t;
	}
};
map<node,int> mp;
int fa[2*N],n,m,mxt[2*N],mxt1[2*N],v[2*N],cnt,idd[2*N];
bool same[2*N],u[2*N],uu[2*N];
int find_fa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=find_fa(fa[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=200020;i++) fa[i]=i,v[i]=-1;
		for(i=1;i<=n;i++) cnt++,same[i]=1,idd[i]=i,mp[node(i,0)]=cnt;
		for(i=1;i<=m;i++)
		{
			char op;
			cin>>op;
			if(op=='U'||op=='T'||op=='F'){
				int idx;
				cin>>idx;
				cnt++;
				mp[node(idx,i)]=cnt;
				idd[cnt]=idx;
				mxt[idx]=max(mxt[idx],i);
				same[cnt]=1;
				if(op=='T') v[cnt]=1;
				else if(op=='F') v[cnt]=0;
				else v[cnt]=2,mxt1[idx]=max(mxt1[idx],i);
			}
			else
			{
				int idi,idj;
				cin>>idi>>idj;
				//scanf("%d%d",&idi,&idj);
				cnt++;
				mp[node(idi,i)]=cnt;
				idd[cnt]=idi;
				if(op=='+') 
					same[cnt]=same[mp[node(idj,mxt[idj])]],v[cnt]=v[mp[node(idj,mxt[idj])]];
				else {
					same[cnt]=!same[mp[node(idj,mxt[idj])]];
					if(v[mp[node(idj,mxt[idj])]]==2||v[mp[node(idj,mxt[idj])]]==-1) v[cnt]=v[mp[node(idj,mxt[idj])]];
					else v[cnt]=!v[mp[node(idj,mxt[idj])]];
				}
				if(find_fa(mp[node(idi,i)])!=find_fa(mp[node(idj,mxt[idj])]))
					fa[mp[node(idi,i)]]=fa[mp[node(idj,mxt[idj])]];
				mxt[idi]=max(mxt[idi],i);
			}
		}
		for(i=1;i<=n;i++)
		{
			int id1=i,id2=idd[fa[mp[node(i,mxt[i])]]];
			//if(i==8)
		//		cout<<id1<<' '<<id2<<' '<<same[mp[node(i,mxt[i])]]<<endl;
			if((id1==id2&&same[mp[node(i,mxt[i])]]==0))
				u[fa[mp[node(i,mxt[i])]]]=1;
			if(mxt1[i]==mxt[i]&&v[mp[node(i,mxt[i])]]==2)
				uu[i]=1;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(v[mp[node(i,mxt[i])]]!=-1){
				if(v[mp[node(i,mxt[i])]]==2||u[fa[mp[node(i,mxt[i])]]]) ans++;
			}
			else if(u[fa[mp[node(i,mxt[i])]]]) ans++;
		}
		cout<<ans<<'\n';
		mp.clear();
		for(i=1;i<=200020;i++) mxt[i]=idd[i]=same[i]=u[i]=0,mxt1[i]=-1;
		cnt=0;
	}
	return 0;
}
