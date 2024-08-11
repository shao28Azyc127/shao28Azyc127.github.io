#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long Typ,sta,fin;
	string nam;
};
struct tn{
	string nam;
	long long len;
};
typedef long long ll;
const int maxn=105;
int n,op,tot=4,alltot=0,k,allcnt=0,addr;
string s,k1;
Node lis[maxn][maxn];
Node all[maxn];
int alltrie[1050][27];
int trie[105][1050][27];
int cnt[105];
tn typ[maxn];
string t[105],nz[105];
void at_m(string str,int b){
	for(int i=0,now=0;i<=str.size();i++){
		//cout<<i<<" "<<str[i]<<endl;
		if(i==str.size()){
			alltrie[now][0]=b;
			return;
		}
		if(alltrie[now][str[i]-'a'+1]==0) alltrie[now][str[i]-'a'+1]=allcnt++;
		now=alltrie[now][str[i]-'a'+1];
	}
}
void t_m(int num,string str,int b){
	for(int i=0,now=0;i<=str.size();i++){
		if(i==str.size()){
			trie[num][now][0]=b;
			return;
		}
		if(trie[num][now][str[i]-'a'+1]==0) trie[num][now][str[i]-'a'+1]=cnt[num]++;
		now=trie[num][now][str[i]-'a'+1];
	}
	//cout<<num<<endl;
}
int at_c(string str){
	for(int i=0,now=0;i<str.size();i++){
		if(i==str.size()) return alltrie[now][0];
		now=alltrie[now][str[i]-'a'+1];
	}
}
int t_c(int num,string str){
	for(int i=0,now=0;i<str.size();i++){
		if(i==str.size()) return trie[num][now][0];
		now=trie[num][now][str[i]-'a'+1];
	}
}
void Dy(){
	long long Max=-1,l;
	cin>>s>>k;
	typ[tot].nam=s;
	for(int i=0;i<k;i++){
		cin>>t[i]>>nz[i];
		for(l=0;l<105;l++){
			if(typ[l].nam==t[i]){
				break;
			}
		}
		lis[tot][i].Typ=l;
		Max=max(Max,typ[l].len);
	}
	typ[tot].len=Max*k;
	cout<<typ[tot].len<<" "<<Max<<endl;
	ll j;
	for(int i=0,j=0;i<k;i++,j+=Max){
		lis[tot][i].sta=j;
		lis[tot][i].fin=j+typ[lis[tot][i].Typ].len;//×ó±ÕÓÒ¿ª
		t_m(tot,s,i+1);
	}
	tot++;
}
void Zy(){
	cin>>s>>k1;
	int sta_num;
	if(alltot==0) sta_num=0;
	else sta_num=all[alltot-1].fin;
	long long l;
	for(l=0;l<105;l++){
		if(typ[l].nam==s){
			break;
		}
		//cout<<l<<endl;
	}
	cout<<sta_num<<endl;
	all[alltot].Typ=l;
	all[alltot].sta=sta_num;
	all[alltot].fin=sta_num+typ[l].len;//×ó±ÕÓÒ¿ª
	at_m(s,alltot);
	all[alltot].nam=k1;
	//cout<<sta_num<<endl;
	//cout<<"abcd";
	return ;
}
void Cl_z(string str,int num){
	s="";
	int i;
	for(i=0;i<str.size()&&s[i]!='.';i++){
		s=s+str[i];
	}
	str.erase(0,i);
	if(str.size()==0){
		int tmp=t_c(num,s);
		cout<<lis[num][tmp].sta;
		return;
	}
	Cl_z(str,t_c(num,s));
}
void Cl(string str){
	s="";
	int i;
	for(i=0;i<str.size()&&s[i]!='.';i++){
		s=s+str[i];
	}
	str.erase(0,i);
	if(str.size()==0){
		int tmp=at_c(s);
		cout<<all[tmp].sta;
		return;
	}
	Cl_z(str,at_c(s));
}
int aef(int add){
	int l=0,r=alltot-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(all[mid].sta>add){
			r=mid-1;
		}
		else{
			if(all[mid].sta==add){
				l=mid;
				break;
			}
			l=mid;
		}
	}
	return l;
}
int ef(int num,int add){
	int l=0,r=typ[num].len-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(lis[num][mid].sta>add){
			r=mid-1;
		}
		else{
			if(lis[num][mid].sta==add){
				l=mid;
				break;
			}
			l=mid;
		}
	}
	return l;
}
bool Cz(int num,int add){
	int tmp=ef(num,add);
	s=s+typ[lis[num][tmp].Typ].nam;
	if(add>=lis[num][tmp].fin) return false;
	if(all[tmp].Typ>=4) s=s+".";
	else return true;
	add-all[tmp].sta;
	return Cz(lis[num][tmp].Typ,add);
}
bool Ca(int add){
	s="";
	int tmp=aef(add);
	s=s+all[tmp].nam;
	if(all[tmp].Typ>=4) s=s+".";
	else return true;
	add-=all[tmp].sta;
	return Cz(all[tmp].Typ,add);
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	typ[0].nam="byte";
	typ[0].len=1;
	typ[1].nam="short";
	typ[1].len=2;
	typ[2].nam="int";
	typ[2].len=4;
	typ[3].nam="long";
	typ[3].len=8;
	for(int i=0;i<n;i++){
		cin>>op;
		//cout<<"&"<<op<<endl;
		switch(op){
			case 1:Dy();break;
			case 2:Zy();break;
			case 3:cin>>s; Cl(s); cout<<endl; break;
			case 4:cin>>addr; if(Ca(addr)) cout<<s; else cout<<"ERR"; cout<<endl; break;
		}
		//cout<<"*"<<i<<endl;
		//cin>>op>>op>>op>>op;
		//cout<<op<<endl;
		//return 0;
	}
}