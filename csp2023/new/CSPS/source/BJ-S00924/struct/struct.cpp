#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map<string,int> mname;





int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mname["byte"] = 1;
    mname["short"] = 2;
    mname["int"] = 4;
    mname["long"] = 8;
    vector<string> mmr;
    map<string,int> mstart;
    map<string,vector<string>> ms;
    map<string,vector<string>> mn;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int opt;
        cin>>opt;
        if(opt == 1){
            string name;
            cin>>name;
            int k;
            cin>>k;
            int mx=0;
            vector<string> s;
            vector<string> name1;
            for(int j=0;j<k;j++){
                string a,b;
                cin>>a>>b;
                s.push_back(a);
                name1.push_back(b);
                mx = max(mx,mname[s[j]]);
            }
            mname[name] = mx;
            ms[name] = s;
            mn[name] = name1;

            vector<string> mr;
            for(int j=0;j<k;j++){
                while(mr.size()%mname[s[j]] != 0) mr.push_back("ERR");
                for(int v=0;v<mname[s[j]];v++){
                    mr.push_back("");
                }
            }
            cout<<mr.size()<<" "<<mx<<endl;
        }
        if(opt == 2){
            string s;
            cin>>s;
            string name;
            cin>>name;
            int len=mname[s];
            while(mmr.size()%len != 0) mmr.push_back("ERR");
            if(s != "int"  &&  s != "short"  &&  s != "byte"  &&  s != "long"){
                for(int j=0;j<ms[s].size();j++){
                    while(mmr.size()%mname[ms[s][j]] != 0) mmr.push_back("ERR");
                    mstart[name+"."+mn[s][j]] = mmr.size();
                    for(int c=0;c<mname[mn[s][j]];c++){
                        mmr.push_back(mn[s][j]);
                    }
                }
            }
            else{
                while(mmr.size()%len != 0) mmr.push_back("ERR");
                mstart[name] = mmr.size();
                for(int i=0;i<len;i++){
                    mmr.push_back(name);
                }
            }
//            cout<<len<<endl;
            cout<<mstart[name]<<endl;
        }
        if(opt == 3){
            string name;
            cin>>name;
            cout<<mstart[name]<<endl;
        }
        if(opt == 4){
            int addr;
            cin>>addr;
            if(mmr[addr] == "ERR")
                cout<<"ERR"<<endl;
            else
                cout<<mstart[mmr[addr]]<<endl;
        }
    }
    return 0;
}
