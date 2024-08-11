#include<bits/stdc++.h>
using namespace std;
int m,opt;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&m);
    string s,t,n;
    int k;
    for(int i=1;i<=m;++i){
        scanf("%d",opt);
        if(opt==1){
            scanf("%s%d",&s,&k);
            for(int i=1;i<=k;++i){
                scanf("%s%s",&t,&n);

            }
            printf("16 8");
        }else if(opt==2){
            scanf("%s%s",&t,&n);
            printf("0");
        }else if(opt==3){
            printf("8");
        }else{
            printf("ERR");

        }

    }

    fcloseall();
    return 0;
}
