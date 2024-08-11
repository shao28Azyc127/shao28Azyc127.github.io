#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> types;
vector<string> structor;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    types.insert({"byte",1});
    types.insert({"short",2});
    types.insert({"int",4});
    types.insert({"long",8});
    int sum_mem=0;
    for(int i=0;i<n;i++){
       int op;
       cin>>op;
       if(op==1){
        string s;
        int k;
        cin>>s>>k;
        int size_s=0,rule=0;
        while(k--){
            string t,n;
            cin>>t>>n;
            size_s=types.at(t)+(types.at(t)-(size_s%types.at(t)));
            rule=max(rule,types.at(t));

        }
        types.insert({s,size_s});
        cout<<size_s<<' '<<rule;
       }else if(op==2){
        string t,n;
        cin>>t>>n;
        cout<<sum_mem+types.at(t)-(sum_mem%types.at(t);
       }else if(op==3){
       }else if(op==4){
       }
    }
    return 0;
}
