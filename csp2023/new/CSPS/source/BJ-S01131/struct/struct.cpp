/*
？什么年代了还出大模拟，衷心地祝愿出题人的母亲身体健康。
哈哈哈原本一度以为我不会 B 了但是居然想出来了逆天改命了！！！
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
int tot;string str;
struct{
	int k,t[200],l;ll len,len2;
	string n[200];
}st[200];
map<string,int>mp;
int max(int a,int b){return a>b?a:b;}
void update(ll&len,int t){int r=len%st[t].l;len+=(r?st[t].l-r:0);}
void jump(ll&len,int t){update(len,t);len+=st[t].len;}
void work1(){
	cin>>str;
	int u=mp[str]=++tot;
	cin>>st[u].k;
	for(int i=0;i<st[u].k;++i)cin>>str>>st[u].n[i],st[u].l=max(st[u].l,st[st[u].t[i]=mp[str]].l),jump(st[u].len,st[u].t[i]);
	st[u].len2=st[u].len;if(st[u].len%st[u].l)st[u].len+=st[u].l-st[u].len%st[u].l;
	cout<<st[u].len<<' '<<st[u].l<<'\n';
}
int tot2;
int t[200];string nm[200];ll lst;
void work2(){
	int u=++tot2;
	cin>>str>>nm[u];
	t[u]=mp[str];
	update(lst,t[u]),cout<<lst<<'\n';lst+=st[t[u]].len;
}
string s[200];
void work3(){
	cin>>str;
	int n=str.length(),k=0;
	for(int i=0;i<n;++i,++k){
		s[k].clear();
		for(;i<n&&str[i]!='.';s[k].push_back(str[i++]));
	}
	ll l=0;int u=1;
	for(;nm[u]!=s[0];jump(l,t[u++]));
	update(l,u=t[u]);
	for(int j=1;j<k;++j){
		int v=0;
		for(;st[u].n[v]!=s[j];jump(l,st[u].t[v++]));
		update(l,u=st[u].t[v]);
	}
	cout<<l<<'\n';
}
void work4(){
	ll L;
	cin>>L;
	if(L>=lst)return (void)(cout<<"ERR\n");
	int u=1;ll l=0,tmp;str.clear();
	for(;tmp=l,jump(tmp,t[u]),tmp<=L;l=tmp,++u);
	update(l,t[u]);if(L<l)return (void)(cout<<"ERR\n");
	if(l+st[t[u]].len2<=L)return (void)(cout<<"ERR\n");
	str+=nm[u];
	if(t[u]<=4)return (void)(cout<<str<<'\n');
	for(u=t[u];;){
		str.push_back('.');
		int v=0;
		for(;tmp=l,jump(tmp,st[u].t[v]),tmp<=L;l=tmp,++v);
		update(l,st[u].t[v]);
		if(L<l)return (void)(cout<<"ERR\n");
		if(l+st[st[u].t[v]].len2<=L)return (void)(cout<<"ERR\n");
		str+=st[u].n[v];
		if(st[u].t[v]<=4)return (void)(cout<<str<<'\n');
		u=st[u].t[v];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("struct.in","r",stdin),freopen("struct.out","w",stdout);
	tot=4;
	st[1].k=0,st[1].l=1,st[1].len=st[1].len2=1;
	st[2].k=0,st[2].l=2,st[2].len=st[2].len2=2;
	st[3].k=0,st[3].l=4,st[3].len=st[3].len2=4;
	st[4].k=0,st[4].l=8,st[4].len=st[4].len2=8;
	mp["byte"]=1,mp["short"]=2,mp["int"]=3,mp["long"]=4;
	int n,op;//op=原批 原神，启动！！！
	for(cin>>n;n--;){
		cin>>op;
		if(op==1)work1();
		else if(op==2)work2();
		else if(op==3)work3();
		else work4();
	}
	return 0;
}