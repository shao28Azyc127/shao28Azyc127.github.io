#include<bits/stdc++.h>
using namespace std;
int l[10000010];
map<int,string>m;
map<string,int>m2;
int nm;
int c[100010];
int n;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    int np=0;
    for(int i=1;i<=n;i++){
        int op;
        scanf("%d",&op);
        if(op==2){
            string ne,me;
            cin>>ne>>me;
            c[m2[me]]=np;
            if(m2[me]==0)m2[me]=++nm,m[m2[me]]=m2[me];
            if(ne=="long"){l[np]=l[np+1]=l[np+2]=l[np+3]=l[np+4]=l[np+5]=l[np+6]=l[np+7]=m2[me];np=ceil(np+8/4);}
            else if(ne=="int"){l[np]=l[np+1]=l[np+2]=l[np+3]=m2[me];np=ceil(np+8/4);}
            else if(ne=="short"){l[np]=l[np+1]==m2[me];np=ceil(np+8/4);}
            else l[np]=m2[me];np=ceil(np+8/4);
        }
        else if(op==3){
            string sn;
            cin>>sn;
            printf("%d\n",c[m2[sn]]);
        }else{
            int lx;
            scanf("%d",&lx);
            if(l[lx]==0)printf("ERR\n");
            else cout<<m[l[lx]]<<endl;
        }
    }
}
