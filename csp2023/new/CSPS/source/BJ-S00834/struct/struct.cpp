#include<bits/stdc++.h>
#define in(...) scanf(__VA_ARGS__)
#define out(...) printf(__VA_ARGS__)
#define up(i,l,r) for(int i=l;i<=r;i++)
#define dn(i,r,l) for(int i=r;i>=l;i--)
#define fr(i,bg,ed,eq) for(i=bg;i!=ed;i=eq)
#define rpt(num) dn(tt,num,1)
using namespace std;
const int N=1e5+50;
typedef long long ll;
#define int ll

struct para{
	int type;
	string name;
	ll fr;
};
struct typ{
	int sz;
	vector<para> pr;
	string name;
	int duiqi;
};
map<string,int> tsmp;
vector<typ> ts;
struct stt{
	int tp;
	int fr;
	string name;
};
vector<stt> vst;
int tsidx=4;
ll addr=0;

int n;
void init(){
	typ bt;
	bt.sz=1;
	bt.name="byte";
	bt.duiqi=1;
	bt.pr.clear();
	tsmp["byte"]=0;
	ts.push_back(bt);
	typ st;
	st.sz=2;
	st.name="short";
	st.duiqi=2;
	st.pr.clear();
	tsmp["short"]=1;
	ts.push_back(st);
	typ it;
	it.sz=4;
	it.name="int";
	it.duiqi=4;
	it.pr.clear();
	tsmp["int"]=2;
	ts.push_back(it);
	typ ll;
	ll.sz=8;
	ll.name="long";
	ll.duiqi=8;
	ll.pr.clear();
	tsmp["long"]=3;
	ts.push_back(ll);
}
void print(string type,int tab){
	rpt(tab){
		cout<<"    ";
	}
	cout<<"struct "<<type<<"{\n";
	typ rtp=ts[tsmp[type]];
	rpt(tab+1){
		cout<<"    ";
	}                 
	cout<<"info:\n";
	rpt(tab+1){
		cout<<"    ";
	}                 
	cout<<"size: "<<rtp.sz<<"\n";
	rpt(tab+1){
		cout<<"    ";
	}                 
	cout<<"name: "<<rtp.name<<"\n";
	for(para i:rtp.pr){
		rpt(tab+1){
			cout<<"    ";
		}
		cout<<"addr: "<<i.fr<<"\n";
		print(ts[i.type].name,tab+1);
	}
	rpt(tab){
		cout<<"    ";
	}
	cout<<"}\n";
}
void find_member(string s){
	int now_addr=0;
	string now_name=s.substr(0,s.find('.',0));
	
//	cout<<now_name<<endl;

	int now_name_idx=s.find('.')+1;
	typ now_t;
	for(stt i:vst){
		if(now_name==i.name){
			now_t=ts[i.tp];
			now_addr=i.fr;
			break;
		}
	}
	while(now_name_idx!=0){
		now_name=s.substr(now_name_idx,s.find('.',now_name_idx)-now_name_idx);
		now_name_idx=s.find('.',now_name_idx)+1;
		
//		cout<<s.length()<<" "<<now_name_idx<<" "<<now_name<<endl;

		for(para i:now_t.pr){
			if(now_name==i.name){
				now_t=ts[i.type];
				now_addr+=i.fr;
			}
		}
	}
	cout<<now_addr<<endl;
}
void find_addr(int ad){
	string ans="";
	int idx;
	typ now_t;
	int tidx;
	for(stt i:vst){
		if(i.fr>ad){         
			break;
		}
		idx++;
	}
	idx--;
	if(1){
		stt i=vst[idx];
		ans=ans+i.name;
		if(i.tp<4){
			if(i.fr+ts[i.tp].sz>ad){
				cout<<ans<<endl;
			}else{
				cout<<"ERR\n";
			}                         
			return ;
		}
		tidx=i.tp;
		now_t=ts[i.tp];
		ad-=i.fr; 
	}                  
	while(tidx>=4){
		idx=0;
		for(para i:now_t.pr){
			if(i.fr>ad){
				break;
			}
			idx++;
		}
		idx--;
		if(1){
			para i=now_t.pr[idx];
			ans=ans+"."+i.name;
			if(i.type<4){
				if(i.fr+ts[i.type].sz>ad){   			
        				cout<<ans<<endl;
        			}else{
        				cout<<"ERR\n";
        			}                         
				return ;
			}
			tidx=i.type;
			now_t=ts[i.type];
			ad-=i.fr; 
		}                  
	}
}
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);

	init();
	cin>>n;
	int op;
	while(n--){
		cin>>op;
		if(op==1){
			string s;
			int k;
			cin>>s>>k;
			typ neww;
			neww.name=s;
			string snm,stp;
			int dq=0;
			neww.pr.resize(k);
			up(i,0,k-1){
				cin>>stp>>snm;
				int tp=tsmp[stp];
				dq=max(dq,ts[tp].duiqi);
				neww.pr[i].name=snm;
				neww.pr[i].type=tp;
			}
			neww.duiqi=dq;
			int now=0;
			up(i,0,k-1){
				int ddq=ts[neww.pr[i].type].duiqi;
				if(i==0){
					neww.pr[i].fr=0;
					now=(ts[neww.pr[i].type].sz+ddq-1)/ddq*ddq;
				}else{
					now=(now+ddq-1)/ddq*ddq;
					neww.pr[i].fr=now;
					now+=ts[neww.pr[i].type].sz;
				}
			}
			neww.sz=(now+dq-1)/dq*dq;
			ts.push_back(neww);
			tsmp[neww.name]=tsidx++;
			
//			for(typ i:ts){
//				print(i.name,0);
//			}

			cout<<neww.sz<<" "<<neww.duiqi<<endl;
		}else if(op==2){
			string t,n;
			cin>>t>>n;
			cout<<addr<<endl;
			stt neww;
			neww.tp=tsmp[t];
			neww.name=n;
			long long duiq=ts[neww.tp].sz;
			addr=(addr+duiq-1)/duiq*duiq;
			neww.fr=addr;
			addr+=ts[tsmp[t]].sz;
			vst.push_back(neww);
		}else if(op==3){
			string s;
			cin>>s;
			find_member(s);
		}else if(op==4){
			ll addr;
			cin>>addr;
			find_addr(addr);
		}
	}
	return 0;
}
