#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
string p[MAXN];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T;
    scanf("%d",&T);
    int k=0;
    while(T--){
        int op;
        scanf("%d",&op);
        if(op==2){
            string t,n;
            scanf("%s%s",&t,&n);
            if(t=="byte"){
                p[++k]=n;
            }
            else if(t=="short"){
                k=(k/2+1)*2-1;
                for(int i=1;i<=2;i++){
                    p[++k]=n;
                }
            }
            else if(t=="int"){
                k=(k/4+1)*4-1;
                for(int i=1;i<=4;i++){
                    p[++k]=n;
                }
            }
            else{
                k=(k/8+1)*8-1;
                for(int i=1;i<=8;i++){
                    p[++k]=n;
                }
            }
        }
        else if(op==3){
            string n;
            scanf("%s",&n);
            for(int i=1;i<=k;i++){
                if(p[i]==n){
                    printf("%d\n",i);
                    break;
                }
            }
        }
        else{
            int n;
            scanf("%d",&n);
            if(p[n]=="") printf("ERR");
            else    printf("%s",p[n]);
        }
    }
    return 0;
}
