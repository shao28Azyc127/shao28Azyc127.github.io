#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n,m;
map<LL,string> mp;
map<string,LL> where;

int get(string s){
    if(s=="byte") return 1;
    if(s=="short") return 2;
    if(s=="int") return 4;
    if(s=="long") return 8;
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
        }
        else if(op==2){
            string s,nam;
            cin>>s>>nam;
            where[nam]=m;
            int len=get(s);
            for(;len;len--,m++){
                mp[m]=nam;
            }
            cout<<where[nam]<<endl;
        }
        else if(op==3){
            string nam;
            cin>>nam;
            cout<<where[nam]<<endl;
        }
        else if(op==4){
            LL a;
            cin>>a;
            if(!mp.count(a)) cout<<"ERR"<<endl;
            else cout<<mp[a]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}