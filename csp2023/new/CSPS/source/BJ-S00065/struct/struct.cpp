#include<iostream>
#include<unordered_map>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=110;
unordered_map<string,int> map;
int idx=4;
struct node{
	int ls;
	LL dq,size;
	unordered_map<string,int> hash;
	int ty[N];
	LL be[N];
	string name[N];
}str[N];
inline void init(){
	str[1].dq=str[1].size=1;
	str[2].dq=str[2].size=2;
	str[3].dq=str[3].size=4;
	str[4].dq=str[4].size=8;
	map["byte"]=1;
	map["short"]=2;
	map["int"]=3;
	map["long"]=4;
}
inline void newstr(){
	idx++;
	string name;
	cin>>name;
	map[name]=idx;
	node &x=str[idx];
	scanf("%d",&x.ls);
	for(int i=1;i<=x.ls;i++){
		string s,nna;
		cin>>s>>nna;
		x.hash[nna]=i;
		x.name[i]=nna;
		x.ty[i]=map[s];
		node y=str[x.ty[i]];
		x.dq=max(x.dq,y.dq);
		if(i==1)
			x.size=y.size;
		else
			x.size=x.size-1-(x.size-1)%y.dq+y.dq+y.size;
		x.be[i]=x.size-y.size;
	}
	if(x.size%x.dq)
		x.size=x.size-x.size%x.dq+x.dq;
	printf("%lld %lld\n",x.size,x.dq);
}
inline void insert(){
	string t,name;
	cin>>t>>name;
	node &x=str[0];
	x.ls++;
	int ls=x.ls;
	x.hash[name]=ls;
	x.name[ls]=name;
	x.ty[ls]=map[t];
	node y=str[x.ty[ls]];
	if(ls==1)
		x.size=y.size;
	else
		x.size=x.size-1-(x.size-1)%y.dq+y.dq+y.size;
	x.be[ls]=x.size-y.size;
	printf("%lld\n",x.be[ls]);
}
LL query(node x,string s){
	int fd,n=s.size();
	for(fd=0;fd<n;fd++)
		if(s[fd]=='.')
			break;
	if(fd==n)
		return x.be[x.hash[s]];
	string l=s.substr(0,fd),r=s.substr(fd+1);
	//cout<<l<<' '<<r<<endl;
	//printf("%d %lld\n",x.hash[l],x.be[x.hash[l]]);
	return query(str[x.ty[x.hash[l]]],r)+x.be[x.hash[l]];
}
string get(node x,LL adr){
	//cout<<x.name<<' '<<adr<<endl;
	if(adr>x.size-1)
		return "ERR";
	if(!x.ls)
		return "";
	int ls=x.ls;
	for(int i=1;i<=ls;i++)
		if(x.be[i]<=adr&&(i==ls||x.be[i+1]>adr)){
			string res=get(str[x.ty[i]],adr-x.be[i]);
			if(res=="ERR")
				return res;
			if(res=="")
				return x.name[i];
			return x.name[i]+'.'+res;
		}
	return "ERR";
}
int main(){
	init();
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--){
		int op;
		scanf("%d",&op);
		if(op==1)
			newstr();
		else if(op==2)
			insert();
		else if(op==3){
			string s;
			cin>>s;
			printf("%lld\n",query(str[0],s));
		}
		else if(op==4){
			LL adr;
			scanf("%lld",&adr);
			cout<<get(str[0],adr)<<endl;
		}
	}
	return 0;
}