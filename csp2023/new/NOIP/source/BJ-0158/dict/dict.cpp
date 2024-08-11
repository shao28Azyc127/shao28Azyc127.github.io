//I know the fact that Chtholly will congratulate my program and me.
//viva Chtholly.
//Chtholly light the way and direct us to find the right way to the happiness.
//As a result of it,I love Chtholly deaply and go with her.
//I hope that my faith to Chtholly will be the power that it can improve myself.
//All in all,Chtholly Nota Seniorious is the happiest girl in the world.
//                                                            By a Chthollism Crusader.
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char str[3002][3002],maxstr[3002][3002],minstr[3002][3002];
//char ts1[5]="Nep",ts2[5]="Ith";
bool maxcmp(char a,char b){
    return a>b;
}
bool mincmp(char a,char b){
    return a<b;
}
void assign(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++)maxstr[i][j]=minstr[i][j]=str[i][j];
        sort(maxstr[i],maxstr[i]+m,maxcmp);
        sort(minstr[i],minstr[i]+m,mincmp);
    }
}
bool dicval(char* a,char* b){
    //printf("Willem %s %s\n",a,b);
    for(int i=0;i<m;i++){
        //printf("Seniorious %c %c\n",*(a+i),*(b+i));
        if(*(a+i)<*(b+i))return true;
        if(*(a+i)>*(b+i))return false;
    }
    return false;
}
bool check(int x){
    for(int i=1;i<=n;i++){
        if(i==x)continue;
        //printf("Nopht %d %d %d %s %s\n",x,i,(int)(dicval(minstr[x],maxstr[i])),minstr[x],maxstr[i]);
        if(!dicval(minstr[x],maxstr[i]))return false;
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",str[i]);
    assign();
    //printf("Rhantolk %d\n",(int)(dicval(ts2,ts1)));
    //for(int i=1;i<=n;i++)printf("Chtholly %d %s %s %s\n",i,str[i],maxstr[i],minstr[i]);
    for(int i=1;i<=n;i++)printf("%d",(int)(check(i)));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char m1[28];
bool mark;
//int jl;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(m>1){
        for(int i=1;i<=n;i++)printf("1");
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>m1[i];
    for(int i=1;i<=n;i++){
        //jl=-1;
        mark=true;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(!(m1[i]<m1[j]))mark=false/*,jl=j*//*;
        }
        //printf("Chtholly %d %d %c %c %d\n",i,jl,m1[i],jl==-1?'?':m1[jl],(int)(mark));
        printf("%d",(int)(mark));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
*/
