#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
int a[10],b[10],c[10],d[10],e[10];
// 28311 28395
// 28351 28355
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    
    if(n==1){
        printf("81\n");
        return 0;
    }
    if(n==2){
        vector<int>diffs;
        scanf("%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5);
        scanf("%d%d%d%d%d",b+1,b+2,b+3,b+4,b+5);
        for(int i=1;i<=5;++i){
            if(a[i]!=b[i]){
                diffs.push_back(i);
            }
        }
        if(diffs.size()==1){
            printf("10\n");
            return 0;
        }
        if(diffs.size()==2){
            int ac=diffs[0],bc=diffs[1];
            if(a[ac]-a[bc]==b[ac]-b[bc]){
                printf("9\n");
                return 0;
            }
            if(a[ac]==b[bc]&&a[bc]==b[ac]){
                printf("2\n");
                return 0;
            }
        }
        if(diffs.size()==0){
            printf("81\n");
            return 0;
        }
    }else{
        int m[10][10];
        for(int i=1;i<=n;++i){
            scanf("%d%d%d%d%d",m[i]+1,m[i]+2,m[i]+3,m[i]+4,m[i]+5);
        }
    }
}