#include<bits/stdc++.h>
using namespace std;
const int MOD=979856411;

//34298 8358525 5765 203144
const int BYTE=34298,SHORT=8358525,INT=5765,LONG=203144;

int Hash(char* ch){
	int res=0,len=strlen(ch);
	for(int i=0;i<len;i++) res=(res*26+ch[i]-'a')%MOD;
	return res;
}
int Hash(char* ch,int len){
	int res=0;
	for(int i=0;i<len;i++){
		res=(res*26+ch[i]-'a')%MOD;
	}
	return res;
}

char name[100000];
int N;

struct typeData{
	char typeName[16];
	char subName[128][16];
	int duiqi;
	typeData(){duiqi=-1;}
	typeData* subData[128];
	void update(){
		for(int i=0;subData[i]!=NULL;i++){
			if(subData[i]->duiqi==-1) subData[i]->update();
			duiqi=max(duiqi,subData[i]->duiqi);
		}
	}
};

map<int,typeData*> name2data;

void initTypeData(){
	typeData *tmp;
	tmp=new typeData();
	strcpy(tmp->typeName,"byte");
	tmp->duiqi=1;
	name2data[BYTE]=tmp;
	tmp=new typeData();
	strcpy(tmp->typeName,"short");
	tmp->duiqi=2;
	name2data[SHORT]=tmp;
	tmp=new typeData();
	tmp->duiqi=4;
	strcpy(tmp->typeName,"int");
	name2data[INT]=tmp;
	tmp=new typeData();
	strcpy(tmp->typeName,"long");
	tmp->duiqi=8;
	name2data[LONG]=tmp;
}

struct node{
	typeData now;
	char name[16];
	node *subNode[128];
	int duiqi;
	int startpos,endpos;
	int init(typeData _now,char* _name,int _startpos){
		duiqi=_now.duiqi;
		strcpy(name,_name);
		now=_now;
		startpos=ceil(_startpos/double(duiqi))*duiqi;
		int tmp=startpos,i=0;
		for(;now.subData[i]!=NULL;i++){
			subNode[i]=new node();
			tmp=subNode[i]->init(*now.subData[i],now.subName[i],tmp+(i!=0));
		}
		if(i==0) tmp++;	
		endpos=ceil(tmp/double(duiqi))*duiqi-1;
		return endpos;
	}
	int find(char *str){
		int i=0;
		bool flag=false;
		for(;str[i]!='\0';i++){
			if(str[i]=='.'){
				flag=true;
				break;
			}	
		}
		if(!flag) return startpos;
		char *nextStr=&str[i+1];
		flag=false;
		for(;nextStr[i]!='\0';i++){
			if(nextStr[i]=='.'){
				flag=true;
				break;
			}	
		}
		int varStr=Hash(nextStr,i);
		for(int i=0;subNode[i]!=NULL;i++){
			if(Hash(subNode[i]->name)==varStr) return subNode[i]->find(nextStr);
		}	
		return -1;
	}
	void find(int x,char* up){
		int h=Hash(now.typeName);
		if(h==BYTE || h==SHORT || h==INT || h==LONG){
			char ch[100];
			ch[0]='.',ch[1]='\0';
			printf("%s\n",strcat(strcat(up,ch),name));
			return;
		}
		for(int i=0;subNode[i]!=NULL;i++){
			if(x>=subNode[i]->startpos && x<=subNode[i]->endpos){
				char ch[100];
				ch[0]='.',ch[1]='\0';
				subNode[i]->find(x,strcat(strcat(up,ch),name));
				return;
			}
		}	
		printf("ERR\n");
	}	
};

node* root[128];
map<int,int> id;
int cnt=0;
int startpos=0;

int main(){
	initTypeData();
	scanf("%d",&N);
	while(N--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int k;
			scanf("%s%d",name,&k);
			typeData *tmp=new typeData();
			strcpy(tmp->typeName,name);
			for(int i=0;i<k;i++){
				scanf("%s",name);
				tmp->subData[i]=name2data[Hash(name)];
				scanf("%s",name);
				strcpy(tmp->subName[i],name);
			}	
			tmp->update();
			name2data[Hash(tmp->typeName)]=tmp;
			node* n=new node();
			int res=n->init(*tmp,"1145141919810",0)+1;
			printf("%d %d\n",res,tmp->duiqi);
			delete n;
		}
		if(op==2){
			root[++cnt]=new node();
			scanf("%s",name);
			typeData tmp=*name2data[Hash(name)];
			scanf("%s",name);
			root[cnt]->init(tmp,name,startpos+(cnt!=1));
			printf("%d\n",root[cnt]->startpos);
			id[Hash(name)]=cnt;

		}
		if(op==3){
			scanf("%s",name);
			int i=0;
			for(;name[i]!='\0';i++)
				if(name[i]=='.')
					break;	
			char *nextStr=&name[i+1];
			int varStr=Hash(name,i);
			int res=root[id[varStr]]->find(name);
			printf("%d\n",res);
		}
		if(op==4){
			int x;
			scanf("%d",&x);
			bool flag=false;
			char ch[100];
			ch[0]='\0';
			for(int i=1;i<=cnt;i++){
				if(x>=root[cnt]->startpos && x<=root[cnt]->endpos){
					root[cnt]->find(x,ch);
					flag=true;
					break;
				}
			}	
			if(!flag) puts("ERR");
		}

	}
	return 0;
}