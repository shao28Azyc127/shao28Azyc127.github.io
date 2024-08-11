#include<bits/stdc++.h>
using namespace std;
int n;
string m[80005];
int now,tot;
struct s{
    string basic[105];
    string bname[15];
    int content;
    string name;
}struc[105];
/*
void addbasic(string inn, string what){
    if(inn=="short"){
        m[now++]="short";
        m[now++]="short";
    }else if(inn=="byte"){
        m[now++]="byte";
    }else if(inn=="int"){
        for(int j=1;j<=4;j++){
            m[now++]="int";
        }
    }else if(inn=="long"){
        for(int j=1;j<=8;j++){
            m[now++]="long";
        }
    }
}*/
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        int op,x;
        string inn,what;
        scanf("%d",&op);
        if(op==1){
                /*
            scanf("%s",inn);
            struc[++tot].name=inn;
            int t;
            scanf("%d",&t);
            struc[tot].content=t;
            for(int i=1;i<=t;i++){
                scanf("%s %s",inn,what);
                struc[tot].basic[i]=inn;
                struc[tot].bname[i]=what;
            }*/
        }else if(op==2){
            cin>>inn>>what;
            if(inn=="short"){
                m[now++]=what;
                m[now++]=what;
            }else if(inn=="byte"){
                m[now++]=what;
            }else if(inn=="int"){
                for(int j=1;j<=4;j++){
                    m[now++]=what;
                }
            }else if(inn=="long"){
                for(int j=1;j<=8;j++){
                    m[now++]=what;
                }
            }/*else{
                for(int i=1;i<=tot;i++){
                    if(struc[i].name==what){
                        for(int j=1;j<=struc[i].content;j++){
                            addbasic(struc[i].basic[j],struc[i].bname[j]);
                        }
                        break;
                    }
                }
            }*/
        }else if(op==3){
            cin>>inn;
            for(int i=0;i<=now;i++){
                if(m[i]==inn){
                    printf("%d",i);break;
                }
            }
        }else if(op==4){
            scanf("%d",&x);
            printf("%s\n",m[x]);
        }
    }




    return 0;
}
