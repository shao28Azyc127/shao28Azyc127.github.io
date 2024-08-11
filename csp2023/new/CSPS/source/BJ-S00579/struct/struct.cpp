#include<iostream>
using namespace std;
struct str{
	int k;
	string name;
	string s[105];
	int len[105];
	int sz,mx;
}sct[105];
string names[105];
int pp;
int add[105][3],p;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin>>n;
	int now=0;
	while(n--){
		int op;
		cin>>op;
		if(op==1){
			p++;
			cin>>sct[p].name>>sct[p].k;
			sct[p].sz=0,sct[p].mx=0;
			for(int i=1;i<=sct[p].k;i++){
				string s;
				cin>>s>>sct[p].s[i];
				if(s=="byte")	sct[p].len[i]=1;
				if(s=="short")	sct[p].len[i]=2;
				if(s=="int")	sct[p].len[i]=4;
				if(s=="long")	sct[p].len[i]=8;
				sct[p].sz+=sct[p].len[i];
				sct[p].mx=max(sct[p].mx,sct[p].len[i]);
			}
			if(sct[p].sz%sct[p].mx!=0)	sct[p].sz+=sct[p].mx-sct[p].sz%sct[p].mx;
		}
		if(op==2){
			string s,s0;
			pp++;
			cin>>s>>names[pp];
			int x=0;
			for(int i=1;i<=p;i++)
				if(sct[i].name==s)
					x=i;
			int nw=now;
			for(int i=1;i<=sct[x].k;i++){
				int l=sct[x].len[i];
				while(l--){
					add[nw][0]=pp;
					add[nw][1]=i;
					add[nw][2]=x;
					nw++;
				}
			}
			now+=sct[x].sz;
		}
		if(op==3){
			string s;
			cin>>s;
			int m=0;
			for(int i=0;i<s.length();i++)
				if(s[i]=='.')	m=i;
			string s1=s.substr(0,m),s2=s.substr(m+1,s.length()-m-1);
			for(int i=0;i<now;i++){
				if(names[add[i][0]]==s1&&sct[add[i][2]].s[add[i][1]]==s2){
					cout<<i<<endl;
					break;
				}
			}
		}
		if(op==4){
			int i;
			cin>>i;
			if(add[i][0]==0)	cout<<"ERR"<<endl;
			else cout<<sct[add[i][0]].name<<'.'<<sct[add[i][2]].s[add[i][1]]<<endl;
		}
	}
	return 0;
}
			