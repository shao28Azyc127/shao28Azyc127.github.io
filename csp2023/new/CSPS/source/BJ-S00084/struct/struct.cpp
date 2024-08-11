#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("struct.in");
ofstream fout("struct.out");

int n;

int tsz(string s){
    if(s=="byte")
        return 1;
    if(s=="short")
        return 2;
    if(s=="int")
        return 4;
    if(s=="long")
        return 8;
    return -1;
}
struct elm{
    int pos;
    string typ;
};
map <string,elm> m;
int ml=0;
struct str{
    vector <pair<string,string> > mem;
    int lsz,siz;
};
map <string,str> t;

int main(){
    ios::sync_with_stdio(0);
    fin.tie(0);fout.tie(0);
    fin>>n;
    while(n--){
        int op;
        fin>>op;
        if(op==1){
            string strn,ty,na;
            int k;
            fin>>strn>>k;
            str tmp;
            tmp.lsz=0;
            for(int i=1;i<=k;i++){
                fin>>ty>>na;
                tmp.mem.push_back(make_pair(ty,na));
                int x=tsz(ty);
                if(x==-1){
                    x=t[ty].siz;
                }
                tmp.lsz=max(tmp.lsz,x);
            }
            tmp.siz=tmp.lsz*k;
            t[strn]=tmp;
            fout<<tmp.siz<<' '<<tmp.lsz<<endl;
        }
        else if(op==2){
            string ty,na;
            fin>>ty>>na;
            if(tsz(ty)!=-1){
                elm tmp;
                int x=tsz(ty);
                tmp.typ=ty;
                tmp.pos=((ml-1)/x+1)*x;
                m[na]=tmp;
                fout<<ml<<endl;
                ml=tmp.pos+x;
            }
            else{
                str tmp=t[ty];
                int x=tmp.lsz;
                ml=((ml-1)/x+1)*x;
                fout<<ml<<endl;
                for(auto ss:tmp.mem){
                    m[na+'.'+ss.second]=(elm){ml,ss.first};
                    ml+=tmp.lsz;
                }
            }
        }
        else if(op==3){
            string na;
            fin>>na;
            fout<<m[na].pos<<endl;
        }
        else if(op==4){
            int x;
            fin>>x;
            bool flag=1;
            for(auto tmp:m){
                int p=tmp.second.pos,sz=tsz(tmp.second.typ);
                if(p<=x&&x<p+sz){
                    fout<<tmp.first<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag){
                fout<<"ERR"<<endl;
            }
        }
    }


    return 0;
}