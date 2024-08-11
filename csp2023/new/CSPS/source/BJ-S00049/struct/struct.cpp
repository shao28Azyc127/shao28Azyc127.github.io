#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int nowR=-1;
int Len(string s){
	if(s=="byte") return 1;
	if(s=="short") return 2;
	if(s=="int") return 4;
	if(s=="long") return 8;
}
struct node{
	int La, Ra, ra;//×ó¶Ë£¬ÓÒ¶Ë£¬¶ÔÆëºóµÄÓÒ¶Ë
	string type;//byte short int long
	string name;
};
struct stru{
	int num, duiqi;
	string name;
	vector<node> chi;
	void init(){
		for(int i=0;i<num;i++){
			chi[i].La=nowR+1;
			chi[i].Ra=chi[i].La+Len(chi[i].type);
			chi[i].ra=chi[i].La+duiqi-1;
			nowR+=duiqi;
		}
	}
};
vector<stru> st;
struct bianl{
	bool mode;
	node key2;
	stru key;
	string name;
};
vector<bianl> a;
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	int n;
	cin>>n;
	while(n--){
		int p;
		cin>>p;
		if(p==1){
			string name;int k;
			cin>>name>>k;
			stru tmp;
			tmp.name=name;tmp.num=k;
			tmp.duiqi=0;
			for(int i=1;i<=k;i++){
				string x, y;
				cin>>x>>y;
				node tmp2;
				tmp2.name=y;tmp2.type=x;
				tmp.chi.push_back(tmp2);
				tmp.duiqi=max(tmp.duiqi, Len(x));
			}
			st.push_back(tmp);
			cout<<k*tmp.duiqi<<" "<<tmp.duiqi<<endl;
		}else if(p==2){
			string x, y;
			cin>>x>>y;
			bianl tmp;
			cout<<nowR+1<<endl;
			tmp.name=y;
			for(int i=0;i<st.size();i++){
				if(st[i].name==x){
					tmp.mode=0;
					tmp.key=st[i];
					tmp.key.init();
					a.push_back(tmp);
				}
			}
			if(x=="byte" || x=="short" || x=="int" || x=="long"){
				node tmp2;
				tmp.mode=1;
				tmp.key2=tmp2;
				tmp.key2.type=x;
				tmp.key2.La=nowR+1;
				tmp.key2.Ra=tmp.key2.ra=nowR+Len(x);
				a.push_back(tmp);
			}
		}else if(p==3){
			string s;
			cin>>s;
			int now=0;
			string tmp;
			stru tmp2;
			if(s.find('.', now)==string::npos){
				tmp=s.substr(now, s.size()-now);
				for(int i=0;i<a.size();i++){
					if(a[i].name==tmp){
						if(!a[i].mode)
							cout<<a[i].key.chi[0].La<<endl;
						else
							cout<<a[i].key2.La<<endl;
					}
				}
			}else{
				tmp=s.substr(now, s.find('.', now)-now), now=s.find('.', now)+1;
				for(int i=0;i<a.size();i++){
					if(a[i].name==tmp){
						tmp2=a[i].key;
					}
				}
				tmp=s.substr(now, s.size()-now);
				for(int i=0;i<tmp2.chi.size();i++){
					if(tmp2.chi[i].name==tmp){
						cout<<tmp2.chi[i].La<<endl;
					}
				}
			}
		}else{
			int k;
			cin>>k;
			stru tmp;
			bool f=0;
			for(int i=0;i<a.size();i++){
				if(a[i].mode==1 && a[i].key2.La<=k && a[i].key2.ra>=k){
					if(a[i].key2.La<=k && k<=a[i].key2.Ra)
						cout<<a[i].name<<endl;
					else
						cout<<"ERR"<<endl;
					f=1;
					break;
				}
			}
			if(f) continue;
			for(int i=0;i<a.size();i++){
				if(a[i].mode==0 && a[i].key.chi[0].La<=k && k<=a[i].key.chi[a[i].key.chi.size()-1].ra){
					tmp=a[i].key;
					break;
				}
			}
			for(int i=0;i<tmp.chi.size();i++){
				if(tmp.chi[i].La<=k && k<=tmp.chi[i].ra){
					if(tmp.chi[i].La<=k && k<=tmp.chi[i].Ra)
						cout<<tmp.name<<"."<<tmp.chi[i].name<<endl;
					else
						cout<<"ERR"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}