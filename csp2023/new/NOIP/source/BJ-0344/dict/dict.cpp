#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[3002][28];
void read(int x){
    int b[28];
    for(int i=1;i<=26;++i) b[i]=0;
    char c;
    c=getchar();
    while(c<'a'||c>'z') c=getchar();
    while(c>='a'&&c<='z'){
        b[c-'a'+1]++;
        c=getchar();
    }
    for(int i=1;i<=26;++i){
        a[x][i]=a[x][i-1]+b[i];
    }
    return ;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        read(i);
    }
    bool flag;
    for(int i=1;i<=n;++i){
        flag=true;
        for(int j=1;j<=n;++j){
            if(j==i) continue;
            for(int z=1;z<=26;++z){
                if(a[i][z]!=0){
                    if(a[j][26]-a[j][z]!=0) break;
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) printf("1");
        else printf("0");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
