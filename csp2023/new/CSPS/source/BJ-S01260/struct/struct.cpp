#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<map>
#define LL long long
using namespace std;

const int NR=110;
const int MR=0;
const int MOD=0;

int gsz(string typ);
int gtab(string typ);
int mtab(int k,int tab){
	if(k%tab!=0)return k+tab-(k%tab);
	return k;
}

struct strc{
	string name;
	int k;
	int size;
	int tab;
	string ctyp[101];
	string cname[101];
	int cp[101];
	bool operator<(const strc &x)const{
		return size<x.size;
	}
	void sta(){
		tab=gtab(ctyp[1]);
		cp[1]=0;
		for(int i=2;i<=k;i++){
			int ctab=gtab(ctyp[i]);
			tab=max(tab,ctab);
			cp[i]=mtab(cp[i-1]+gsz(ctyp[i-1]),ctab);
		}
		size=mtab(cp[k]+gsz(ctyp[k]),tab);
	}
	int gnamecp(string qn){
		for(int i=1;i<=k;i++){
			if(cname[i]==qn)return i;
		}
		return -1;
	}
	string gcpname(int qcp){
		int pos=upper_bound(cp+1,cp+1+k,qcp)-cp-1;
		return cname[pos];
	}
};
map<string,strc> a;

int gsz(string typ){
	if(typ=="byte")return 1;
	else if(typ=="short")return 2;
	else if(typ=="int")return 4;
	else if(typ=="long")return 8;
	else if(a.count(typ))return a[typ].size;
	return 0;
}
int gtab(string typ){
	if(typ=="byte")return 1;
	else if(typ=="short")return 2;
	else if(typ=="int")return 4;
	else if(typ=="long")return 8;
	else if(a.count(typ))return a[typ].tab;
	return 0;
}
bool isbasetyp(string typ){
	if(typ=="byte")return true;
	else if(typ=="short")return true;
	else if(typ=="int")return true;
	else if(typ=="long")return true;
	return false;
}
struct val{
	int head;
	string typ,name;
	bool operator<(const val &x)const{
		return head<x.head;
	}
};

LL nclen;
val nc[NR];
int nchead[NR];
int nccnt;
map<string,LL> nametonc;

int gbase(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='.')return i;
	}
	return -1;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int op;
		cin >> op;
		if(op==1){
			strc tmp;
			cin >> tmp.name >> tmp.k;
			for(int i=1;i<=tmp.k;i++){
				cin >> tmp.ctyp[i] >> tmp.cname[i];
			}
			tmp.sta();
			cout << tmp.size << " " << tmp.tab << endl;
			a[tmp.name]=tmp;
		}
		if(op==2){
			val tmp;
			cin >> tmp.typ >> tmp.name;
			tmp.head=mtab(nclen,gtab(tmp.typ));
			nametonc[tmp.name]=tmp.head;
			nc[++nccnt]=tmp;
			nchead[nccnt]=tmp.head;
			nclen=tmp.head+gsz(tmp.typ);
			cout << tmp.head << endl;
		}
		if(op==3){
			string s;
			cin >> s;
			int pp=gbase(s);
			if(pp==-1){
				cout << nametonc[s] << endl;
			}
			else{
				string ai="",bi="";
				for(int i=0;i<pp;i++){
					ai+=s[i];
				}
				for(int i=pp+1;i<s.size();i++){
					bi+=s[i];
				}
				int nci=nametonc[ai];
				nci+=a[ai].gnamecp(bi);
				cout << nci << endl;
			}
		}
		if(op==4){
			int x;
			cin >> x;
			int pos=upper_bound(nchead+1,nchead+1+nccnt,x)-nchead;
			pos--;
			if(nc[pos].head==x){
				if(isbasetyp(nc[pos].typ)){
					cout << nc[pos].name << endl;
				}
				else{
					cout << "ERR" << endl;
				}
			}
			else{
				if(isbasetyp(nc[pos].typ)){
					cout << nc[pos].name << endl;
				}
				else{
					cout << nc[pos].name << "." << a[nc[pos].typ].gcpname(x-nc[pos].head) << endl;
				}
			}
		}
	}
}