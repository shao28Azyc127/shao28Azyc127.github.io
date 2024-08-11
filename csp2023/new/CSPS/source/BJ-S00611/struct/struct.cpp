#include <bits/stdc++.h>
using namespace std;

const int by=1,sho=2,in=4,lo=8;
struct isstr{
	string leixing,members_name[10010];
	int value,members_all_value,members_addres[10010];
	int kongjian;
}iss[1010];
struct jiben{
	string leixing,name;
	string ns[10010];
	int kongjian;
}jiben[10010];

int kj(string name){
	if(name=="byte")return 1;
	if(name=="short")return 2;
	if(name=="int")return 4;
	if(name=="long")return 8;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		switch(op){
			case 1:
				cin>>iss[i].leixing>>iss[i].value;
				for(int j=1;j<=iss[i].value;j++){
					cin>>iss[i].members_name[j];
					iss[i].members_all_value=0;
				}
				for(int j=1;j<=iss[i].value;j++){
					if(iss[i].members_name[j]=="byte")iss[i].kongjian=1;
					else if(iss[i].members_name[j]=="short")iss[i].kongjian=2;
					else if(iss[i].members_name[j]=="int")iss[i].kongjian=4;
					else if(iss[i].members_name[j]=="long")iss[i].kongjian=8;
					
					iss[i].members_all_value+=kj(iss[i].members_name[j]);
					iss[i].members_addres[i]+=kj(iss[i].members_name[j]);
				}
				if(iss[i].members_all_value%iss[i].kongjian!=0){
					int b=iss[i].members_all_value/iss[i].kongjian;
					iss[i].members_all_value=((b+1)*iss[i].kongjian);
				}
				cout<<iss[i].members_all_value<<" "<<iss[i].kongjian<<endl;
				
			case 2:
				cin>>jiben[i].leixing>>jiben[i].name;
				jiben[i].kongjian+=kj(jiben[i].leixing);
				if(kj(jiben[i].leixing)>kj(jiben[i-1].leixing)){
					int b=jiben[i].kongjian%kj(jiben[i].leixing);
					jiben[i].kongjian+=kj(jiben[i].leixing)-b;
				}
				cout<<jiben[i].kongjian<<endl;
			
			case 3:
				char s[6];
				for(int j=1;j<=5;j++){
					cin>>s[j];
				}
				cout<<iss[i].members_addres[s[6]];
				
			case 4:
				int addr;
				cin>>addr;
				for(int j=1;j<=addr+100;j++){
					if(jiben[j].kongjian>=addr){
						cout<<jiben[j].kongjian<<endl;
					}else cout<<"ERR";
				}
		}
	}
	return 0;
}