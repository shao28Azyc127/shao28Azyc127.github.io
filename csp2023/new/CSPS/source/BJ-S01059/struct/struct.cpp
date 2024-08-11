#include<bits/stdc++.h>
using namespace std;
struct data{
	string name;
	int type;//0:byte,1:short,2:int,3:long;
	int st,len;
};
data f[110];
int n,cnt=1,sp[10010];
void place_(data &x,int which){
	int pos=0;
	while(sp[0]!=0)pos+=x.len;
	x.st=pos;
	cout<<pos<<endl;
	for(int i=pos;i<pos+x.len;i++){
		sp[i]=which;
	}
	return;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		if(op==2){
			string ty,nm;
			cin>>ty>>nm;
			f[cnt++].name=nm;
			if(ty=="btye")f[cnt].type=0;
			if(ty=="short")f[cnt].type=1;
			if(ty=="int")f[cnt].type=2;
			if(ty=="long")f[cnt].type=3;
			if(ty=="btye")f[cnt].len=1;
			if(ty=="short")f[cnt].len=2;
			if(ty=="int")f[cnt].len=4;
			if(ty=="long")f[cnt].len=8;
			place_(f[cnt],cnt);
		}else if(op==3){
			string s;
			cin>>s;
			for(int i=1;i<=cnt;i++){
				if(f[i].name==s){
					cout<<f[i].st<<endl;
				}
			}
		}else if(op==4){
			int k;
			cin>>k;
			if(sp[k])cout<<f[sp[k]].st<<endl;
			else cout<<"ERR\n";
		}
	}
	return 0;
}
