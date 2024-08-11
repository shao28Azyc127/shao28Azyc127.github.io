#include<bits/stdc++.h>
using namespace std;
int n;
struct CCFStruct{
    int size=0,match=1;
    map<string,CCFStruct> members;
    void addMember(CCFStruct member,string name){
        size+=member.size;
        match=max(match,member.match);
        members[name]=member;
    }
};
map<string,CCFStruct> structs;
struct Object{
    string name,type;
    long long begin=0,end=0;
};
map<string,Object> objects;
long long cur;
vector<Object> memory;
bool isBasicType(string type){
    return type=="int"||type=="byte"||type=="long"||type=="short";
}
void addObject(Object object){
    objects[object.name]=object;
    int t=structs[object.type].match;
    cut+=t-cur%t;
    memory.push_back()
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    structs["int"]={4,4};
    structs["byte"]={1,1};
    structs["long"]={8,8};
    structs["short"]={2,2};
    scanf("%d",&n);
    while(n--){
        int op;
        scanf("%d",&op);
        if(op==1){
            string name;
            int k;
            cin>>name>>k;
            CCFStruct new_struct;
            for(int i=1;i<=k;i++){
                string type,tname;
                cin>>type>>tname;
                new_struct.addMember(structs[type],tname);
            }
            structs[name]=new_struct;
        }
        if(op==2){
            string type,name;
            cin>>type>>name;
            addObject({name,type});
        }
    }
    return 0;
}
