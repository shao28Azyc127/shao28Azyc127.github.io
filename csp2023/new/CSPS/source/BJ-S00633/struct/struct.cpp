#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
const int memmax=80000;
struct holder{
    int offset;
    string belong;
};
struct alocator{
    holder holders[memmax+5];
    int used=0;
    alocator(){
    }
    int allocate(int len,int off,string bel){
        int j,i=used;
        for(;i<used+off&&i%off;i++){}
        for(j=i;j<i+len;j++){
            holders[j].offset=i-j;
            holders[j].belong=bel;
        }
        used=j;
        return i;
    }
    void skip(int target){
        used=target;
    }
};
struct nar{
    int used=0;
    nar(){
    }
    int allocate(int len,int off){
        int j,i=used;
        for(;i<used+off&&i%off;i++){}
        for(j=i;j<i+len;j++){}
        used=j;
        return i;
    }
};
struct namedVar{
    string name;
    int off;
};
struct namedVal{
    string name;
    int len;
};
struct structure{
    vector<namedVar> vars;
    map<string,namedVar> varMap;
    vector<namedVal> raws;
    int offset;
    int len;
    structure(){
        
    }
    structure(vector<namedVal> vct){
        //cout<<"init call success"<<endl;
        raws=vct;
        //cout<<"raws copy success"<<endl;
        offset=0;
        nar a;
        //cout<<"alocator init success"<<endl;
        for(namedVal i:vct){
            offset=max(offset,i.len);
        }
        //cout<<"offset max success"<<endl;
        for(namedVal i:vct){
            int off=a.allocate(i.len,i.len);
            namedVar nv;
            nv.name=i.name;
            nv.off=off;
            vars.push_back(nv);
            varMap[i.name]=nv;
            offset=max(offset,i.len);
            len=off+i.len;
        }
        //cout<<"offset calculate success"<<endl;
        while(len%offset){
            len++;
        }
        //cout<<"length fix success"<<endl;
    }
    int create(alocator a,string nm){
        while(a.used%offset){
            a.used++;
        }
        int ret=a.used;
        for(namedVal i:raws){
            a.allocate(i.len,i.len,nm+"."+i.name);
        }
        return ret;
    }
};
map<string,structure> structs;
map<string,pair<structure,int> > defined;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    alocator a;
    cin>>n;
    for(int i=0;i<n;i++){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            vector<namedVal> nvs;
            cin>>s>>k;
            //cout<<"DEFINE STRUCT "<<s<<" START"<<endl;
            for(int j=0;j<k;j++){
                namedVal nv;
                string tn;
                string nm;
                cin>>tn>>nm;
                nv.name=nm;
                if(tn=="byte"){
                    nv.len=1;
                }else if(tn=="short"){
                    nv.len=2;
                }else if(tn=="int"){
                    nv.len=4;
                }else if(tn=="long"){
                    nv.len=8;
                }
                nvs.push_back(nv);
                //cout<<"DEFINE CHILD "<<nm<<" AS "<<tn<<endl;
            }
            structs[s]=structure(nvs);
            //cout<<"DEFINE END"<<endl;
            cout<<structs[s].len<<" "<<structs[s].offset<<"\n";
        }else if(op==2){
            string t,n;
            cin>>t>>n;
            if(t=="byte"){
                cout<<a.allocate(1,1,n)<<"\n";
            }else if(t=="short"){
                cout<<a.allocate(2,2,n)<<"\n";
            }else if(t=="int"){
                cout<<a.allocate(4,4,n)<<"\n";
            }else if(t=="long"){
                cout<<a.allocate(8,8,n)<<"\n";
            }else{
                //cout<<"DEFINE OBJECT "<<n<<" AS "<<t<<endl;
                defined[n]=make_pair(structs[t],structs[t].create(a,n));
                cout<<defined[n].second<<"\n";
            }
        }else if(op==3){
            string s;
            cin>>s;
            string sa=s.substr(0,s.find("."));
            string sb=s.substr(s.find(".")+1);
            //cout<<"ACCESS ATTRIBUTE "<<sb<<" OF "<<sa<<endl;
            cout<<defined[sa].second+defined[sa].first.varMap[sb].off<<"\n";
        }else if(op==4){
            int addr;
            cin>>addr;
            //cout<<"ACCESS MEMORY "<<addr<<endl;
            if(a.holders[addr].belong==""){
                cout<<"ERR";
            }
            cout<<a.holders[addr].belong<<"\n";
        }
    }
    return 0;
}