#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("struct.in");
ofstream fout("struct.out");
string basts[4]={};
struct structure{
    string name,mem[101];
    short t[101],par,maxi=0,n;
};
struct variate{
    structure stru;
    string name;
    int add;
};
structure Byte={"byte"},Short={"short"},Int={"int"},Long={"long"};
structure strs[101]={Byte,Short,Int,Long};
variate vars[101];
int sizs[101]={1,2,4,8};
int slen=4,varlen=0,mlen=0;
short strut(string tname){
    for(short i=0;i<slen;++i)
        if(tname==strs[i].name) return i;
    return -1;
}
short varsear(string name){
    for(short i=0;i<varlen;++i)
        if(name==vars[i].name) return i;
    return -1;
}
short memsear(string name,structure s){
    for(short i=0;i<s.par;++i)
        if(name==s.mem[i]) return i;
    return -1;
}
void define(){
    structure s;
    fin>>s.name>>s.par;
    string str;
    for(int i=0;i<s.par;++i){
        fin>>str>>s.mem[i];
        s.t[i]=strut(str);
        s.maxi=max(int(s.maxi),sizs[s.t[i]]);
    }
    sizs[slen]=s.maxi*s.par;
    fout<<sizs[slen]<<" "<<s.maxi<<endl;
    s.n=slen;
    strs[slen++]=s;
}
void setvar(){
    variate v;
    string str;
    fin>>str>>v.name;
    v.stru=strs[strut(str)];
    v.add=mlen;
    fout<<v.add<<endl;
    mlen+=v.stru.maxi*v.stru.par;
    vars[varlen++]=v;
}
string fronta(int &pos,string name){
    string ans;
    for(pos=0;pos<name.length();ans+=name[pos],++pos)
        if(name[pos]=='.') return ans;
    pos=-1;
    return ans;
}
string over(int pos,string name){
    string ans;
    for(++pos;pos<name.length();++pos) ans+=name[pos];
    return ans;
}
int visit(string name,structure s){
    int pos,sum;
    string nn=fronta(pos,name);
    for(int i=0;i<s.par;++i) {
        if(s.mem[i]==nn) break;
        sum+=s.maxi;
    }
    if(pos==-1) return sum;
    return sum+visit(over(pos,name),strs[s.t[memsear(nn,s)]]);
}
void visits(){
    string name;
    int pos=0;
    fin>>name;
    variate var=vars[varsear(fronta(pos,name))];
    fout<<var.add+visit(over(pos,name),var.stru)<<endl;
}
bool check(int addr,structure str,string &ans){
    int n_=addr/str.maxi;
    short type=str.t[n_];
    if(addr%str.maxi>=sizs[type]) return false;
    ans+=str.mem[addr/str.maxi];
    if(type<4)return true;
    ans+=".";
    return check(addr%str.maxi,strs[type],ans);
}
void checks(){
    int sum=0,num=0,addr;
    fin>>addr;
    if(addr>mlen){
        fout<<"ERR"<<endl;
        return;
    }
    for(;sum<addr;++num,sum+=sizs[vars[num-1].stru.n]);
    if(sum>addr){
        --num;
        sum-=sizs[vars[num].stru.n];
    }
    structure su=vars[num].stru;
    addr-=sum;
    string ans=vars[num].name+".";
    if(!check(addr,su,ans)){
        fout<<"ERR"<<endl;
        return;
    }
    fout<<ans<<endl;
}
int main(){
    int n,op;
    fin>>n;
    for(int i=0;i<n;++i){
        fin>>op;
        if(op==1) define();
        else if(op==2) setvar();
        else if(op==3) visits();
        else if(op==4) checks();
    }
    fin.close();
    fout.close();
    return 0;
}
