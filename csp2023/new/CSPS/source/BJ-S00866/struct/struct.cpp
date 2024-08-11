#include <bits/stdc++.h>
using namespace std;

struct kind{
    char name[12];
    char vari[10];
    int leng[110];
    int pos[110];
    int qi=0;
    int summ=0;
}go[110];

struct stre{
    int leng;
    int pos;
    int name[12];
}neww[110];

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    memset(go,0,sizeof(go));
    int stuff=1;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int tmp=0;
            scanf("%s%d",&go[stuff].name,&tmp);
            for(int k=1;k<=tmp;k++){
                char aaaaa[10];
                scanf("%s%s",&aaaaa,&go[stuff].vari);
                go[stuff].pos[k]=go[stuff].leng[k-1]+go[stuff].pos[k-1];
                if(!strcmp(aaaaa,"short")){
                    go[stuff].leng[k]=2;
                    if(go[stuff].pos[k]%2!=0){
                        while(go[stuff].pos[k]%2!=0)
                            go[stuff].pos[k]++;
                    }
                    go[stuff].qi=max(2,go[stuff].qi);
                }
                else if(!strcmp(aaaaa,"byte")){
                    go[stuff].leng[k]=1;
                    if(go[stuff].pos[k]%1!=0){
                        while(go[stuff].pos[k]%1!=0)
                            go[stuff].pos[k]++;
                    }
                    go[stuff].qi=max(1,go[stuff].qi);
                }
                else if(!strcmp(aaaaa,"int")){
                    go[stuff].leng[k]=4;
                    if(go[stuff].pos[k]%4!=0){
                        while(go[stuff].pos[k]%4!=0)
                            go[stuff].pos[k]++;
                    }
                    go[stuff].qi=max(4,go[stuff].qi);
                }
                else if(!strcmp(aaaaa,"long")){
                    go[stuff].leng[k]=8;
                    if(go[stuff].pos[k]%8!=0){
                        while(go[stuff].pos[k]%8!=0)
                            go[stuff].pos[k]++;
                    }
                    go[stuff].qi=max(8,go[stuff].qi);
                }
                else{
                    for(int l=0;l<stuff;l++){
                        if(!strcmp(go[stuff].name,go[l].name)){
                            go[stuff].leng[k]=go[l].summ;
                            if(go[stuff].pos[k]%go[l].qi!=0){
                                while(go[stuff].pos[k]%go[l].qi!=0)
                                go[stuff].pos[k]++;
                            }
                            go[stuff].qi=max(go[l].qi,go[stuff].qi);
                            break;
                        }
                    }
                }
            }
            printf("%d %d\n",go[stuff].pos[tmp]+go[stuff].leng[tmp],go[stuff].qi);
            go[stuff].summ=go[stuff].pos[tmp]+go[stuff].leng[tmp];
        }

        if(op==2){
            /*char aaaaa[10];
            scanf("%s%s",&aaaaa,&neww.name);
            if(!strcmp(aaaaa,"short")){
                neww[].leng=2;
                if(go[stuff].pos[k]%2!=0){
                    while(go[stuff].pos[k]%2!=0)
                        go[stuff].pos[k]++;
                }
                go[stuff].qi=max(2,go[stuff].qi);
            }*/
        }
    }
    return 0;
}
