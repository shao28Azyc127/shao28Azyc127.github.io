#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
char te[3009],rm[3009][3009],fw[3009][3009],xst[3009];
inline bool s_gt(char f,char t){return f<t;}
inline bool s_ls(char f,char t){return f>t;}
inline bool cmst(char *c1,char *c2){for(int q=0;q<M;q++){if(c1[q]==c2[q]){continue;}return c1[q]<=c2[q];}}
inline void cpst(char *src,char dst[3009]){int pnt=0;while(src[pnt]!='\0'){dst[pnt]=src[pnt++];}}
struct _{char un[3009];int i;}F[3009],T[3009];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    //scanf("%d %d\n",&N,&M);
    cin >> N >> M;
    for(int q=0;q<M;q++){xst[q]='z';}
    for(int q=1;q<=N;q++){
        //scanf("%s\n",rm[q]);
        cin >> rm[q];
        //cpst(rm[q],te);
        memcpy(te,rm[q],sizeof(te));
        sort(te,te+M,s_ls);
        if(cmst(te,xst)){memcpy(xst,te,sizeof(te));}
        sort(te,te+M,s_gt);
        memcpy(rm[q],te,sizeof(te));
        //cout << " ! "<<te<<" "<<rm[q]<<"\n";
        //cout << te;
        //printf("! %s\n",te);
    }
    for(int q=1;q<=N;q++){
        //<<" @ "<<rm[q]<<" "<<xst<<" "<<cmst(rm[q],xst)<<"\n";
        if(cmst(rm[q],xst)){printf("1");}
        else{printf("0");}
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
