#include<bits/stdc++.h>
#define MaxN 10000
using namespace std;
int n,scnt = 1,vcnt = 1,p = 0;
int spa[MaxN*100],siz[MaxN];
void makeV(string a,string b,int siz){
    int be = (p+siz-1)/siz*siz;
    if(a=="short"){
        for(int i = be;i<be+2;i++){
            spa[i] = vcnt-1;
        }
        p = be+2;
    }else if(a=="byte"){
        for(int i = be;i<be+1;i++){
            spa[i] = vcnt-1;
        }
        p = be+1;
    }else if(a=="int"){
        for(int i = be;i<be+4;i++){
            spa[i] = vcnt -1;
        }
        p = be+4;
    }else if(a=="long"){
        for(int i =be;i<be+8;i++){
            spa[i] = vcnt -1;
        }
        p = be+8;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    //struct
    map<string,int> s;
    string vrecord[MaxN];
    vector<pair<string,string>> srecord[101];
    map<string,int> vsize;
    vsize.insert(make_pair("short",2));
    vsize.insert(make_pair("byte",1));
    vsize.insert(make_pair("long",8));
    vsize.insert(make_pair("int",4));
    //var
    map<string,int> v;
    cin >> n;
    while(n--){
        int opt;
        cin >> opt;
        if(opt==1){
            string name;
            int k;
            cin >> name;
            s.insert(make_pair(name,scnt++));
            cin >> k;
            int siznum = 0;
            for(int i = 1;i<=k;i++){
                string a,b;
                cin >> a >> b;
                srecord[scnt-1].push_back(make_pair(a,b));
                vrecord[vcnt] = b;
                v.insert(make_pair(b,vcnt++));
                siznum = max(siznum,vsize[a]);
            }
            siz[scnt-1] = siznum;
            for(int i = 0;i<k;i++){
                makeV(srecord[scnt-1][i].first,srecord[scnt-1][i].second,siznum);
            }
            cout << k*siznum << ' ' << siznum << endl;
        }else if(opt==2){
            string a,b;
            if(vsize[a]==0){
                cout << (p+siz[s[a]]-1)/siz[s[a]]*siz[s[a]];
                for(int i = 0;i<srecord[s[a]].size();i++){
                    vrecord[vcnt] = b+"."+srecord[s[a]][i].second;
                    v.insert(make_pair(b+"."+srecord[s[a]][i].second,vcnt++));
                    makeV(srecord[s[a]][i].first,srecord[s[a]][i].second,siz[s[a]]);
                }
            }else{
                cout << (p+vsize[a]-1)/vsize[a]*vsize[a];
                vrecord[vcnt] = b;
                v.insert(make_pair(b,vcnt++));
            }
            cout << endl;
        }else if(opt==3){
            string a;
            for(int i = 0;i<=p;i++){
                if(spa[i]==v[a]){
                    cout << i <<endl;
                    break;
                }
            }
        }else if(opt==4){
            int ran;
            cin >> ran;
            if(spa[ran]==0){
                cout << "ERR"<<endl;
            }else{
                cout << vrecord[spa[ran]]<<endl;
            }
        }
    }
    return 0;
}
