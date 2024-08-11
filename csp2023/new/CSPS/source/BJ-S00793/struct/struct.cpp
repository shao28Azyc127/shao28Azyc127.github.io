//Genshin Impact (wrong) Zhenshen Impart (true)
//I love Kamisato Ayaka
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c) for(int (i)=a;i<=(b);i+=(c))
#define per(i,a,b,c) for(int (i)=a;i>=(b);i-=(c))
#define pb push_back
using namespace std;
struct Node{
	int l,r;string name;int tp;
};
vector<Node> mem;
map<string,int> s2i;
struct st{
	vector<Node> mem;string name;
	int dq,sz;
};vector<st> vec;
vector<st> decla;
bool errr=0;
string visit(const vector<Node> &mem,int pos){
	for(auto [l,r,name,tp]:mem){
		if(l<=pos && pos<=r){
			if(tp<=3){
				return name;
			}else{
				return name+"."+visit(vec[tp].mem,pos-l);
			}
		}	
	}
	errr=1;
	return "";
}int getit(const vector<Node> &mem,string name){
	string t,gogo;
	for(auto c:name){
		if(c=='.')	break ;
		t+=c;
	}for(int i=t.size()+1;i<name.size();i++){
		gogo+=name[i];
	}
	for(auto [l,r,name,tp]:mem){
		if(name==t){
			if(gogo.size()==0){
				return l;
			}else{
				return l+getit(vec[tp].mem,gogo);
			}	
		}
	}
	return 0;
}

signed main(){

	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;cin>>n;
	vec.pb({{},"byte",1,1});vec.pb({{},"short",2,2});	vec.pb({{},"int",4,4});	vec.pb({{},"long",8,8});
	s2i["byte"]=0;s2i["short"]=1;s2i["int"]=2;s2i["long"]=3;
	int ll=0;
	while(n--){
		int op;cin>>op;
		if(op==1){
			string s;int k;
			cin>>s>>k;
			vec.pb({{},s,0});
			int id=vec.size()-1;s2i[s]=id;
			int cur=0;
			rep(i,1,k,1){
				string t,n;cin>>t>>n;
				int ii=s2i[t];
				int ddq=vec[ii].dq;
				cur=((cur+ddq-1)/ddq)*ddq;
				vec[id].mem.pb({cur,cur+vec[ii].sz-1,n,ii});
				cur+=vec[ii].sz;
				vec[id].dq=max(vec[id].dq,ddq);
			}
			int ddq=vec[id].dq;
			cur=((cur+ddq-1)/ddq)*ddq;
			vec[id].sz=cur;
			cout<<vec[id].sz<<" "<<vec[id].dq<<endl;
		}if(op==2){
			string t,n;cin>>t>>n;
			int tp=s2i[t],ddq=vec[tp].dq;
			ll=((ll+ddq-1)/ddq)*ddq;
			cout<<ll<<endl;
			mem.pb({ll,ll+vec[tp].sz-1,n,tp});
			ll+=vec[tp].sz;
		}if(op==3){
			string t;cin>>t;
			cout<<getit(mem,t)<<endl;
		}if(op==4){
			int val;errr=0;
			cin>>val;
			string qwq=visit(mem,val);
			if(errr)cout<<"ERR\n";
			else	cout<<qwq<<endl;
		}
	}	
	return 0;
}