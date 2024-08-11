#include<bits/stdc++.h>
using namespace std;
struct st{
	vector<string> son;
	vector<int> stype;
	int size;
	int dq;
	int method[805];
}s[123];
string nst[123],nbl[123];
struct bl{
	int k;
	int l;
}b[123];
int finds(string s){
	for(int i=1;i<=110;i++)if(nst[i]==s)return i;
	return 0;
}
int findb(string s){
	for(int i=1;i<=110;i++)if(nbl[i]==s)return i;
	return 0;
}
int n,op,ids=4,idb,line[1000005],len;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	s[1].size=s[1].dq=1;
	s[2].size=s[2].dq=2;
	s[3].size=s[3].dq=4;
	s[4].size=s[4].dq=8;
	s[1].method[0]=1;
	for(int i=0;i<2;i++)s[2].method[i]=1;
	for(int i=0;i<4;i++)s[3].method[i]=1;
	for(int i=0;i<8;i++)s[4].method[i]=1;
	nst[1]="byte";
	nst[2]="short";
	nst[3]="int";
	nst[4]="long";
	while(n--){
		cin >> op;
		if(op==1){
			int k;
			string tmp;
			cin >> k >> tmp;
			nst[++ids]=tmp;
			for(int i=1;i<=k;i++){
				string s1,s2;
				cin >> s1 >> s2;
				int nm=finds(s1);
				s[ids].stype.push_back(nm);
				s[ids].son.push_back(s2);
				s[ids].dq=max(s[ids].dq,s[nm].dq);
				if(s[ids].size%s[nm].dq==0){
					for(int j=0;j<s[nm].size;j++)if(s[nm].method[j])s[ids].method[s[ids].size+j]=i;
					s[ids].size+=s[nm].size;
				}
				else{
					s[ids].size=(s[ids].size-s[ids].size%s[nm].dq)+s[nm].dq;
					for(int j=0;j<s[nm].size;j++)if(s[nm].method[j])s[ids].method[s[ids].size+j]=i;
					s[ids].size+=s[nm].size;
				}
			}
			if(s[ids].size%s[ids].dq!=0)s[ids].size=(s[ids].size-s[ids].size%s[ids].dq)+s[ids].dq;
			cout << s[ids].size << " " << s[ids].dq << endl;
		}else if(op==2){
			string ty,na;
			cin >> ty >> na;
			int idl=finds(ty);
			nbl[++idb]=na;
			b[idb].k=idl;
			if(len%s[b[idb].k].dq!=0)len=(len-len%s[b[idb].k].dq)+s[b[idb].k].dq;
			b[idb].l=len;
			for(int i=0;i<s[b[idb].k].size;i++){
				line[b[idb].l+i]=idb;
			}
			len+=s[b[idb].k].size;
			cout << b[idb].l << endl;
		}else if(op==3){
			;
		}else{
		bool flag=1;
			long long add;
			cin >> add;
			if(!line[add])cout << "ERR";
			else{
				
				if(nst[b[line[add]].k]>4){
					add-=s[b[line[add]].k].l;
					if(s[b[line[add]].k].method[add])cout << nbl[line[add]] << "." << s[b[line[add]].k].son[s[b[line[add]].k].method[add]-1];
					else {cout << "ERR";flag=0;}
				}
				else cout << nbl[line[add]];
			}
			cout << endl;
		}
	}
	return 0;
}