#include <bits/stdc++.h>
using namespace std;
map<string,pair<int,int>> mp;
map<int,pair<int,string>> mp1;
int mem=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int q;cin >>q;
    while(q--){
        int op;cin >>op;
        string t,n;
        int addr;
        if(op==1){
            while(true){

            }
        }
        if(op==2){
            cin >>t>>n;
            cout <<mem<<endl;
            if(t=="byte"){
                mp[n].first=mem;
                mp[n].second=mem;
                mp1[mem].first=1;
                mp1[mem].second=n;
                mem++;
            }else if(t=="short"){
                mp[n].first=mem;
                mp[n].second=mem+1;
                mp1[mem].first=2;
                mp1[mem+1].first=2;
                mp1[mem].second=n;
                mp1[mem+1].second=n;
                mem+=2;
            }else if(t=="int"){
                mp[n].first=mem;
                mp[n].second=mem+3;
                mp1[mem].first=3;
                mp1[mem+1].first=3;
                mp1[mem+2].first=3;
                mp1[mem+3].first=3;
                mp1[mem].second=n;
                mp1[mem+1].second=n;
                mp1[mem+2].second=n;
                mp1[mem+3].second=n;
                mem+=4;
            }else{
                mp[n].first=mem;
                mp[n].second=mem+7;
                mp1[mem].first=4;
                mp1[mem+1].first=4;
                mp1[mem+2].first=4;
                mp1[mem+3].first=4;
                mp1[mem+4].first=4;
                mp1[mem+5].first=4;
                mp1[mem+6].first=4;
                mp1[mem+7].first=4;
                mp1[mem].second=n;
                mp1[mem+1].second=n;
                mp1[mem+2].second=n;
                mp1[mem+3].second=n;
                mp1[mem+4].second=n;
                mp1[mem+5].second=n;
                mp1[mem+6].second=n;
                mp1[mem+7].second=n;
                mem+=8;
            }
        }
        if(op==3){
            cin >>t;
            cout <<mp[t].first<<endl;
        }
        if(op==4){
            cin >>addr;
            if(mp1[addr].first){
                cout <<mp1[addr].second<<endl;
            }else{
                cout <<"ERR"<<endl;
            }
        }
    }
    return 0;
}
