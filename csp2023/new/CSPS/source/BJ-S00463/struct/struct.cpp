#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
map<string,int>mp;
struct stru{
    string l[110];
    int num[110];
}s[110];
string add[10000];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int b=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;

        if(op==2){
            string a,name;
            cin>>a>>name;
            mp[name]=b;
            if(a=="byte"){
                add[b]=name;
                b++;
            }else if(a=="short"){
                add[b]=name;
                b++;
                add[b]=name;
                b++;
            }else if(a=="int"){
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
            }else{

                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
                add[b]=name;
                b++;
            }
        }else if(op==3){
            string name;
            cin>>name;
            cout<<mp[name]<<endl;
        }else{
            int k;
            cin>>k;
            if(k>=b)cout<<"ERR"<<endl;
            else cout<<add[k]<<endl;
        }
    }
}
