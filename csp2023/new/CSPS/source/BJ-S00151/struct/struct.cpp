#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
struct type_rp{
	int o[103],tpids[103],sz,oo,aa;
	map<string,int> tpnames;
	type_rp(){sz=oo=aa=o[0]=0;};
	void add_subtype(int,string);
	void __test_print();
}types[103];
int typesn=0,valsn=0;
void type_rp::add_subtype(int tpid,string tpname){
	sz++;
	o[sz]=o[sz-1]+types[tpids[sz-1]].oo;
	tpids[sz]=tpid;
	while(o[sz]%types[tpid].aa!=0)	o[sz]++;
	aa=std::max(aa,types[tpid].aa);
	oo=o[sz]+types[tpid].oo;
	while(oo%aa!=0)oo++;
	tpnames[tpname]=sz;
}
void type_rp::__test_print(){
	cout<<"sz:"<<sz<<" oo:"<<oo<<" aa:"<<aa<<endl;
	for(int i=1;i<=sz;i++)	cout<<tpids[i]<<'.'<<o[i]<<',';
	cout<<endl;
}
map<string,int> typesname,valsname;
void initTypes(){
	types[1].sz=1;types[1].tpids[1]=1;types[1].oo=1;types[1].aa=1;//byte
	types[2].sz=1;types[2].tpids[1]=2;types[2].oo=2;types[2].aa=2;//short
	types[3].sz=1;types[3].tpids[1]=3;types[3].oo=4;types[3].aa=4;//int
	types[4].sz=1;types[4].tpids[1]=4;types[4].oo=8;types[4].aa=8;//long
	typesname["byte"]=1;typesname["short"]=2;typesname["int"]=3;typesname["long"]=4;
	typesn=4;
}
struct val_rp{
	long long top;int tpid;
	val_rp(){top=tpid=0;}
	void init_top(int typid);
}vals[103];
void val_rp::init_top(int typid){
	top=vals[valsn-1].top+types[vals[valsn-1].tpid].oo;
	tpid=typid;
	while(top%types[typid].aa!=0)top++;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	initTypes();
	int q;
	cin>>q;
	while(q--){
		int op;cin>>op;
		if(op==1){
			string typname;int k;
			cin>>typname>>k;
			typesname[typname]=++typesn;
			for(int i=1;i<=k;i++){
				string sub,nam;
				cin>>sub>>nam;
				types[typesn].add_subtype(typesname[sub],nam);
			}
			cout<<types[typesn].oo<<' '<<types[typesn].aa<<endl;
		} else if(op==2){
			string typname,valname;
			cin>>typname>>valname;
			valsn++;
			vals[valsn].init_top(typesname[typname]);
			valsname[valname]=valsn;
			cout<<vals[valsn].top<<endl;
		} else if(op==3){
			string str;
			cin>>str;
			string::size_type pos=str.find('.');
			int valid=valsname[str.substr(0,pos)];
			int tyid=vals[valid].tpid;
			long long sum=0;
			str=str.substr(pos+1);
			while(1){
				string::size_type pos=str.find('.');
				if(pos==string::npos)	break;
				if(types[tyid].tpnames.find(str.substr(0,pos))==types[tyid].tpnames.end())	break;
				int t=types[tyid].tpnames[str.substr(0,pos)];
				sum+=types[tyid].o[t];
				tyid=types[tyid].tpids[t];
				str=str.substr(pos+1);
			}
			cout<<vals[valid].top+sum<<endl;
		}
	}
	return 0;
}
