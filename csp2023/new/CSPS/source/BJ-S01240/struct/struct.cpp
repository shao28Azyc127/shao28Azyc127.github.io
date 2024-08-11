#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int n;
struct klass{
	string type,name;
};
struct suc;
struct suc{
	int rule=0;
	int cache=0;
	vector<klass> members;
};
unordered_map<string,suc> data;
suc init(suc a){
	
		for(klass kls:a.members){
				if(kls.type=="byte"){
					a.rule=max(a.rule,1ll);
				}
				if(kls.type=="short"){
					a.rule=max(a.rule,2ll);
				}
				if(kls.type=="int"){
					a.rule=max(a.rule,4ll);
					
				}
				if(kls.type=="long"){
					a.rule=max(a.rule,8ll);
					
				}
				else{
					suc tp = data[kls.type];
					a.rule=max(a.rule,tp.rule);
					
				}
			}
		for(klass kls:a.members){
			if(kls.type=="byte"){
				a.cache+=a.rule;
			}
			else if(kls.type=="short"){
				a.cache+=a.rule;
			}
			else if(kls.type=="int"){
				a.cache+=a.rule;
					
			}
			else if(kls.type=="long"){
				a.cache+=a.rule;	
			}
			else{
				suc tp = data[kls.type];
				a.cache+=tp.cache;
				if(a.cache%a.rule!=0) a.cache=(a.cache/a.rule+1)*a.rule;
			}
		}
		return a;
}
int getcache(klass kls){
	if(kls.type=="byte") return 1;
	if(kls.type=="short") return 2;
	if(kls.type=="int") return 4;
	if(kls.type=="long") return 8;
	return data[kls.type].cache;
}
vector<klass> mem;
int find(string name){
	for(int i=0;i<mem.size();i++){
		if(mem[i].name==name) return i;
	}
	return 0;
}
int getstartmem(string name){
	int ans=0;
	int to=find(name);
	for(int i=0;i<to;i++){
		ans+=getcache(mem[i]);
	}
	return ans;
}
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		if(op==1){
			string s;int k;
			suc tmp;
			cin>>s>>k;
			for(int i=1;i<=k;i++){
				string t,n;
				cin>>t>>n;
				tmp.members.push_back({t,n});
			}
			tmp=init(tmp);
			data.insert({s,tmp});
			cout<<tmp.cache<<" "<<tmp.rule<<endl;
		}
		if(op==2){
			string t,n;
			cin>>t>>n;
			mem.push_back({t,n});
			cout<<getstartmem(t)<<endl;
		}
		if(op==3){
			string s;
			cin>>s;
			string argv[105];
			int argc=1;
			for(char c:s){
				if(c=='.') argc++;
				else argv[argc].push_back(c);
			}
			int now=getstartmem(argv[1]);
			klass tmp=mem[find(argv[1])];
			for(int i=2;i<=argc;i++){
				suc cur=data[tmp.type];
				vector<klass> members=cur.members;
				for(klass kls:members){
					if(kls.name==argv[i]) {
						tmp=kls;
						break;
					}
					
					now+=cur.rule;
				}
			}
			cout<<now<<endl;
		}
		if(op==4){
			int addr;
			cin>>addr;
			int now=0;
			klass tmp;
			bool flag=0;
			for(klass kls:mem){
				if(addr>=now+getcache(kls)) now+=getcache(kls);
				else {tmp=kls;flag=1;break;};
			}
			if(flag==0) {
				cout<<"ERR"<<endl;
				continue;
			}
			while(flag){
				suc cur=data[tmp.type];
				vector<klass> members=cur.members;
				for(klass kls:members){
					if(addr>=now+cur.rule) now+=cur.rule;
					else {
						if(addr>=now+getcache(kls)) cout<<"ERR"<<endl;
						flag=0;
						break;
					}
				}
			}
		}
	}
	return 0;
}
