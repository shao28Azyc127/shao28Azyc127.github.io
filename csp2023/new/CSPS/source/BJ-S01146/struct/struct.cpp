#include<bits/stdc++.h>
using namespace std;
string tmp,tt;
map<string,long long> p;
map<long long,string> pp;
int n,opr;
long long lst,addr,nw;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    lst=0;
    cin>>n;
    while(n--){
        cin>>opr;
        if(opr==1)
            continue;
        else if(opr==2){
            cout<<lst<<endl;
            cin>>tmp>>tt;
            if(tmp[0]=='b')
                nw=lst+1;
            else if(tmp[0]=='s')
                nw=lst+2;
            else if(tmp[0]=='i')
                nw=lst+4;
            else
                nw=lst+8;
            for(int i=lst;i<nw;i++)
                pp[i]=tt;
            p[tt]=lst;
            lst=nw;
        }
        else if(opr==3){
            cin>>tmp;
            cout<<p[tmp]<<endl;
        }
        else{
            cin>>addr;
            if(addr>=lst)
                cout<<"ERR"<<endl;
            else
                cout<<pp[addr]<<endl;
        }
    }
    return 0;
}
