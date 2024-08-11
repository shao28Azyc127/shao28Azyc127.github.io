#include <bits/stdc++.h>
using namespace std;

struct node
{
	string a;
	string b;
	long long startpos;
};

map <string,long long> sz,need,start;
map <string,vector<node> > link;
map <string,string> typ;

long long dfs(string s,string op,int pos,int len)
{
	if(pos>=len)
		return 0;

	string now;
	for(int i=pos;i<len;i++)
		if(op[i]=='.' || i==len-1)
		{
			if(op[i]!='.')
				now += op[i];

			for(auto x:link[s])
				if(x.b==now)
					return x.startpos+dfs(x.a,op,i+1,len);
		}
		else
			now += op[i];

	return 0;
}

vector <string> ans;

void dfs(string s,long long val)
{
	if(link[s].size()==0 && val<sz[s])
		return;

	if(link[s].size()==0 && val>=sz[s])
	{
		ans.clear();
		return;
	}

	vector <node> tmp=link[s];
	int lim=0;
	for(int i=0;i<tmp.size();i++)
		if(tmp[i].startpos<=val)
			lim=i;

	ans.push_back(tmp[lim].b);
	dfs(tmp[lim].a,val-tmp[lim].startpos);
}

string seq[105];

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	sz["long"]=need["long"]=8;
	sz["int"]=need["int"]=4;
	sz["short"]=need["short"]=2;
	sz["byte"]=need["byte"]=1;
	int n;
	cin >> n;

	long long nowlim=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin >> op;
		if(op==1)
		{
			string s;
			cin >> s;

			int k;
			cin >> k;
			long long nowpos=0,nowneed=0;
			for(int i=1;i<=k;i++)
			{
				string a,b;
				cin >> a >> b;
				nowpos=(nowpos+need[a]-1)/need[a]*need[a];
				link[s].push_back((node){a,b,nowpos});
				nowneed=max(nowneed,need[a]);
				nowpos += sz[a];
			}
			need[s]=nowneed, sz[s]=(nowpos+nowneed-1)/nowneed*nowneed;
			printf("%lld %lld\n",sz[s],need[s]);
		}
		else if(op==2)
		{
			string a,b;
			cin >> a >> b;
			typ[b]=a;
			start[b]=(nowlim+need[a]-1)/need[a]*need[a];
			printf("%lld\n",start[b]);
			nowlim=start[b]+sz[a];
			seq[++cnt]=b;
		}
		else if(op==3)
		{
			string s;
			cin >> s;
			int len=s.length();
			string now;

			bool haveans=false;
			for(int i=0;i<len;i++)
				if(s[i]=='.')
				{
					printf("%lld\n",start[now]+dfs(typ[now],s,i+1,len));
					haveans=true;
					break;
				}
				else
					now=now+s[i];

			if(!haveans)
				printf("%lld\n",start[now]);
		}
		else if(op==4)
		{
			long long pos,lim=0;
			cin >> pos;
			for(int i=1;i<=cnt;i++)
				if(start[seq[i]]<=pos)
					lim=i;

			ans.clear();
			ans.push_back(seq[lim]);
			dfs(typ[seq[lim]],pos-start[seq[lim]]);

			if(ans.size()==0)
				printf("ERR\n");
			else
			{
				for(int i=0;i<ans.size();i++)
				{
					if(i==ans.size()-1)
						cout << ans[i] << endl;
					else
						cout << ans[i] << '.';
				}
			}
		}
	}
	return 0;
}