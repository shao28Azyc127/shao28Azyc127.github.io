#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op;
    string s;
    cin>>n;
    struct d{
        short a;
        int b;
        short c;
    };

    int k,t,n1,m,s1;
    for(int i=0;i<n;i++){
        m=0;
        s1=0;
        scanf("%d",&op);
        if(op==1){
            scanf("%s",&s);
            scanf("%d",&k);
            for(int i=0;i<k;i++){
                scanf("%s%s",&t,&n1);
                if(t=='short') n=2,m+=1;
                if(t=='int') n=4,m+=7;
                if(t=='long') n=8,m+=9;
                printf("%s",t);
                printf("%d",m);
                printf(" ");
                printf("%d",n);
                printf("\n");
            }
        }
        if(op==2){
            scanf("%s%s",&t,&n1);
            printf("%d",s1);
            printf("\n");
            s1++;
        }
        if(op==3){
            scanf("%s",&s);

        }
        if(op==4){
            int addr;
            scanf("%d",&addr);

        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
