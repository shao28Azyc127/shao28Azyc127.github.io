#include <bits/stdc++.h>
using namespace std;
map<string,long long >mym;
map<long long,string >mymt; 
long long ncnt=0;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	vector<long long> v;
	int q;
	long long maxn=0,n;
	string s,st,ss;
	cin>>q;
	mym["byte"]=1;
	mym["short"]=2;
	mym["int"]=4;
	mym["long"]=8;
	for(int i=1,typ;i<=q;i++)
	{
		cin>>typ;
		if(typ==1)
		{
			cin>>s>>n;
			maxn=0;
			for(int j=1;j<=n;j++)
			{
				cin>>st>>ss;
				maxn=max(maxn,mym[st]);
			}
			mym[s]=maxn*n;
			cout<<mym[s]<<" "<<maxn<<endl;
		}
		else if(typ==2)
		{
			cin>>st>>ss;
			mym[ss]=ncnt;
			mymt[ncnt]=ss;
			v.push_back(ncnt);
			cout<<ncnt<<endl;
			ncnt+=mym[st];
		}
		else if(typ==3)
		{
			cin>>st;
			cout<<mym[st]<<endl;
		}
		else
		{
			cin>>n;
			maxn=0;
			for(int i=0;i<v.size();i++)
			{
				if(v[i]<n)
					maxn=v[i];
				else
					break;
			}
			cout<<mymt[maxn]<<endl;
		}
	}
	return 0;
}