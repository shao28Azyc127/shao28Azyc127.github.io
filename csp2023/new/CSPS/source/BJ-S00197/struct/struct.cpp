#include<iostream>
#include<math.h>
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

ifstream iff;
ofstream of;
int n;
long long add;
int op;
string name;
int typec;

struct typebase{
int typesize;
string name;
};

typebase tb[200]; int tbsize=0;

struct type{
string name;
int typeidv;

};type realtype[100000];int rtsize=0;
struct realstruct{
int rbs=0;

type t[200];
};
struct typestruct{
int tbs=0;
int maxsize;
type t[200];
};



typestruct ts[200];  int tssize=0;
map<string,int> tnametotid;
map<string,int> nametoid;
map<int,long long> idtoadd;
long long addtoid[100000]; int bisize=0;
int addstruct(int rtid){
        idtoadd[rtid]=add;

        if(realtype[rtid].typeidv<=4){
            addtoid[++bisize]=rtid;
            add+=tb[realtype[rtid].typeidv].typesize;
        }
        else{
        for(int i=0;i<ts[realtype[rtid].typeidv].tbs;i++){
          //ts[realtype[rtsize].typeidv].t[i].name
          //tb[ts[realtype[rtsize].typeidv].t[i].typeidv].typesize
          string m=realtype[rtid].name+"."+ts[realtype[rtid].typeidv].t[i].name;
          nametoid[m]=++rtsize;
          realtype[rtsize].name=m;
          realtype[rtsize].typeidv=ts[realtype[rtid].typeidv].t[i].typeidv;
          addstruct(rtsize);
        }
        }
}



int main(){
tb[1].name="byte";tb[1].typesize=1;
tb[2].name="short";tb[2].typesize=2;
tb[3].name="int";tb[3].typesize=4;
tb[4].name="long";tb[4].typesize=8;
tnametotid["byte"]=1;
tnametotid["short"]=2;
tnametotid["int"]=3;
tnametotid["long"]=4;
tbsize=4;
iff.open("struct.in");
of.open("struct.out");
iff>>n;
for(int i=0;i<n;i++){
    iff>>op;
    if(op==1){
        iff>>name>>typec;
        tbsize++;
        tb[tbsize].name=name;

        ts[tbsize].tbs=typec;
        tnametotid[name]=tbsize;
        for(int j=0;j<typec;j++){
           string na,ma;
           iff>>na>>ma;
           ts[tbsize].t[j].name=ma;
           ts[tbsize].t[j].typeidv=tnametotid[na];
           ts[tbsize].maxsize=max(ts[tbsize].maxsize,tb[ts[tbsize].t[j].typeidv].typesize);
        }
        tb[tbsize].typesize=typec*ts[tbsize].maxsize;
         of<< tb[tbsize].typesize<<' '<< ts[tbsize].maxsize<<endl;
    }
    if(op==2){
        string na,ma;
        iff>>na>>ma;
        nametoid[ma]=++rtsize;
        of<<add<<endl;
        realtype[rtsize].name=ma;
        realtype[rtsize].typeidv=tnametotid[na];
        addstruct(rtsize);

       // add+=tb[realtype[++rtsize].typeidv].typesize;
    }
    if(op==3){
        iff>>name;
        of<<idtoadd[nametoid[name]]<<endl;
    }
    if(op==4){
        long long l,l0=0;

        iff>>l;
        if(l>add){of<<"ERR"<<endl;continue;}
        for(int i=1;i<=bisize;i++){
            l0+=tb[realtype[addtoid[i]].typeidv].typesize;
            if(l0>l)
            {
                of<<realtype[addtoid[i]].name<<endl;
                break;
            }
        }

    }

}

}




//a b c d e
//f g h i j
//差 同 可以一次调整得到---其他数字相同   10
//一个数字不同 可以一次调整得到  10
//连边 A B 2   A C  2   位置不同  B C 2
