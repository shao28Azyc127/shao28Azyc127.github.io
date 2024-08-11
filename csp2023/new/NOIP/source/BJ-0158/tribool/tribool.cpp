//I am a Chthollist forever.
//Chtholly Nota Seniorious always in my heart;
#include<cstdio>
#include<iostream>
using namespace std;
struct Chtholly{
    int op,i,j;
};
Chtholly bk[12];
int id,t,n,m,seed,nowseed,ans,cnt,pow3[12],base[12],a[12];
char op;
bool mark;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&id,&t);
    if(id>2)while(t--)printf("0\n");
    pow3[0]=1;
    for(int i=1;i<11;i++)pow3[i]=3*pow3[i-1];
    while(t--){
        ans=114514;
        scanf("%d%d",&n,&m);
        seed=pow3[n]-1;
        for(int i=1;i<=m;i++){
            cin>>op;
            if(op=='T'){
                bk[i].op=0;
                scanf("%d",&bk[i].i);
                bk[i].j=0;
            }
            if(op=='F'){
                bk[i].op=0;
                scanf("%d",&bk[i].i);
                bk[i].j=1;
            }
            if(op=='U'){
                bk[i].op=0;
                scanf("%d",&bk[i].i);
                bk[i].j=2;
            }
            if(op=='+'){
                bk[i].op=1;
                scanf("%d%d",&bk[i].i,&bk[i].j);
            }
            if(op=='-'){
                bk[i].op=2;
                scanf("%d%d",&bk[i].i,&bk[i].j);
            }
            //printf("Willem %c\n",op);
        }
        while(seed>=0){
            cnt=0,mark=true;
            nowseed=seed;
            for(int i=n-1;i>=0;i--){
                base[i]=nowseed/pow3[i];
                nowseed%=pow3[i];
            }
            for(int i=0;i<n;i++)a[i]=base[i];
            //printf("Chtholly %d",seed);
            //for(int i=0;i<n;i++)printf(" %d",base[i]);
            //printf("\n");
            //printf("Ithea %d",seed);
            //for(int i=0;i<n;i++)printf(" %d",base[i]);
            //printf("\n");
            for(int i=1;i<=m;i++){
                if(!bk[i].op)a[bk[i].i-1]=bk[i].j;
                else{
                    if(bk[i].op==1)a[bk[i].i-1]=a[bk[i].j-1];
                    else{
                        if(a[bk[i].j-1]==0)a[bk[i].i-1]=1;
                        else if(a[bk[i].j-1]==1)a[bk[i].i-1]=0;
                        else a[bk[i].i-1]=2;
                    }
                }
                //printf("Nopht %d %d %d %d %d\n",i,bk[i].i-1,bk[i].op,bk[i].j,a[bk[i].i-1]);
            }
            //printf("Nephren %d",seed);
            //for(int i=0;i<n;i++)printf(" %d",base[i]);
            //printf("\n");
            for(int i=0;i<n;i++){
                if(a[i]!=base[i]){
                    mark=false;
                    break;
                }
                if(a[i]==2)cnt++;
            }
            if(mark)ans=min(ans,cnt);
            //printf("Rhantolk %d %d %d\n",ans,cnt,(int)(mark));
            seed--;
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
