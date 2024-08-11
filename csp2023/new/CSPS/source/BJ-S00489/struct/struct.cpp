#include<bits/stdc++.h>
using namespace std;
const int N=10001,NN=100001;
int n,op,k,lst=0,llo=0,liit=0,lbt=0,st=0,lys=0,yst=0,lxc[N],xc=0;
char s;
string sat[N],lo[N],iit[N],bt[N],nm,lx,ys[N],lxk[N],ffo[NN];
int jswz(int dxx,string nem){
    int i=0;
    while(1){
        if(st<dxx*i) {
            st=dxx*i+dxx-1;
            ffo[st]=nm;
            return 0;
        }
        i++;
    }
}
int main(){
    freopen("struct.in","in",stdin);
    fprintf(stdout,"struct.out");
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>op;
        if(op==1){
            int dx=0,dq=0;
            cin>>s>>k;
            for(int j=0;j<k;j++){
                cin>>lx>>nm;
                if(lx=="long") lo[llo]=nm,llo++,dq=8,jswz(8,nm);
                else if(lx=="short") sat[lst]=nm,lst++,dq=max(dq,2),jswz(2,nm);
                else if(lx=="int") iit[liit]=nm,liit++,dq=max(dq,4),jswz(4,nm);
                else if(lx=="byte") bt[lbt]=nm,lbt++,dq=max(dq,1),jswz(1,nm);
            }
            lxc[xc]=st;
            lxk[xc]=s;
            xc++;
            cout<<st<<" "<<dq;
        }
        if(op==2){
            cin>>lx>>ys[lys];
            lys++;
            cout<<lst;
            if(lx=="long") lst+=4;
            else if(lx=="short") lst+=2;
            else if(lx=="int") lst+=4;
            else if(lx=="byte") lst+=1;
            else{
                for(int j=0;j<xc;j++){
                    if(lx==lxk[j]) lst+=lxc[j];
                }
            }
        }
        if(op==4){
            int addr;
            string ants;
            cin>>addr;
            while(ffo[addr]=="") addr++;
            cout<<ffo[addr];
        }
    }
    return 0;
}