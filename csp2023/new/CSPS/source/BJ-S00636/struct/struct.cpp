#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
struct node{
	string tittle;
	int k;
	string type[N];
	string name[N];
	int STD,sz;
}s[N];
map<string,int> belong_s;
int tot,tot2;
long long now;
string Name[N],Type[N];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		if(op==1){
			tot++;
			cin>>s[tot].tittle>>s[tot].k;
			belong_s[s[tot].tittle]=tot;
			for(int i=1;i<=s[tot].k;i++){
				cin>>s[tot].type[i]>>s[tot].name[i];
				int tmp;
				if(belong_s[s[tot].type[i]]){
					tmp=s[belong_s[s[tot].type[i]]].STD;
				}else if(s[tot].type[i]=="byte"){
					tmp=1;
				}else if(s[tot].type[i]=="short"){
					tmp=2;
				}else if(s[tot].type[i]=="int"){
					tmp=4;
				}else if(s[tot].type[i]=="long"){
					tmp=8;
				}
				s[tot].STD=max(s[tot].STD,tmp);
			}
			cout<<(s[tot].sz=s[tot].STD*s[tot].k)<<' '<<s[tot].STD<<'\n';
		}else if(op==2){
			tot2++;
			cin>>Type[tot2]>>Name[tot2];
			int tmp;
			if(belong_s[Type[tot2]]){
				tmp=s[belong_s[Type[tot2]]].STD;
			}else if(Type[tot2]=="byte"){
				tmp=1;
			}else if(Type[tot2]=="short"){
				tmp=2;
			}else if(Type[tot2]=="int"){
				tmp=4;
			}else if(Type[tot2]=="long"){
				tmp=8;
			}
			cout<<((now+(tmp-now%tmp))==0)?0:(now+(tmp-now%tmp));
			now=now+(tmp-now%tmp)+tmp-1;
		}else if(op==3){
			string s;
			cin>>s;
			
		}else if(op==4){
			int addr;
			cin>>addr;
			cout<<"ERR\n";
		}
	}
	return 0;
}
