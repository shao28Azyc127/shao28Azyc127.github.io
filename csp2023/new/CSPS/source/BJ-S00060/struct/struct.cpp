#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct structure{
	ll first,d;
	ll size;
	string name;
	int subcnt;
	bool isConst;
	vector<structure> sub;
	ll getSize(){
		if(isConst)return d;
		return subcnt*d;
	}
	string query(ll idx){
		if(subcnt==0)return name;
		for(int i=0;i<subcnt;i++){
			if(sub[i].first<=idx&&idx<sub[i].first+sub[i].getSize()){
				return name+"."+sub[i].query(idx);
			}
		}
		return "-ERR-";
	}
	void modify(){
		if(subcnt==0)return;
		for(int i=0;i<subcnt;i++){
			sub[i].first=first+i*d;
			sub[i].modify();
		}
	}
	void addSub(structure dat,string name){
		dat.first=first+getSize();
		dat.name=name;
		subcnt++;
		sub.push_back(dat);
		if(dat.getSize()>d){
			d=dat.getSize();
			modify();
		}
	}
	void display(int tab){
		for(int i=0;i<tab;i++)cout<<"|   ";
		cout<<name<<"("<<first<<"+"<<d<<"k,len="<<getSize()<<") "<<subcnt<<" nodes"<<endl;
		if(isConst)return;
		for(int i=0;i<subcnt;i++){
			sub[i].display(tab+1);
		}
	}
	int queryidx(string dat){
		if(dat=="")return first;
		int idx=dat.find('.');
		string tofind,nxt;
		if(idx==-1){
			tofind=dat;
			nxt="";
		}else{
			tofind=dat.substr(0,idx);
			nxt=dat.substr(idx+1);
		}
		for(int i=0;i<subcnt;i++){
			if(sub[i].name==tofind){
				return sub[i].queryidx(nxt);
			}
		}
		return -1;
	}
};
map<string,structure> mp={
	{"byte",{-2147483647,1,1,"byte",0,true,{}}},
	{"short",{-2147483647,2,2,"short",0,true,{}}},
	{"int",{-2147483647,4,4,"int",0,true,{}}},
	{"long",{-2147483647,8,8,"long",0,true,{}}}
};
ll totend,totd=1;
int t;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(x==1){
			string name;
			cin>>name;
			mp[name]={-2147483647,0,0,name,0,false,{}};
			int n;
			cin>>n;
			while(n--){
				string ctype,cname;
				cin>>ctype>>cname;
				mp[name].addSub(mp[ctype],cname);
			}
			if(mp[name].getSize()>totd){
				for(auto id:mp){
					auto i=id.first;
					if(mp[i].first<0)continue;
					mp[i].first/=totd;
					mp[i].first*=mp[name].getSize();
					mp[i].modify();
				}
			}
			cout<<mp[name].getSize()<<" "<<mp[name].d<<endl;
		}else if(x==2){
			string type,name;
			cin>>type>>name;
			mp[name]=mp[type];
			mp[name].name=name;
			mp[name].first=totend;
			mp[name].modify();
			totd=max(totd,mp[name].getSize());
			totend=totd*mp.size();
			cout<<mp[name].first<<endl;
		}else if(x==3){
			string dst;
			cin>>dst;
			int idx=dst.find('.');
			string tofind,nxt;
			if(idx==-1){
				tofind=dst;
				nxt="";
			}else{
				tofind=dst.substr(0,idx);
				nxt=dst.substr(idx+1);
			}
			for(auto id:mp){
				auto i=id.first;
				if(mp[i].name==tofind){
					cout<<mp[i].queryidx(nxt)<<endl;
					break;
				}
			}
		}else{
			ll idx;
			cin>>idx;
			string res;
			for(auto id:mp){
				auto i=id.first;
				if(mp[i].first<=idx&&mp[i].first+mp[i].getSize()>idx){
					res=mp[i].query(idx);
					break;
				}
			}
			if(res.find("-ERR-")!=-1)cout<<"ERR"<<endl;
			else cout<<res<<endl;
		}
	}
}