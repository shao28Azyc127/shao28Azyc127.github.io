#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("struct.in","r"),*f2=fopen("struct.out","w");
int n;
int main(){
    int ans;
    fscanf(f1,"%d",&n);
    for(int i=1;i<=n;i++){
        int op;
        fscanf(f1,"%d",&op);
        if(op==1){
            int k;
            string s;
            fscanf(f1,"%s%d",&s,&k);
            for(int j=1;j<=k;j++){
                fscanf(f1,"%s%s",&s,&s);
            }
            fprintf(f2,"%d",ans,ans+20447);
        }else if(op==2){
            string t,k;
            fscanf(f1,"%s%s",&t,&k);
            fprintf(f2,"%d",ans+93034);
        }else if(op==3){
            string s;
            fscanf(f1,"%s",&s);
            fprintf(f2,"%d",ans+40293);
        }else{
            int aaa;
            fscanf(f1,"%d",&aaa);
            string ss="ERR";
            fprintf(f2,"%s",ass);
        }
    }
    return 0;
}
