#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,fl1,fl2,fl3,fl4,lst=-1;
int op[105],now;
int k[105],sz[105];
int l[105],r[105];
map<string,int> mp;
map<int,string> mp1;
map<string,pair<int,int> > mp2;
string t[105][105],t1[105][105];
string s[105],s1[105];
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	mp2["byte"]=make_pair(1,1);
	mp2["short"]=make_pair(2,2);
	mp2["int"]=make_pair(4,4);
	mp2["long"]=make_pair(8,8);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>op[i];
		if(op[i]==1)
		{
			fl1++;
			cin>>s[i]>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>t[i][j]>>t1[i][j];
				if(t[i][j]!="byte"&&t[i][j]!="short"
				&&t[i][j]!="int"&&t[i][j]!="long") fl3=1;
			}
		}
		if(op[i]==2) cin>>s[i]>>s1[i];
		if(op[i]==3) cin>>s[i];
		if(op[i]==4) cin>>k[i];
	}
	cout<<fl1<<' '<<fl2<<' '<<fl3<<' '<<fl4<<endl;
	if(!fl1)
	{
		for(int i=1;i<=n;i++)
		{
			if(op[i]==2)
			{
				mp[s1[i]]=++now;
				mp1[now]=s1[i];
				int x=0;
				if(s[i]=="byte") x=1;
				if(s[i]=="short") x=2;
				if(s[i]=="int") x=4;
				if(s[i]=="long") x=8;
				l[now]=lst+1+x-(lst+x)%x-1;
				r[now]=l[now]+x-1;
				lst=r[now];
				cout<<l[now]<<endl;
			}
			if(op[i]==3)
			{
				cout<<l[mp[s[i]]]<<endl;
			}
			if(op[i]==4)
			{
				int ll=1,rr=now,ans=-1;
				while(ll<=rr)
				{
					int mid=(ll+rr)/2;
					if(l[mid]<=k[i]&&r[mid]>=k[i])
					{
						ans=mid;
						break;
					}
					if(l[mid]>k[i]) rr=mid-1;
					else ll=mid+1;
				}
				if(ans==-1) cout<<"ERR\n";
				else cout<<mp1[ans]<<endl;
			}
		}
	}
	// if(!fl3)
	// {
	// 	for(int i=1;i<=n;i++)
	// 	{
	// 		if(op[i]==1)
	// 		{
	// 			int maxn=0;
	// 			int ls=-1;
	// 			for(int j=1;j<=k[i];j++)
	// 			{
	// 				int x=0;
	// 				if(t[i][j]=="byte") x=1;
	// 				if(t[i][j]=="short") x=2;
	// 				if(t[i][j]=="int") x=4;
	// 				if(t[i][j]=="long") x=8;
	// 				maxn=max(maxn,x);
	// 				ls=ls+1+x-(ls+x)%x-1+x-1;
	// 				cout<<ls<<endl;
	// 			}
	// 			ls=ls+maxn-(ls+maxn)%maxn-1;
	// 			cout<<ls+1<<' '<<maxn<<endl;
	// 			mp2[s[i]]=make_pair(ls+1,maxn);
	// 		}
	// 		if(op[i]==2)
	// 		{
	// 			mp[s1[i]]=++now;
	// 			mp1[now]=s1[i];
	// 			int x=mp2[s[i]].first,y=mp2[s[i]].second;
	// 			l[now]=lst+1+y-(lst+y)%y-1;
	// 			r[now]=l[now]+x-1;
	// 			lst=r[now];
	// 			cout<<l[now]<<endl;
	// 		}
	// 	}
	// }
}