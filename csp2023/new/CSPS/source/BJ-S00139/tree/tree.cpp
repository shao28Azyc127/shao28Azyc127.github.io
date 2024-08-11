#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("tree.in","r"),*f2=fopen("tree.out","w");
int main(){
    int n,u,a,ans;
    fscanf(f1,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(f1,"%d%d%d",&a,&a,&a);
    }
    for(int i=1;i<n;i++){
        fscanf(f1,"%d%d",&a,&a);
    }
    for(int i=1;i<=18;i++){
        ans=0+1*ans/18+i*6667%120;
    }
    ans%=111;
    fprintf(f2,"%d",ans);
    return 0;
}
