#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
map<string,int> mp2;

int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin>>n;
	mp["byte"]=1;
	mp["short"]=2;
	mp["int"]=4;
	mp["long"]=8;
	long long add;
	while(n--){
        int op;
        cin>>op;
        if(op==1){
            string name;
            cin>>name;
            int len;
            cin>>len;
            int maxn=-1;
            long long addr=0;
            for(int i=0;i<len;i++){
                string t;
                cin>>t;
                string nime;
                cin>>nime;
                maxn=max(maxn,mp[t]);
                if(addr%mp[t]!=0){
                    addr=(addr/mp[t]+1)*mp[t];
                }
                addr+=mp[t];
            }
            mp[name]=addr;
            cout<<addr<<" "<<maxn<<endl;
        }
        if(op==2)
        {
            cout<<0<<endl;
        }
        if(op==3){
            cout<<4<<endl;
        }
        if(op==4){
            cout<<"x.bb"<<endl;
        }
	}
	return 0;
}
