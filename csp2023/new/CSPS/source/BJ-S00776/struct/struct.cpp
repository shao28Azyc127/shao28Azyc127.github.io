#include<bits/stdc++.h>
using namespace std;
map<string,long long> mp;
map<long long,string> mp1;
long long mn=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    long long n;
    cin>>n;
    while(n--){
        long long op;
        cin>>op;
        if(op==2){
            string type;
            cin>>type;
            string name;
            cin>>name;
            if(type=="int"){
                if(mn%4==0){
                    mp[name]=mn;
                    for(int i=mn;i<mn+4;i++){
                        mp1[i]=name;
                    }
                    mn+=4;
                }
                else{
                    mn=(mn/4+1)*4;
                    mp[name]=mn;
                    for(int i=mn;i<mn+4;i++){
                        mp1[i]=name;
                    }
                    mn+=4;
                }
            }
            if(type=="short"){
                if(mn%2==0){
                    mp[name]=mn;
                    for(int i=mn;i<mn+2;i++){
                        mp1[i]=name;
                    }
                    mn+=2;
                }
                else{
                    mn=(mn/2+1)*2;
                    mp[name]=mn;
                    for(int i=mn;i<mn+2;i++){
                        mp1[i]=name;
                    }
                    mn+=2;
                }
            }
            if(type=="byte"){
                mp[name]=mn;
                mp1[mn]=name;
                mn++;
            }
            if(type=="long"){
                if(mn%8==0){
                    mp[name]=mn;
                    for(int i=mn;i<mn+8;i++){
                        mp1[i]=name;
                    }
                    mn+=8;
                }
                else{
                    mn=(mn/8+1)*8;
                    mp[name]=mn;
                    for(int i=mn;i<mn+8;i++){
                        mp1[i]=name;
                    }
                    mn+=8;
                }
            }
        }
        if(op==3){
            string name;
            cin>>name;
            cout<<mp[name]<<endl;
        }
        if(op==4){
            long long x;
            cin>>x;
            if(mp1[x]==""){
                cout<<"ERR\n";
            }
            else{
                cout<<mp1[x]<<endl;
            }
        }
    }

    return 0;
}
