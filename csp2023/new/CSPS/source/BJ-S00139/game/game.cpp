#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("game.in","r"),*f2=fopen("game.out","w");
int n;
char s[2000008];
bool f=true;
int main(){
    fscanf(f1,"%d",&n);
    fscanf(f1,"%d",&s[1]);
    for(int i=2;i<=n;i++){
        fscanf(f1,"%d",&s[i]);
        if(s[i]!=s[i-1]){
            f=false;
        }
    }
    if(f){
        fprintf(f2,"%d",n/2);
    }else{
        fprintf(f2,"%d",0);
    }
    return 0;
}
