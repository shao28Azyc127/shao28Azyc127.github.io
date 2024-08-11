#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int Q,opt,tv,T_name=1,T_item=1,T_addr=0,L_addr[100009],LT=0;
string C,C2,C3;
struct tp_item{
    bool istype;
    int n,s,o,paid;
    int P[109];
    unordered_map<string,int> D;
    unordered_map<int,string> Dv;
};
stack<string> ans;
unordered_map<string,int> M_name;
unordered_map<int,string> M_namev;
unordered_map<int,tp_item> M_type;
unordered_map<int,tp_item> M_item;
unordered_map<int,int> M_addr;
inline void ini(tp_item &ti){
    for(int tmp=1;tmp<=ti.n;tmp++){
        //printf(" @item %d (%d,%d)\n",tmp,ti.P[tmp],ti.o);
        ti.o=max(M_type[ti.P[tmp]].s,ti.o);
    }ti.s=ti.n*ti.o;
}
set<int> S_addr;
inline int define(int pid,int tp){
    if(tp<0){
        int adr=T_addr;
        M_addr[T_addr]=pid;
        L_addr[++LT]=T_addr;
        T_addr+=M_type[pid].o;
        return adr;
    }

    for(int q=1;q<=M_type[pid].n;q++){
        int v=M_type[pid].P[q],oadv=T_addr;
        M_item[pid].P[q]=define(++T_item,v);
        M_item[M_item[pid].P[q]].paid=pid;
        T_addr=oadv+M_type[pid].o;
    }return pid;
}
inline void cpy(string &dest,string &s,char mk){
    //cout << "ini " << dest << " "<<s<<"\n";
    dest.resize(s.size());
    int T=0;
    if(s.find('.')==-1){
        dest=s;
        s.erase();
        return;
    }
    while(s[T]!=mk){dest[T]=s[T];++T;}
    dest.erase(T);
    s.erase(0,T+1);
}
int main(){
    ios::sync_with_stdio(0);
    M_name["bool"]=-1;
    M_name["short"]=-2;
    M_name["int"]=-4;
    M_name["long"]=-8;
    tp_item te;
    te.s=1;
    M_type[-1]=te;
    te.s=2;
    M_type[-2]=te;
    te.s=4;
    M_type[-4]=te;
    te.s=8;
    M_type[-8]=te;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> Q;
    for(int qtp=1;qtp<=Q;qtp++){
        cin >> opt;
        //printf("Opt %d\n",opt);
        if(opt==1){
            cin >> C >> opt;
            tp_item ns;
            ns.n=opt;
            //printf("db %d\n",opt);
            for(int q=1;q<=opt;q++){
                cin >> C2>>C3;
                ns.D[C3]=M_name[C2];
                ns.Dv[M_name[C2]]=C3;
                ns.P[q]=M_name[C2];
                //cout << "Attr name "<<C3<<" bind id "<<M_name[C2]<<" and P"<<q<<"\n";
            }
            ini(ns);
            M_name[C]=++T_name;
            M_namev[T_name]=C;
            //printf("db 4\n");
            M_type[M_name[C]]=ns;
            //cout << "Name of "<<C<<" is "<<M_name[C]<<"\n";
            //printf("db 5\n");
            printf("%d %d\n",ns.s,ns.o);
            continue;
        }
        if(opt==2){
            cin >> C2>>C3;
            printf("%d\n",T_addr);
            M_name[C3]=++T_item;
            tp_item ns;
            ns.D=M_type[M_name[C2]].D;
            M_item[M_name[C3]]=ns;
            //cout << "Added "<<C3<<" to item "<<M_name[C3]<<"\n";
            define(M_name[C3],M_name[C2]);
            continue;
        }
        if(opt==3){
            cin >> C;
            cpy(C2,C,'.');
            //cout << C2 << " "<<C<<"\n";
            int idi=M_name[C2];
            while(C.find('.')!=-1){
                cpy(C2,C,'.');
                //cout << "par "<<C2<<" " << idi << " with "<< M_item[idi].D[C2]<<"\n";
                idi=M_item[idi].P[M_item[idi].D[C2]];
            }
            printf("%d\n",idi);
        }
        if(opt==4){
            cin >> opt;
            sort(L_addr+1,L_addr+1+LT);
            int rtn=upper_bound(L_addr+1,L_addr+LT+1,opt)-L_addr;
            int rtv=L_addr[rtn];
            printf("v %d\n",rtv);
            if(M_item[M_addr[rtn]].o+rtn<opt){printf("ERR\n");continue;}
            //while()
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
