#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
map<string,ll> ma;
string name[N][2];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	cin>>T;
	ll cnt=0;
	int num=0;
	while(T--){
		int op;
		cin>>op;
		string s1,s2;
		if(op==2){
			cin>>s1>>s2;
			if(cnt!=0){
				if(s1=="byte"){
					cnt++;
				}
				if(s1=="short"){
					cnt=(cnt%2)+cnt;
				}
				if(s1=="int"){
					cnt=4-(cnt%4)+cnt;
				}
				if(s1=="long"){
					cnt=8-(cnt%8)+cnt;
				}

			}
			ma[s2]=cnt;
			if(s1=="byte"){
				cnt++;
			}
			if(s1=="short"){
				cnt+=2;
			}
			if(s1=="int"){
				cnt+=4;
			}
			if(s1=="long"){
				cnt+=8;
			}
			name[++num][0]=s1;
			name[num][1]=s2;
		}
		if(op==3){
			bool flag=0;
			cin>>s1;
			for(int i=0;i<(int)(s1.size());i++) if(s1[i]=='.') flag=1;
			if(!flag){
				cout<<ma[s1]<<endl;
			}
		}
		if(op==4){
			bool flag=0;
			ll xxx;
			cin>>xxx;
			if(xxx>cnt) cout<<"ERR"<<endl;
			else{
				for(int i=1;i<=num;i++){
					if(name[i][0]=="byte"){
						if(xxx==ma[name[i][1]]) cout<<name[i]<<endl,flag=1;
					}
					if(name[i][0]=="short"){
						if(xxx>=ma[name[i][1]]&&xxx<=ma[name[i][1]]+1) cout<<name[i][1]<<endl,flag=1;
					}
					if(name[i][0]=="int"){
						if(xxx>=ma[name[i][1]]&&xxx<=ma[name[i][1]]+3) cout<<name[i][1]<<endl,flag=1;
					}
					if(name[i][0]=="long"){
						if(xxx>=ma[name[i][1]]&&xxx<=ma[name[i][1]]+7) cout<<name[i][1]<<endl,flag=1;
					}
				}
				if(!flag) cout<<"ERR"<<endl;
			}
		}
	}
}
