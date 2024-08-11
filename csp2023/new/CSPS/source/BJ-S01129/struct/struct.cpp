#include <bits/stdc++.h>
using namespace std;
int siz[4]={1,2,4,8};
map<string,int>m,type;
map<string,pair<int,int>>v;
vector<string>names;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    type["byte"]=1;
    type["short"]=2;
    type["int"]=4;
    type["long"]=8;
    int n,address=0;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==2){
            string t,name;
            cin>>t>>name;
            names.push_back(name);
            address=ceil(address*1.0/type[t])*type[t]+type[t];
            v[name]={address-type[t],address};
            cout<<address-type[t]<<"\n";
        }
        if(op==3){
            string name;
            cin>>name;
            cout<<v[name].first<<"\n";
        }
        if(op==4){
            int addr;
            cin>>addr;
            bool flag=0;
            for(int i=0;i<names.size();++i){
                if(v[names[i]].first<=addr&&addr<v[names[i]].second){
                    cout<<names[i]<<"\n";
                    flag=1;
                    break;
                }
            }
            if(!flag)cout<<"ERR\n";
        }
    }
    return 0;
}
