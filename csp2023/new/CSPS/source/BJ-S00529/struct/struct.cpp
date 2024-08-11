#include<bits/stdc++.h>
#define ffor(i,l,r) for(ll i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(ll i=(l),i##_end=(r);i>=i##_end;i--)
using namespace std;
using ll = long long;
using tid = ll ;
using nid = ll ;
ll n;
map<string,tid> tstoi;//类型到类型id
map<string,nid> nstoi;
vector<string> tref = {""},nref = {""};
ll tget(string i){
	auto it = tstoi.find(i);
	if(it==tstoi.end()){
		tref.push_back(i);
		return tstoi[i] = tstoi.size()+1;
	}else return it->second;
}
ll nget(string i){
	auto it = nstoi.find(i);
	if(it==nstoi.end()){
		nref.push_back(i);
		return nstoi[i] = nstoi.size()+1;
	}else return it->second;
}
struct Type{
	//string name;
	ll size;
	ll in_size;
	ll gof;
	map<nid,tid> nf;// name to types;
	map<nid,ll > of;// name to offset
	vector<nid> vars;
	vector<ll > preof;// fast to find var by addr
}types[110];
ll calc(ll x,ll y){
	if(x%y==0) return x;
	return (x/y+1)*y;
}
ll gaddr = 0;
ll gvarc = 0;
tid vars[110];
map<nid,ll > gname;// nid -> i
nid names[110];
ll pre[110];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	//freopen("./struct/struct3.in","r",stdin);
	types[tget("byte")] = {
		//"byte",
		1,1,1,
	};
	types[tget("short")] = {
		//"byte",
		2,2,2,
	};
	types[tget("int")] = {
		//"byte",
		4,4,4,
	};
	types[tget("long")] = {
		//"byte",
		8,8,8,
	};
	cin>>n;
	ffor(_,1,n){
		ll op;cin>>op;
		if(op==1){
			ll k;string s;
			cin>>s>>k;
			ll id = tget(s),addr = 0;
			auto &o = types[id];
			ffor(i,1,k){
				string tmp;cin>>tmp;
				tid ti = tget(tmp);
				cin>>tmp;
				nid ni = nget(tmp);
				o.vars.push_back(ni);
				o.nf[ni] = ti;
				addr = calc(addr,types[ti].gof);
				o.preof.push_back(addr);
				o.of[ni] = addr;
				addr+=types[ti].size;

				//offset
				o.size = calc(o.size,types[ti].gof);
				o.size+= types[ti].size;
				o.gof = max(o.gof,types[ti].gof);
			}
			o.in_size = o.size;
			o.size = calc(o.size,o.gof);
			cout<<o.size<<" "<<o.gof<<"\n";

		}else if(op==2){
			string tmp;cin>>tmp;
			tid ti = tget(tmp);
			cin>>tmp;
			nid ni = nget(tmp);
			gaddr = calc(gaddr,types[ti].gof);
			pre[++gvarc] = gaddr;
			vars[gvarc] = ti;
			names[gvarc] = ni;
			cout<<gaddr<<"\n";
			gaddr+=types[ti].size;
			gname[ni] = gvarc;


		}else if(op==3){
			string tmp,name;cin>>tmp;
			tmp+='.';
			ll i = 0;
			while(tmp[i]!='.') name+=tmp[i],i++;
			ll ni = nget(name),addr = pre[gname[ni]],ti = vars[gname[ni]];
			i++;name = "";
			for(;i<tmp.size();i++){
				if(tmp[i]!='.') name+=tmp[i];
				else{
					ll ni = nget(name);

					addr+=types[ti].of[ni];
					ti = types[ti].nf[ni];
					name = "";
				}
			}

			cout<<addr<<"\n";
		}else if(op==4){
			ll end;cin>>end;
			if(end>=gaddr){
				puts("ERR");
				continue;
			}
			ll i_ = upper_bound(pre+1,pre+gvarc+1,end)-pre-1;
			ll ti = vars[i_],ni;
			end -= pre[i_];
			vector<nid> ans;
			ni = names[i_];
			ans.push_back(ni);
			while(1){
				auto &o = types[ti];
				if(end>=o.in_size) goto bad;//in hole
				if(ti<=4){
					break;
				}
				auto &oof = types[ti].preof;
				
				i_ = upper_bound(oof.begin(),oof.end(),end)-oof.begin()-1;
				ni = o.vars[i_];
				ans.push_back(ni);
				end-=o.preof[i_];
				ti = o.nf[ni];
			}
			ffor(i,0,ans.size()-1){
				if(i!=0) cout<<".";
				cout<<nref[ans[i]];
			}
			cout<<"\n";
			continue;
			bad:;
			puts("ERR");
			
		}
	}
	return 0;
}