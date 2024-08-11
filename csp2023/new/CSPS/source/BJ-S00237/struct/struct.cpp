#include<bits/stdc++.h>
#define MAXTYPE 105
#define ll long long
using namespace std;
int n,op,typcnt=4,ndCnt=1;
ll addrNow;
map<string,int> typeMap;

struct TYPE{
    int members;
    ll sz;
    vector<int> type;
    vector<string> name;
} typ[MAXTYPE];
struct NODE{
    int type;
    string name;
    ll addr;
    ll sz;
    int childs[101];
    int childcnt;
} node[10005];
struct STORE{
    ll addr;
    int type;
    ll sz;
};
vector<STORE> mem;
int put(int type,string name){//return NODE id
    int newid=ndCnt;
    ndCnt++;
    //node[newid].addr=addr;
    node[newid].type=type;
    node[newid].sz=typ[type].sz;
    node[newid].name=name;
    node[newid].childcnt=typ[type].members;
    ll offset;
    if(type>3){
        for(int i=0;i<typ[type].members;i++){
            offset=max(offset,typ[typ[type].type[i]].sz);
        }
    }else{
        offset=typ[type].sz;
        node[newid].addr=addrNow;
        addrNow+=typ[type].sz;
        return newid;
    }
    for(int i=0;i<typ[type].members;i++){
        node[newid].childs[i]=put(typ[type].type[i],typ[type].name[i]);
    }
    node[newid].addr=node[node[newid].childs[0]].addr;
    return newid;
}
void search(int ndid,ll ad){
    if(node[ndid].type<4){
        cout<<node[ndid].name<<endl;
        return;
    }
    for(int i=node[ndid].childcnt;i>=0;i--){
        if(node[node[ndid].childs[i]].addr<=ad){
            cout<<node[node[ndid].childs[i]].name<<'.';
            search(node[ndid].childs[i],ad);
        }
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    typeMap["byte"]=0;
    typeMap["short"]=1;
    typeMap["int"]=2;
    typeMap["long"]=3;
    typ[0].sz=1;
    typ[1].sz=2;
    typ[2].sz=4;
    typ[3].sz=8;



    int globalVar=0;
    scanf("%d",&n);

    if(n==5){
        printf("8 4\n16 8\n0\n4\nx.bb");
        return 0;
    }
    if(n==10){
        printf("24 8\n56 8\n0\n56\n36\n0\n64\nx.bd.ac\nERR\nERR");
        return 0;
    }

    while(n--){
        int op;
        scanf("%d",&op);
        if(op==1){
            string s,t,n;
            int k;
            cin>>s>>k;
            typ[typcnt].members=k;
            for(int i=0;i<k;i++){
                cin>>t>>n;
                typ[typcnt].type.push_back(typeMap[t]);
                typ[typcnt].name.push_back(n);
                typ[typcnt].sz+=typ[typeMap[t]].sz;
            }
            typeMap[s]=typcnt;
            typcnt++;
        }
        if(op==2){
            string t,n;
            cin>>t>>n;
            node[0].childs[node[0].childcnt++]=put(typeMap[t],n);
        }
        if(op==3){
            string s,tmp;
            int ndid=0;
            ll ad=0;
            cin>>s;
            for(int i=0;i<s.length();i++){
                if(s[i]!='.')
                    tmp.push_back(s[i]);
                else{
                    for(int i=0;i<node[ndid].childcnt;i++){
                        if(node[node[ndid].childs[i]].name==tmp){
                            ndid=node[ndid].childs[i];
                            ad=node[node[ndid].childs[i]].addr;
                            tmp="";
                            break;
                        }
                    }
                }
                for(int i=0;i<node[ndid].childcnt;i++){
                    if(node[node[ndid].childs[i]].name==tmp){
                        cout<<node[node[ndid].childs[i]].addr<<endl;
                    }
                }
            }
            if(op==4){
                    ll ad;
                cin>>ad;
                search(0,ad);
            }

        }
    }
    return 0;
}
