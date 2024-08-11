#include<bits/stdc++.h>
using namespace std;
int n,op;string typ,nam;
map<string,int>mp;
struct Node{int l,r;string s;}cd[100000];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	mp["byte"]=1;mp["short"]=2;
	mp["int"]=4;mp["long"]=8;int t=0,len=0;
	cin>>n;while(n--){
		cin>>op;if(op==2){
			cin>>typ>>nam;int dd;
			for(int i=t;;i++){
				if(i%mp[typ]==0){dd=i;break;}
			}t=dd;cout<<t<<endl;
			cd[++len].s=nam;cd[len].l=t;cd[len].r;
			t+=mp[typ];cd[len].r=t-1;
		}if(op==3){
			cin>>nam;
			for(int i=1;i<=len;i++){
				if(nam==cd[i].s){cout<<cd[i].l<<endl;break;}
			}
		}if(op==4){
			int x;cin>>x;int kj=0;
			for(int i=1;i<=len;i++){
				if(x>=cd[i].l&&x<=cd[i].r){cout<<cd[i].s<<endl;kj=1;break;}
			}if(kj==0)cout<<"ERR"<<endl;
		}
	}return 0;
}