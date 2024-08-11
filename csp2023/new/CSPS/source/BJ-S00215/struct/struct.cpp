#include<bits/stdc++.h>
using namespace std;
namespace SOLUTION{
	typedef long long ll;
	typedef pair<int,int> PII;
	const int N=105;
	struct STRUCT{
		unordered_map<string,int> pos;
		ll st=0,size=0,dq=0;
		vector<PII> mem;
		vector<string> name;
	};
	map<string,STRUCT> nam,mp;
	map<ll,string> it;
	int n,op,k;
	ll nwmem;
	string type,s,name;
	inline void init(){
		STRUCT res;
		res.pos["#"]=0;
		res.mem.push_back({0,0}),res.size=res.dq=1;
		nam["byte"]=res;
		res.mem.back().second=1,res.size=res.dq=2;
		nam["short"]=res;
		res.mem.back().second=3,res.size=res.dq=4;
		nam["int"]=res;
		res.mem.back().second=7,res.size=res.dq=8;
		nam["long"]=res;
	}
	bool dfs(STRUCT nw,int tar,string &ans){
		if(nw.mem.size()==1){
			int l=nw.mem[0].first,r=nw.mem[0].second;
			return l<=tar&&r>=tar;
		}for(int i=0;i<nw.mem.size();i++){
			int l=nw.mem[i].first,r=nw.mem[i].second;
			if(l>tar)	return 0;
			else if(l<=tar&&r>=tar){
				ans+="."+nw.name[i];
				return dfs(mp[nw.name[i]],tar-l,ans);
			}
		}return 0;
	}
	ll dfs2(STRUCT nw,string s){
		int flag=0;string t;
		for(int i=0;i<s.size();i++)
			if(s[i]=='.'){
				t=s.substr(0,i);
				flag=i;
				break;
			}
		if(!flag)	return nw.st+nw.mem[nw.pos[s]].first;
		else	return nw.st+nw.mem[nw.pos[t]].first+dfs2(mp[t],s.substr(flag+1,s.size()-flag));
	}
	int main(){
		cin>>n;
		init();
		while(n--){
			cin>>op;
			if(op==1){
				cin>>s>>k;
				STRUCT res;
				for(int i=0;i<k;i++){
					cin>>type>>name;
					res.pos[name]=i;
					res.name.push_back(name);
					int lstmem=i?res.mem.back().second:0;
					STRUCT nw=nam[type];
					mp[name]=nw;
					res.dq=max(res.dq,nw.dq);
					int nwst=lstmem;
					if(i)	nwst+=(nw.dq-lstmem%nw.dq);
					res.mem.push_back({nwst,nwst+nw.size-1});
				}int lst=res.mem.back().second;
				lst+=res.dq-lst%res.dq;
				res.size=lst;
				nam[s]=res;
				cout<<res.size<<' '<<res.dq<<'\n';
			}else if(op==2){
				cin>>type>>name;
				STRUCT res=nam[type];
				if(nwmem)	nwmem+=res.dq-nwmem%res.dq;
				res.st=nwmem,mp[name]=res;
				for(int i=nwmem;i<=nwmem+res.size-1;i++)	it[i]=name;
				cout<<nwmem<<'\n';
				nwmem+=res.size-1;
			}else if(op==3){
				cin>>s;
				int i;
				for(i=0;i<s.size();i++)if(s[i]=='.')break;
				if(i>=s.size())	cout<<mp[s].st<<'\n';
				else	cout<<dfs2(mp[s.substr(0,i)],s.substr(i+1,s.size()-i))<<'\n';
			}else if(op==4){
				cin>>k;
				if(it.count(k)){
					string ans=it[k];
					STRUCT res=mp[ans];
					if(dfs(res,k,ans))	cout<<ans<<'\n';
					else	cout<<"ERR\n";
				}else	cout<<"ERR\n";
			}
		}
		return 0;
	}
}
int main(){
	 freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return SOLUTION::main();
}
