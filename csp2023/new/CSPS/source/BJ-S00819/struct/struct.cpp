#include<bits/stdc++.h>
using namespace std;
int n,op;
struct var{   //变量
	string type;   //类型
	int start,end;    //起始空间和结束空间
};
struct member{    //成员变量
	string type,name;   //类型，名称
};
struct stru{
	int mmy;   //类型大小
	vector<member> mmb ;  //遍历，查询
	bool basic; // 是否是基本类型
}  ;
//~ void add(string t){     //发配空间
	//~ if(st[t].basic){    //基本类型
		//~ v[st[t].]={t,memoryPos+(memoryPos%st[t].mmy),memoryPos+(memoryPos%st[t].mmy)+st[t].mmy};
		//~ memoryPos=memoryPos+(memoryPos%st[t].mmy)+st[t].mmy;
	//~ }
	//~ else{    //结构体
		//~ for(int i=0;i<st[t].mmb.size();i++){
			//~ add(st[t].mmb[i].type);
		//~ }
	//~ }
	
//~ }
var var_pack(string a,int b,int c){
	var t;
	t.type=a;
	t.start=b;
	t.end=c;
	return t;
}
string vars[100010];
map<string,var>v;
map<string,stru >st;
int var_cnt=0;
int memoryPos=0;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	vector<member>empty;    //录入基本类型
	st["int"]={4,empty,1};
	st["long"]={8,empty,1};
	st["short"]={2,empty,1};
	st["byte"]={1,empty,1};
	cin>>n;
	for(int u=1;u<=n;u++){
		cin>>op;
		if(op==1){
			//~ string s,t,n;
			//~ map<string,string>temp_mem;
			//~ int k;
			//~ cin>>s>>k;
			//~ int max_mem=-1,sum_mem=0;
			//~ for(int i=1;i<=k;i++){
				//~ cin>>t>>n;
				//~ temp_mem[n]=t;
				//~ maxmem=max(maxmem,st[t].mmy);    //最大大小
				//~ sum_mem+=st[t].mmy;     //累积空间
			//~ }
			//~ st.push_back({s,temp_mem,0});  //不是基本类型
		}
		else if(op==2){
			string t,n;
			cin>>t>>n;
			vars[++var_cnt]=n;
			v[n]=var_pack(t,memoryPos+(memoryPos%st[t].mmy),memoryPos+(memoryPos%st[t].mmy)+st[t].mmy-1);
			memoryPos=memoryPos+(memoryPos%st[t].mmy)+st[t].mmy;
			cout<<v[n].start<<endl;
		}
		else if(op==3){
			string s;
			cin>>s;
			cout<<v[s].start<<endl;
			//~ string name="";
			//~ int mem=a0;
			//~ bool m=0;
			//~ string temp_type;
			//~ for(int i=0;i<s.size();i++){
				//~ if(s[i]=='.'){
					//~ if(!m)
						//~ temp_type=v[name].type;
					//~ else{
						//~ for(int i=0;i<st[temp_type].mmb.size();i++){    //便利找成员
							//~ if(st[temp_type].mmb[i].name==name){
								//~ temp_type=st[temp_type].mmb[i].type;
							//~ }
						//~ }
					//~ }
					//~ name="";
				//~ }
			//~ }
			//~ //此时temptype一定是基本类型了
			//~ cout<<114514;
			//~ }
		}
		else if(op==4){
			int addr;
			bool found=0;
			cin>>addr;
			for(int i=1;i<=var_cnt;i++){
				//~ cout<<vars[i]<<" ";
				if(v[vars[i]].start<=addr&&v[vars[i]].end>=addr){
					cout<<v[vars[i]].start<<endl;
					found=1;
					break;
				}
			}
			if(!found) cout<<"ERR"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
/*
6
2 int a
2 long aa
2 byte 1
3 aa
2 short b
4 9
*/
