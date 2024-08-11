#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<pair<string,string>> vec;
struct Str
{
    vector<pair<string,string>> gt;
    int siz,dq;
}; map<string,Str> mp;
signed main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
    Str basic; basic.siz=basic.dq=1;
    mp["byte"]=basic;
    basic.siz=basic.dq=2;
    mp["short"]=basic;
    basic.siz=basic.dq=4;
    mp["int"]=basic;
    basic.siz=basic.dq=8;
    mp["long"]=basic;
    int nowlen=0;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int op; cin>>op;
        if(op==1)
        {
            string ss; int k; cin>>ss>>k;
            Str nows; nows.siz=nows.dq=0;
            for(int j=1; j<=k; ++j)
            {
                string x1,x2; cin>>x1>>x2;
                nows.gt.push_back({x1,x2});
                nows.dq=max(nows.dq,mp[x1].dq);
                while(nows.siz%mp[x1].dq!=0) ++nows.siz;
                nows.siz+=mp[x1].siz;
            }
            while(nows.siz%nows.dq!=0) ++nows.siz;
            mp[ss]=nows;
            cout<<nows.siz<<' '<<nows.dq<<'\n';
        }
        if(op==2)
        {
            string s1,s2; cin>>s1>>s2;
            vec.push_back({s1,s2});
            while(nowlen%mp[s1].dq!=0) ++nowlen;
            cout<<nowlen<<'\n';
            nowlen+=mp[s1].siz;
        }
        if(op==3)
        {
            string s; cin>>s;
            vector<string> vecs;
            for(int i=0; i<s.size(); ++i)
            {
                int now=i;
                while(now<s.size() && s[now]!='.') ++now;
                vecs.push_back(s.substr(i,now-i));
                i=now;
            }
            int wz=0;
            string now;
            for(auto i:vec)
            {
            	while(wz%mp[i.first].dq!=0) ++wz;
            	if(i.second==vecs[0]) { now=i.first; break; }
            	wz+=mp[i.first].siz;
			}
			for(int i=1; i<vecs.size(); ++i)
			{
				for(auto j:mp[now].gt)
				{
					while(wz%mp[j.first].dq!=0) ++wz;
					if(j.second==vecs[i]) { now=j.first; break; }
					wz+=mp[j.first].siz;
				}
			}
			cout<<wz<<'\n';
        }
        if(op==4)
        {
        	int wz; cin>>wz;
        	int nowwz=0;
        	string now;
        	bool flag=0,vis=0;
        	string ans;
			for(auto i:vec)
        	{
        		while(nowwz%mp[i.first].dq!=0) ++nowwz;
        		if(nowwz>wz) { flag=1; break; }
        		if(nowwz+mp[i.first].siz>wz) { now=i.first; vis=1; ans=i.second; break; }
        		nowwz+=mp[i.first].siz;
			}
			if(!vis) flag=1;
			if(flag) { cout<<"ERR\n"; continue; }
			while(!flag && mp[now].gt.size()!=0)
			{
				bool vis=0;
				for(auto i:mp[now].gt)
				{
					while(nowwz%mp[i.first].dq!=0) ++nowwz;
					if(nowwz>wz) { flag=1; break; }
					if(nowwz+mp[i.first].siz>wz) { ans+='.'+i.second,now=i.first; vis=1; break; }
					nowwz+=mp[i.first].siz;
				}
				if(!vis) flag=1;
			}
			if(flag) { cout<<"ERR\n"; continue; }
			cout<<ans<<'\n';
		}
    }
    return 0;
}