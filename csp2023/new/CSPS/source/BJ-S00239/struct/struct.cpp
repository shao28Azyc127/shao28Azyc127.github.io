//*** 15pts is enough
#include <bits/stdc++.h>
using namespace std;
#define w s[cnt-1]

int cnt = 2;
int sp = 0;
map<string,int> m,mmem;

struct mem{
	string path;
	mem(){path="ERR";}
}mem[10000010];

struct Ss{
	string name;
	int dq;
	size_t size;
	int num;

	Ss(){}
	Ss(string _name,size_t _size){name=_name,size=_size,m[_name]=cnt-1;}
}s[10];


void init(){
	s[1] = Ss("byte",1);
	cnt++;
	s[2] = Ss("short",2);
	cnt++;
	s[3] = Ss("int",4);
	cnt++;
	s[4] = Ss("long",8);
	cnt++;
}

void build(int idx,string path){
	mmem[path] = sp,mem[sp].path=path,sp+=s[idx].size;
}

int main(){
	//freopen("struct.in","r",stdin);
	//freopen("struct.out","w",stdout);

	int n,k,op,type1;
	string type,name;
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&op);
		if(op==1){
			cin>>name>>k;
		}else if(op==2){
			cin>>type>>name;
			printf("%d\n",sp);
			build(m[type],name);
		}else if(op==3){
			cin>>name;
			cout<<mmem[name]<<endl;
		}else if(op==4){
			int addr;
			cin>>addr;
			cout<<mem[addr].path<<"\n";
		}
	}
	return 0;
}