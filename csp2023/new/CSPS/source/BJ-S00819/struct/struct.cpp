#include<bits/stdc++.h>
using namespace std;
int n,op;
struct var{   //����
	string type;   //����
	int start,end;    //��ʼ�ռ�ͽ����ռ�
};
struct member{    //��Ա����
	string type,name;   //���ͣ�����
};
struct stru{
	int mmy;   //���ʹ�С
	vector<member> mmb ;  //��������ѯ
	bool basic; // �Ƿ��ǻ�������
}  ;
//~ void add(string t){     //����ռ�
	//~ if(st[t].basic){    //��������
		//~ v[st[t].]={t,memoryPos+(memoryPos%st[t].mmy),memoryPos+(memoryPos%st[t].mmy)+st[t].mmy};
		//~ memoryPos=memoryPos+(memoryPos%st[t].mmy)+st[t].mmy;
	//~ }
	//~ else{    //�ṹ��
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
	vector<member>empty;    //¼���������
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
				//~ maxmem=max(maxmem,st[t].mmy);    //����С
				//~ sum_mem+=st[t].mmy;     //�ۻ��ռ�
			//~ }
			//~ st.push_back({s,temp_mem,0});  //���ǻ�������
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
						//~ for(int i=0;i<st[temp_type].mmb.size();i++){    //�����ҳ�Ա
							//~ if(st[temp_type].mmb[i].name==name){
								//~ temp_type=st[temp_type].mmb[i].type;
							//~ }
						//~ }
					//~ }
					//~ name="";
				//~ }
			//~ }
			//~ //��ʱtemptypeһ���ǻ���������
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
