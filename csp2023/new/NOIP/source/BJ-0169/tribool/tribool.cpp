#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int C,T,n,m;
int h[N];

int get(char a){
    if(a=='T') return -1;
    if(a=='F') return -2;
    if(a=='U') return -3;
}

void work1(char op,int x1,int x2){
}

void work2(char op,int x){
    if(C==3 || C==4 || C==5 || C==6){
        h[x]=get(op);
    }
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        for(int i=1;i<=n;++i) h[i]=0;
        scanf("%d%d",&n,&m);
        for(int p=1;p<=m;++p){
            char op;
            int i,j;
            cin>>op;
            if(op=='+' || op=='-'){
                scanf("%d%d",&i,&j);
                work1(op,i,j);
            }
            else{
                scanf("%d",&i);
                work2(op,i);
            }
        }
        if(C==3 || C==4){
            int res=0;
            for(int i=1;i<=n;++i) if(h[i]==-3) res++;
            printf("%d\n",res);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}